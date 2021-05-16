def partition(a,b,low,high):
    i=low-1
    pivot=a[high]
    for j in range(low,high):
        if a[j] < pivot:
            i=i+1
            a[j],a[i]=a[i],a[j]
    a[i+1],a[high]=a[high],a[i+1]
    i=low-1
    for j in range(low,high):
        if b[j] < pivot:
            i=i+1
            b[j],b[i]=b[i],b[j]
    b[j+1],b[high]=b[high],b[i+1]
    print(a)
    print(b)

a=[3,1,5,2,4]
b=[2,4,3,1,5]
partition(a,b,0,4)
