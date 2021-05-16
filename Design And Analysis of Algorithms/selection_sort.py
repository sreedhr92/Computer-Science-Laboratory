def print_array(a, low, high):
    print("The Subarray of a", a[low:high])


def read_array(a):
    n = int(input("Enter the length :"))
    for i in range(0, n):
        element = int(input("Enter element :"))
        a.append(element)
    return n


def minimum(a, low, high):
    m = 100
    for i in a[low:high]:
        if i < m:
            m = i
    return a.index(m)


def selection_sort(a):
    for i in range(len(a)):
        m = minimum(a, i, len(a))
        a[i], a[m] = a[m], a[i]
    print(a)


a = []
read_array(a)
print(a)
selection_sort(a)








