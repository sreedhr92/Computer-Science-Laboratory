
def read_array(a):
    n = int(input("Enter the length :"))
    for i in range(0, n):
        element = int(input("Enter element :"))
        a.append(element)
    return n

def ordered_insert(n,a,count):
    if len(a) == 0:
        a.append(n)
    elif count == len(a):
        a.append(n)
    elif a[count] < n:
        ordered_insert(n, a, count + 1)
    elif a[count] >= n:
        a.insert(count, n)

def ordered_merge(u,v,count):
    if count < len(u):
        ordered_insert(u[count],v,0)
        ordered_merge(u,v,count+1)

u=[15,40,45]
v=[5,10,20,35,50]
#read_array(u)
#read_array(v)
ordered_merge(u,v,0)
print(v)
