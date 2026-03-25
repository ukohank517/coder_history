from flask import Flask, request, jsonify
import hashlib
import logging

app = Flask(__name__)
app.logger.setLevel(logging.DEBUG)

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

@app.route("/flag", methods=["PUT"])
def flag():
    data = request.get_json()
    app.logger.debug("flag called")
    app.logger.debug(data)
    app.logger.info(f"FLAG: {data.get('flag')}")
    return "", 200

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=8000)
