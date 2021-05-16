def power(x,n):
    if n == 0:
        return 1
    else:
        return x*power(x,n-1)

x = int(input("Enter the base:"))
y = int(input("Enter the exponent:"))
print("The value of",x,"to the power of",y,"=",power(x,y))