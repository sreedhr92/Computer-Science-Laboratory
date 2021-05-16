def magic_square(a,i,j,val,n):
    if val == n**2:
        return a
    else:
        if a[i][j] == 0:
            if val == 1:
                a[i][j] = val
                print("val=", val, "i=", i, "j=", j)
                magic_square(a, i - 1, j + 1, val + 1, n)
            elif i == -1 and j != n:
                i=n-1
                magic_square(a, i, j, val, n)
            elif i !=- 1 and j == n:
                j=0
                magic_square(a, i, j, val, n)
            elif i == -1 and j == n:
                i=i+1
                j=j-2
                magic_square(a, i, j, val, n)
            else:
                a[i][j]=val
                print("val0=", val, "i=", i, "j=", j)
                magic_square(a, i - 1, j + 1, val + 1, n)
        else:
            i=i+1
            j=j-2
            print("val1=", val, "i=", i, "j=", j)
            magic_square(a, i, j, val, n)

n=int(input("Enter the value of N:"))
a = [[0] * n]*n
magic_square(a,n//2,n-1,1,n)
for i in range(n):
    for j in range(n):
        print(a[i][j],end='')
    print()


