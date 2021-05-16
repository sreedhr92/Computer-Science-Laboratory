def merge(u,v):
    i=0
    while 1:
        if i == len(u) or len(v) == 0:
            u.extend(v)
            return u
        elif u[i] < v[0]:
            i = i+1
        elif u[i] > v[0]:
            u.insert(i,v[0])
            v.remove(v[0])


def merge_sort(a):
    if len(a) == 0 or len(a) == 1:
        return a
    m=(len(a)//2)
    sorted_l1=merge_sort(a[0:m])
    sorted_l2=merge_sort(a[m:len(a)])
    return merge(sorted_l1,sorted_l2)

u=[2,3,8,9,1,4,5,7]
print(merge_sort(u))

