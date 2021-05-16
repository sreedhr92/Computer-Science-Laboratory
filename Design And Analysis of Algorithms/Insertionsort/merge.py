def merge(u,v,low):
    if low == len(v) or low == len(u):
        v.insert(0,u[low-1])
        merge(u,v,low-1)
        print(a)
    if u[low] < v[low] or low > 0:
        merge(u[low+1:],v,low+1)
    elif u[low] > v[low] or low > 0:
        merge(u,v[low+1:],low+1)


u=[1,3,5]
v=[2,4,6]
merge(u,v,0)
print(v)