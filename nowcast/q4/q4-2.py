import os
from cryptography import x509
from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.primitives.asymmetric import padding

# CA証明書（そのまま貼る）
ca_pem = b"""-----BEGIN CERTIFICATE-----
MIIDWDCCAkCgAwIBAgIUPKP/N0XCMOHsIvP7o8PvUNgTRfwwDQYJKoZIhvcNAQEL
BQAwRDELMAkGA1UEBhMCSlAxDjAMBgNVBAcTBVRva3lvMREwDwYDVQQKEwhGaW5h
dGV4dDESMBAGA1UEAxMJQ3VzdG9tIENBMB4XDTI1MDUyMTA3MjkwMFoXDTMwMDUy
MDA3MjkwMFowRDELMAkGA1UEBhMCSlAxDjAMBgNVBAcTBVRva3lvMREwDwYDVQQK
EwhGaW5hdGV4dDESMBAGA1UEAxMJQ3VzdG9tIENBMIIBIjANBgkqhkiG9w0BAQEF
AAOCAQ8AMIIBCgKCAQEAzRA1ymAZt/7qCst3ZqPAZ0fAfQHknk2yvorTrI6cnanB
9lNPrQN8z/ZMTQHeTasO4Dyz9HvwGxPgrewlnMsE08mKzrX+EUg+PG9LBqg2JjOf
HwwpGxll71Dn/JT90KGzqmW1ozj7KAcvRKRHiAiPfCThi4GZ3E2BftS176F2NpVj
Si3GG0cq5b39EEmQEPOX9Ifxur9PXjBrIJ8VYAXo7TI6mu5iYDgJV/6QKyUDk47S
J3jJdBHp+fghPWHIPNfPAtZuh2qBVBp19gA7K+KzHWf72lLl2oIhyjaRIzuZGoek
LHIksb2OGATjU+PSACergUO0VWglo+lL+Gt740+pXQIDAQABo0IwQDAOBgNVHQ8B
Af8EBAMCAQYwDwYDVR0TAQH/BAUwAwEB/zAdBgNVHQ4EFgQUU3a2C0ojPtRxHnjM
HQSdJzHB8UMwDQYJKoZIhvcNAQELBQADggEBACqNijmdPg2DR/KZD2wljVPYSQJH
bMWeFyjWQxIpJAyCwNoY/Yze/GAGxqrUXPdRqUNULhQz1HLXm9pYMgrk9mXuIgRR
rEpWcupnd+9mDvykNRZmYo7GGaSJSx9KBi6diZAxIxAMtzKRgt3+j4THRormiz0o
x5nA2aYfbZDIJiounYlWVPEQa9TrvODmIy+k8MseXWXnQZo2tfYPXnlHKrlZpUDK
qZq84Nk0f9FPAP3hH8UeYvwufrm63GKfnQNQrhIZvIoKwSEZ3cpNuOSh3nl17JV8
5TDLfm9xnezSBscQav49kZdmkK899TPtobrN0EJXZyfxpQNGm6ZBy1HxiOQ=
-----END CERTIFICATE-----"""

# CA証明書読み込み
ca_cert = x509.load_pem_x509_certificate(ca_pem)
ca_public_key = ca_cert.public_key()

cert_dir = "./quiz_certs"

for filename in os.listdir(cert_dir):
    path = os.path.join(cert_dir, filename)

    try:
        with open(path, "rb") as f:
            cert = x509.load_pem_x509_certificate(f.read())

        # 🔥 署名検証
        ca_public_key.verify(
            cert.signature,
            cert.tbs_certificate_bytes,
            padding.PKCS1v15(),
            cert.signature_hash_algorithm,
        )

        print("VALID:", filename)

    except Exception:
        continue