def partition(a,b,low_a,high_a,low_b,high_b):
    i=low_a-1
    pivot=a[high_a]
    index=[]
    for j in range(low_a,high_a):
        if a[j] < pivot:
            i=i+1
            a[j],a[i]=a[i],a[j]
    a[i+1],a[high_a]=a[high_a],a[i+1]
    index.append(i+1)
    i=low_b-1
    for j in range(low_b,high_b):
        if b[j] < pivot:
            i=i+1
            b[j],b[i]=b[i],b[j]
    b[j+1],b[high_b]=b[high_b],b[i+1]
    index.append(i+1)
    return index

def quicksort(a,b,low_a,high_a,low_b,high_b):
    pi=[]
    if low_a < high_b or low_b < high_b:
        pi=partition(a,b,low_a,high_a,low_b,high_b)
        quicksort(a,b,low_a,pi[0]-1,low_b,pi[1]-1)
        quicksort(a,b,pi[0]+1,high_b,pi[1]+1,high_b)


a=[3,1,5,2,4]
b=[2,4,3,1,5]
quicksort(a,b,0,4,0,4)
print(a)
print(b)


