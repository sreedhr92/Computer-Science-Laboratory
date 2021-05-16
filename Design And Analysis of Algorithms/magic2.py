def display(a,n):
    for i in range(n):
        for j in range(n):
            print(a[i][j], end='  ')
        print()
c=0
n=int(input("Enter the value of N:"))
a = [[0 for i in range(n)]for j in range(n)]
def magic_square(i,j,val,n):
    global c
    c=val
    if c > n**2:
        return
    elif val == 1:
        a[i][j] = val
        magic_square( i - 1, j + 1, val + 1, n)
        return
    elif i == -1 and j != n:
        i = n-1
        magic_square( i, j, val, n)
        return
    elif i !=- 1 and j == n:
        j = 0
        magic_square(i, j, val, n)
        return
    elif i == -1 and j == n:
        i = 0
        j = n - 2
        magic_square( i, j, val, n)
        return
    else:
        if a[i][j] == 0:
            a[i][j] = val
            magic_square( i - 1, j + 1, val + 1, n)
            return
        else:
            i=i+1
            j=j-2
            magic_square( i, j, val, n)
            return

magic_square(n//2,n-1,1,n)
display(a,n)
