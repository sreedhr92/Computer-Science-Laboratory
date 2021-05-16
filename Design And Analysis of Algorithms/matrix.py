class error(Exception):
    pass
class matrix_multiplicationerror(error):
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
    print(c)

def matrix_multi_comp(a,b):
    c = [[sum(x*y for x,y in zip(i,j)) for j in zip(*b)] for i in a]
    print(c)


print("\n----------MATRIX MULTIPLICATION--------")
print("FIRST MATRIX")
m1=int(input("Enter the value of m:"))
n1=int(input("Enter the value of n:"))
a=[[0 for j in range(0,n1)] for i in range(0,m1)]

print("SECOND MATRIX")
m2=int(input("Enter the value of m:"))
n2=int(input("Enter the value of n:"))
b=[[0 for j in range(0,n2)] for i in range(0,m2)]

try:
    if m2 != n1:
        raise matrix_multiplicationerror
    print("Enter the value for matrix A")
    read_matrix(a, m1, n1)
    print_matrix(a, m1, n1)
    print("Enter the value for matrix B")
    read_matrix(b, m2, n2)
    print_matrix(b, m2, n2)
    matrix_multiplication(a, b, m1, n1, m2, n2)
    matrix_multi_comp(a,b)

except matrix_multiplicationerror:
    print("Given matrix's dimentions are not satisfied the conditions for multiplication")



