def lcs(a,b):
    lcs = [[None]*(len(b)+1) for i in range(len(a)+1)]
    for i in range(0,len(a)+1):
        for j in range(0,len(b)+1):
            if i==0 or j==0:
                lcs[i][j]=0
            elif a[i-1]==b[j-1]:
               lcs[i][j]= 1+lcs[i-1][j-1]
            else:
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1])
    for i in range(0,len(a)+1):
        for j in range(0,len(b)+1):
            print(lcs[i][j],end="")
        print()
    print("The length of the LCS",lcs[i][j])


a=[5,3,2,7,8,1,6]
b=[7,1,6,8,2,5,9]
lcs(a,b)