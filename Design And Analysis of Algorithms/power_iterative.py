def power_iterative(x,n):
    result =1
    for i in range(0,n):
        result = x*result
    return result


x = int(input("Enter the base:"))
y = int(input("Enter the exponent:"))
print("The value of",x,"to the power of",y,"=",power_iterative(x,y))