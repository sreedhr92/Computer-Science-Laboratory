def read(a):
    n = int(input("Enter the length :"))
    for i in range(0, n):
        element = int(input("Enter element :"))
        a.append(element)
    return n
def get_pivot(a,low,high):
    mid = low + high // 2
    pivot = high
    if a[low] < a[mid]:
        if a[mid] < a[high]:
            pivot = mid
    elif a[low] < a[high]:
            pivot = low
    print(pivot)
    return pivot

def partition(a,low,high):
    pivot = get_pivot(a,low,high)
    pivot_value = a[pivot]
    a[low],a[pivot] = a[pivot],a[low]
    border =0
    for i in range(low,high):
        if a[i] < pivot_value:
            border = border +1
            a[i],a[border]=a[border],a[i]
    a[low],a[border]=a[border],a[low]
    return border

def quick_sort(a,low,high):
    if low < high:
        p = partition(a,low,high)
        quick_sort(a,low,p-1)
        quick_sort(a,p+1,high)


a=[5,7,4,8,3,99,4,2]
low =0
high = len(a)-1
quick_sort(a,low,high)
print(a)