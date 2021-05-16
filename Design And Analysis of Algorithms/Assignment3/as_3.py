def cross_sum_array(a,low,mid,high):
    left_sum=-100
    right_sum=-100
    sum=0
    for i in range(mid,low,-1):
        sum = sum+a[i]
        if sum >= left_sum:
            sum = left_sum
    sum=0
    for j in range(mid+1,high+1):
        sum = sum +a[j]
        if sum >= right_sum:
            sum = right_sum
    return left_sum + right_sum
def max(a,b,c):
    if a > b:
        if a > c:
            return a
    elif b > c:
        if b > a:
            return b
    else:
        return c
def max_sub_array(a,low,high):
    print(low, high)
    if low == high:
        return a[low]
    mid=(low+high)//2
    return max(max_sub_array(a,low,mid),max_sub_array(a,mid+1,high),cross_sum_array(a,low,mid,high))

a = [-2, -4, 3, -1, 5, 6, -7, -2, 4, 3, 2]
print(max_sub_array(a,0,len(a)-1))