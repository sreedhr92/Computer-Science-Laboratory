def matrix_multiplication(a,b):
    c = [[0 for i in range(len(b[0]))] for j in range(len(a))]
    for i in range(len(a)):
        for j in range(len(b[0])):
            for k in range(len(b)):
                c[i][j]+=a[i][k]*b[k][j]
    return c

def print_matrix(a,m,n):
    for i in range(m):
        for j in range(n):
            print(a[i][j],end =" ")
        print("\n")

def fast_power_mat(x,n):
    result =[[1 if i==j else 0 for i in range(len(x))]for j in range(len(x))]
    if n ==0:
        return result
    if n ==1:
        return x
    if n ==2:
        return matrix_multiplication(x,x)
    if n > 2:
        for i in range(0,n):
            if n % 2 != 0:
                result = matrix_multiplication(result,x)
            else :
                result = matrix_multiplication(x,x)
                n=n//2
        return result

def fibo_mat(n):
    F=[[0,1],[1,1]]
    f=[[0],[1]]
    power = fast_power_mat(F,n)
    result = matrix_multiplication(power,f)
    print("The fibonacci is",result[0][0])

num = int(input("Enter the number :"))
fibo_mat(num)

