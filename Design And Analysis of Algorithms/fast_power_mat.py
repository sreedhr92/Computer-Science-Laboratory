class error(Exception):
    pass

class power_error(error):
    pass
def print_matrix(a,m,n):
    for i in range(m):
        for j in range(n):
            print(a[i][j],end =" ")
        print("\n")


def read_matrix(a,m,n):
    for i in range(m):
        for j in range(n):
            a[i][j]=0
            a[i][j]=int(input("Enter the element :"))

def matrix_multiplication(a,b):
    c = [[0 for i in range(len(b[0]))] for j in range(len(a))]
    for i in range(len(a)):
        for j in range(len(b[0])):
            for k in range(len(b)):
                c[i][j]+=a[i][k]*b[k][j]
    return c
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
                n=n/2
        return result

m1=int(input("Enter the value of m:"))
n1=int(input("Enter the value of n:"))
n=int(input("Enter the exponent :"))
a=[[0 for j in range(0,n1)] for i in range(0,m1)]
try:
    if m1 != n1:
        raise power_error
    print("Enter the value for matrix A")
    read_matrix(a, m1, n1)
    print_matrix(a, m1, n1)
    print("The power of a matrix :")
    print_matrix(fast_power_mat(a,n),m1,n1)

except power_error:
    print("Power of a matrix can be computed only for the square matrix")
