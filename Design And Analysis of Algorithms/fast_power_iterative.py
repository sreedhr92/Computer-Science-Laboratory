def fast_power_iterative(x,n):
    result =1
    for i in range(0,n):
        if n % 2 != 0:
            result =result*x
        else :
            result = x*x
            n=n/2
    return result


x = int(input("Enter the base:"))
y = int(input("Enter the exponent:"))
print("The value of",x,"to the power of",y,"=",fast_power_iterative(x,y))
