import jwt
from jwt import InvalidSignatureError
from cryptography.hazmat.primitives import serialization

ssh_pubkey = b"""ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQC6eLDuYM4TKIKRvc5MSCPGiMSi7PYmbPMAkX6QbNc3PZtlvDjIL9ZYVsrVgw7FIvzpwzouqTV6K401AcRh7j24AXxNaH3OeC4uyx8u1u0mfxUB6DB6FjfjZsD46uqQvj6/GwZGLPkZ8Gyduqbi776Pb9LuBEyZo6wIGjQsHbELJmou4e2SeBEU6yF6MiFQ+DGK2xl6vikjslYzwXSCj7pD2hoVAc5nS5wjU5cf6rerDBcYmvjkN7qvBM+JkSUoWRjLbbyqoJJIHRQHQZay6HFOc88wCY+KHwnPg7+QWTNMpQgFDBQ0Rran1Mm/LH6HK7f0mT8Dl99zCBI/6BMKyVA5"""

# ssh形式をpem形式に戻す(調べた)
public_key = serialization.load_ssh_public_key(ssh_pubkey)

with open("jwts.rand.txt") as f:
    for line in f:
        token = line.strip()
        try:
            decoded = jwt.decode(token, public_key, algorithms=["RS256"])
            print("VALID:", decoded)
        except InvalidSignatureError:
            continue
        except Exception:
            continue