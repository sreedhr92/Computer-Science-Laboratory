#using iterative function
def tracelis_i(lis,a):
    b=[]
    for i in range(len(lis)-1,-1,-1):
        if i == len(lis)-1:
            b.insert(0,a[i])
            value=lis[i]
            continue
        if lis[i] == value-1:
            b.insert(0,a[i])
            value = lis[i]
    print(b)

c=[]
value_r=0
#Using recursive function
def tracelis_r(lis,a,i):
    global value_r
    if i==0:
        return
    if i==len(lis)-1:
        c.insert(0,a[i])
        value_r=lis[i]
        tracelis_r(lis,a,i-1)
    if lis[i] == value_r-1:
        c.insert(0,a[i])
        value_r=lis[i]
        tracelis_r(lis, a, i - 1)
    else:
        tracelis_r(lis, a, i - 1)


def lis(a,n):
    lis=[]
    lis.append(1)
    for i in range(1,len(a)):
        lis.append(1)
        for j in range(0,i):
            if a[i] > a[j] and lis[i] <= lis[j]:
                lis[i]=lis[j]+1
    print(lis)
    tracelis_i(lis,a)
    tracelis_r(lis,a,len(lis)-1)
    return lis[n-1]

a=[5,2,8,6,3,6,9,7]
print("The length Longest increasing subsequnece is",lis(a,len(a)))
print(c)
#Output
'''[1, 1, 2, 2, 2, 3, 4, 4]
[2, 3, 6, 7]
The length Longest increasing subsequnece is 4
[2, 3, 6, 7]'''