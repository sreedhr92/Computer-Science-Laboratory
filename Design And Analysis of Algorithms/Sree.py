
s=input("Enter the string")
a=input("Enter the sub string")
count=0
for i in range(len(s)):
    if(s[i:i+len(a)]==a):
        count+=1
print(count)

