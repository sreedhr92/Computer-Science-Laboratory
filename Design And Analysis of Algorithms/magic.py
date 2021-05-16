def display(a,n):
    for i in range(n):
        for j in range(n):
            print(a[i][j], end='')
        print()
def magic_square(a, i, j, val, n):
    print("iteration #", val)
    if val == n**2:
        print("val0=", val,"i=",i,"j=",j)
        return a
    elif val == 1:
        print("val1=", val,"i=",i,"j=",j)
        a[i][j]=val
        magic_square(a, i-1, j+1, val+1, n)
    elif i == -1 and j != n:
        print("val2=", val,"i=",i,"j=",j)
        i = n-1
        if a[i][j] != 0:
            print("val21=", val,"i=",i,"j=",j)
            magic_square(a,i+1,j-2,val,n)
        elif a[i][j] == 0:
            a[i][j]=val
            print("val22=", val,"i=",i,"j=",j)
            magic_square(a,i-1,j+1,val+1,n)
    elif i !=- 1 and j == n:
        print("val3=", val,"i=",i,"j=",j)
        j=0
        if a[i][j] != 0:
            print("val31=", val,"i=",i,"j=",j)
            magic_square(a,i+1,j-2,val,n)
        elif a[i][j] == 0:
            a[i][j]=val
            print("val32=", val,"i=",i,"j=",j)
            magic_square(a, i-1, j+1, val+1, n)
    elif i == -1 and j == n:
        print("val4=", val)
        i = 0
        j = n-2
        if a[i][j] != 0:
            print("val41=", val,"i=",i,"j=",j)
            magic_square(a, i + 1, j - 2, val, n)
        elif a[i][j] == 0:
            a[i][j] = val
            print("val42=", val,"i=",i,"j=",j)
            magic_square(a, i - 1, j + 1, val + 1, n)
    else:
        if a[i][j]!=0:
            print("val51=", val, "i=", i, "j=", j)
            magic_square(a, i + 1, j - 2, val, n)
        elif a[i][j] == 0:
            a[i][j] = val
            print("val52=", val,"i=",i,"j=",j)
            magic_square(a, i - 1, j + 1, val + 1, n)



n=int(input("Enter the value of N:"))
a = [[0] * n]*n
magic_square(a,n//2,n-1,1,n)
for i in range(n):
    for j in range(n):
        print(a[i][j],end='')
    print()