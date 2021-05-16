def read_array(a):
    n = int(input("Enter the length :"))
    for i in range(0, n):
        element = int(input("Enter element :"))
        a.append(element)
    return n

def ordered_insert(n,a,count):
    if len(a)==0:
        a.append(n)
    elif count==len(a):
        a.append(n)
    elif a[count] < n:
        ordered_insert(n,a,count+1)
    elif a[count] >= n:
        a.insert(count,n)

a = []
read_array(a)
n = int(input("Enter the numberto be inserted:"))
print("The Original Array :", a)
ordered_insert(n,a,0)
print("After the insertion :")
print(a)

