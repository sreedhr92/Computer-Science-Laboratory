def fast_power(x,n):
    if n == 0:
        return 1
    elif n % 2!=0:
        return x*fast_power(x,n-1)
    elif n % 2==0:
        return fast_power(x,n/2)*fast_power(x,n/2)

x = int(input("Enter the base:"))
y = int(input("Enter the exponent:"))
print("The value of",x,"to the power of",y,"=",fast_power(x,y))