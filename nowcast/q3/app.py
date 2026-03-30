from flask import Flask, request, jsonify
import pandas as pd
import hashlib
import logging

def build_candles():
    df = pd.read_csv("order_books.csv")

    # JSTがあると処理落ちるので
    df["time"] = df["time"].str.replace(" JST", "", regex=False)
    df["time"] = pd.to_datetime(df["time"], format="%Y-%m-%d %H:%M:%S %z", errors="coerce")

    # 時間足キーを作る
    df["year"] = df["time"].dt.year
    df["month"] = df["time"].dt.month
    df["day"] = df["time"].dt.day
    df["hour"] = df["time"].dt.hour

    df = df.sort_values("time")

    candles = {}

    grouped = df.groupby(["code", "year", "month", "day", "hour"])

    for key, group in grouped:
        code, y, m, d, h = key

        candles[(code, y, m, d, h)] = {
            "open": int(group.iloc[0]["price"]),
            "high": int(group["price"].max()),
            "low": int(group["price"].min()),
            "close": int(group.iloc[-1]["price"]),
        }

    return candles

################################################
app = Flask(__name__)
app.logger.setLevel(logging.DEBUG)
CANDLES = build_candles()
app.logger.info(f"Loaded candles: {len(CANDLES)}")


@app.route("/login", methods=["PUT"])
def login():
    data = request.get_json()
    app.logger.info("login called")
    app.logger.debug(data)
    username = data.get("username", "")
    password = data.get("password", "")

    token = hashlib.sha1((username + password).encode()).hexdigest()
    res = jsonify({"token": token})
    app.logger.debug("return:")
    app.logger.debug(res)
    return res

@app.route("/candle", methods=["GET"])
def candle():
    code = request.args.get("code")
    year = int(request.args.get("year"))
    month = int(request.args.get("month"))
    day = int(request.args.get("day"))
    hour = int(request.args.get("hour"))

    key = (code, year, month, day, hour)

    result = CANDLES.get(key)
    if not result:
        return jsonify({"error": "not found"}), 404

    return jsonify(result)

@app.route("/flag", methods=["PUT"])
def flag():
    data = request.get_json()
    app.logger.debug("flag called")
    app.logger.debug(data)
    app.logger.info(f"FLAG: {data.get('flag')}")
    return "", 200

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=8000)
