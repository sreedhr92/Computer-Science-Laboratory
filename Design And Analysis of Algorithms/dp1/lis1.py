maximum =1
max_lis=[]
def LengthES(a,n):
    global maximum
    if n==1:
        return 1
    end=1
    for i in range(1,n):
        res = LengthES(a,i)
        if a[i-1] < a[n-1] and res +1 > end:
            end = res +1
        max_lis.append(end)
    maximum = max(end,maximum)
    return end


a=[5,2,8,6,3,6,9,7]
print("The length Longest increasing subsequnece is",LengthES(a,len(a)))

