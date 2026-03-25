# 問題　

### 問題1-1 Container - コンテナの実行 (4点)

dockerで、
```
$ docker run --rm stajima/skill-test:v1_q1-1
WARNING: The requested image's platform (linux/amd64) does not match the detected host platform (linux/arm64/v8) and no specific platform was requested
f1nat3xthd{f778f18c-ebe3-4678-8aa2-853d15b379b6}
(base)
```

M1マックで実行アーキテクチャが異なるのでwarning出てます。（フラグつけて消せるような）

### 問題1-2 Container - コンテナ上の任意のコマンドの実行 (8点)

解法1: dockerに入って中身を直接確認:

```
$ docker run --rm -it --entrypoint sh stajima/skill-test:v1_q1-2
WARNING: The requested image's platform (linux/amd64) does not match the detected host platform (linux/arm64/v8) and no specific platform was requested
/ # ls
bin       dev       etc       flag.txt  home      lib       media     mnt       opt       proc      root      run       sbin      srv       sys       tmp       usr       var
/ # cat flag.txt
f1nat3xthd{b82df727-593a-46cc-9949-dabe8b8c10a7}
/ #
```

解法2: 起動シェルを無効化してentrypointを上書きする。

```
$ docker run --rm --entrypoint cat stajima/skill-test:v1_q1-2 /flag.txt
WARNING: The requested image's platform (linux/amd64) does not match the detected host platform (linux/arm64/v8) and no specific platform was requested
f1nat3xthd{b82df727-593a-46cc-9949-dabe8b8c10a7}
```

### 問題1-3 Container - コンテナ上のファイルの取得 (12点)

シェルがないのでローカルにコピーする

```
$ docker create --name tmp stajima/skill-test:v1_q1-3
WARNING: The requested image's platform (linux/amd64) does not match the detected host platform (linux/arm64/v8) and no specific platform was requested
2f6dad47b7b0d11f594df9b8e29470df42dea0d29f374e8d38e3d52281400c29

$ docker cp tmp:/flag.txt .
Successfully copied 2.05kB to /Users/ukohank517/workspace/coder_history/nowcast/.

$ cat flag.txt
f1nat3xthd{7d374833-4dcb-4a66-9aa7-8c3a7ff737de}
```

### 問題2-1 JWT - Payloadのからの値の取得 (4点)

(jwt.io頼り)

```
{
  "flag": "f1nat3xthd{8011814b-470c-4f3c-aa6e-215aa8db9924}"
}
```

### 問題2-2 JWT - 公開鍵による検証 (8点)

```
$ python3 q2-2.py
VALID: {'flag': 'f1nat3xthd{f53c73d9-278e-4b2e-af2e-26b10eed5224}'}
```

### 問題2-3 JWT - RSAの公開鍵/秘密鍵の性質 (12点)

ヘッダークレームより、全てPS256アルゴらしい

```
$ python3 q2-3.py
VALID JWT FOUND:
{'flag': 'f1nat3xthd{0ad9dc6b-9e07-4e0f-b142-ff170e6d2ac1}'}
(base)
```

### 問題3-1 HTTP - POSTリクエストの送信 (4点)


```
$ curl -X POST https://skill-test.st8.workers.dev/v1/q3-1/login -H "Content-Type: application/json" -d '{"username":"admin","password":"supersecretpassword"}'
{"token": "d97329d6c03c90a0c82bfec27e9427e796324861", "flag": "f1nat3xthd{8727d491-8190-4a3a-a937-d94a71d89c6c}"}(base)
```

### 問題3-2 HTTP - APIサーバーの構築(ログイン) (8点)

動作確認:
```
$ curl -X PUT localhost:8000/login -H "Content-Type: application/json" -d '{"username":"admin","password":"thisispassword"}'
$ curl -X PUT https://nowcast.aikkou.com/login -H "Content-Type: application/json" -d '{"username":"admin","password":"thisispassword"}'
{"token":"8368890114e5e84ade36e721e8cf29b1207004d5"}
```

実行:
```
$ curl -X POST https://skill-test.st8.workers.dev/v1/q3-2/agent   -H "Content-Type: application/json"   -d '{"target":"https://nowcast.aikkou.com/"}'
```

ログは：
```
app-1  | [2026-03-25 05:04:17,135] INFO in app: FLAG: f1nat3xthd{f1096ca4-f298-464f-97e0-feedbe237f78}
```

### 問題3-3 HTTP - APIサーバーの構築(ローソク足) (16点)

実行:
```
$ curl -X POST https://skill-test.st8.workers.dev/v1/q3-3/agent   -H "Content-Type: application/json"   -d '{"target":"https://nowcast.aikkou.com/"}'
```

ログは:
```
app-1  | 172.20.0.1 - - [25/Mar/2026 07:42:37] "GET /candle?code=SPCR&year=2021&month=12&day=22&hour=10 HTTP/1.1" 200 -
app-1  | 172.20.0.1 - - [25/Mar/2026 07:42:37] "GET /candle?code=FTHD&year=2021&month=12&day=23&hour=10 HTTP/1.1" 200 -
app-1  | 172.20.0.1 - - [25/Mar/2026 07:42:37] "GET /candle?code=TEQA&year=2021&month=12&day=27&hour=11 HTTP/1.1" 200 -
app-1  | [2026-03-25 07:42:37,700] DEBUG in app: flag called
app-1  | [2026-03-25 07:42:37,701] DEBUG in app: {'flag': 'f1nat3xthd{02f401fd-140e-4fe5-a7f5-29ff996139fc}'}
app-1  | [2026-03-25 07:42:37,701] INFO in app: FLAG: f1nat3xthd{02f401fd-140e-4fe5-a7f5-29ff996139fc}
```

### 問題4-1 Network - DKIM (8点)

公開鍵DNS名の形式は: `<selector>._domainkey.<domain>`

```
$ dig @8.8.8.8 TXT dk4419._domainkey.st.fntxt.co

; <<>> DiG 9.10.6 <<>> @8.8.8.8 TXT dk4419._domainkey.st.fntxt.co
; (1 server found)
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 49866
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 512
;; QUESTION SECTION:
;dk4419._domainkey.st.fntxt.co.	IN	TXT

;; ANSWER SECTION:
dk4419._domainkey.st.fntxt.co. 300 IN	TXT	"v=DKIM1;k=rsa;p=f1nat3xthd{eb690513-0b2b-45a4-b6a3-591c56ac1a91}"

;; Query time: 28 msec
;; SERVER: 8.8.8.8#53(8.8.8.8)
;; WHEN: Wed Mar 25 11:00:29 JST 2026
;; MSG SIZE  rcvd: 135
```

### 問題4-2 Network - X.509 (8点)

```
$ python3 q4-2.py
VALID: f1nat3xthd{5d194f57-92c5-4b57-9814-2879a1584112}.pem
```

### 問題4-3 Network - MySQL (8点)

```
$ tcpdump -r mysql.pcap -A > mysql.query # hex形式のselect文がある

$ echo "626F6775735F666C61677B61353335616335372D356639322D346539392D623636302D3736393239653934636563387D66316E617433787468647B66623439613661372D646132632D346139342D616561352D3936373032333061363063337D74686973697366616B657B36383566386561362D386532312D343133352D396164652D3039393338373039326263377D69676E6F7265746869737B36663165613432302D613961332D343666622D383366392D3238343935336563373465317D" | xxd -r -p
bogus_flag{a535ac57-5f92-4e99-b660-76929e94cec8}f1nat3xthd{fb49a6a7-da2c-4a94-aea5-9670230a60c3}thisisfake{685f8ea6-8e21-4135-9ade-099387092bc7}ignorethis{6f1ea420-a9a3-46fb-83f9-284953ec74e1}(base)
```