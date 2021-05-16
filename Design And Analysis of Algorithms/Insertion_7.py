def read(a):
    n = int(input("Enter no of terms :"))
    for i in range(1, n+1):
        element = int(input("Enter element :"))
        a[2**i] = element
    return n


def sort(a,n):
    for i in range(1,n+1):
        if i+1 < n :
            if a[2**i] < a[2**(i+1)]:
                break
            else:
                a[2**i],a[2**(i+1)]=a[2**(i+1)],a[2**i]
    print(a)




a = dict()
n = read(a)
print("Dict :", a)
sort(a,n)
