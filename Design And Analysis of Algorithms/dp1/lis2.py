def lis(a,n):
    lis=[]
    lis.append(1)
    for i in range(1,len(a)):
        lis.append(1)
        for j in range(0,i):
            if a[i] > a[j] and lis[i] <= lis[j]:
                lis[i]=lis[j]+1
    print(lis)
    return lis[n-1]

a=[5,2,8,6,3,6,9,7]
print("The length Longest increasing subsequnece is",lis(a,len(a)))

