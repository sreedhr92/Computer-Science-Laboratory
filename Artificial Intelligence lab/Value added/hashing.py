import hashlib

i=0
while(1):
    s = "Mallory Rules CryptoLand"
    s1 = s + str(i)
    s2 = bytes(s1,'utf-8')
    s3 = hashlib.sha256(s2).hexdigest()
    if s3[0:4] == '0000':
        print(i)
        print(s3)
        break
    i = i + 1

'''Output
C:\Users\sreed\anaconda3\python.exe "F:/Academics/SSN/5th Sem/AI lab/Value added/hashing.py"
74164
0000611c6faf461fe5e32657fd14560036829133ac09b0275cd2c97dda38381d
'''