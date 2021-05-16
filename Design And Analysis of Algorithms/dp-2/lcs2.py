def trace_lcs(a,b,lcs):
    lcs_value=[]
    i=len(a)
    j=len(b)
    while i > 0 and j > 0:
        if a[i-1] == b[j-1]:
            lcs_value.insert(0,a[i-1])
            i-=1
            j-=1
        elif lcs[i-1][j] > lcs[i][j-1]:
            i-=1
        else:
            j-=1
    print(lcs_value)

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

    trace_lcs(a,b,lcs)


a=[5,2,9,7,0,1]
b=[5,1,0,7,2,9]
lcs(a,b)

'''output:
C:\Users\sreed\PycharmProjects\DAA\venv\Scripts\python.exe C:/Users/sreed/PycharmProjects/DAA/dp-2/lcs2.py
0000000
0111111
0111122
0111123
0111223
0112223
0122223
The length of the LCS 3
[5, 2, 9]

'''