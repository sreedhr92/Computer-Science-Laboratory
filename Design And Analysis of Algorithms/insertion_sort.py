def print_array(a, low, high):
    print("The Subarray of a", a[low:high])


def read_array(a):
    n = int(input("Enter the length :"))
    for i in range(0, n):
        element = int(input("Enter element :"))
        a.append(element)
    return n

def order_insert_1(a,n):
    count =0
    for i in range(0, n):
        if a[n-1-count] < a[n-i-1] :
            a[n-1-count],a[n-i-1] = a[n-i-1],a[n-1-count]
            count = count + 1
    print("The Ordered array  :", a)

def order_insert_2(a):
    n=len(a)
    count =0
    for i in range(0, n):
        if a[n-1-count] < a[n-i-1] :
            a[n-1-count],a[n-i-1] = a[n-i-1],a[n-1-count]
            count = count + 1
    print("The Ordered array  :", a)

def order_insert_recursion_3(a,n,i):
    if a[n-1] < a[n-i] and n > 1:
        a[n-1],a[n-i] = a[n-i],a[n-1]
        order_insert_recursion(a,n-1,i)
    elif a[n-1] > a[n-i] or n == 1:
        print("The Ordered array  :",a)

def order_insert_4(a,n):
    element = a[n-1]
    for i in range(0, n):
        if element < a[i] :
            break
    while n > i:
        n = n - 1
        a[n] = a[n-1]
    a[i] = element
    print(a)

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



def order_insert_5(a,n):
    element = a[n-1]
    for i in range(0, n):
        if element < a[i] :
            break
    while n > i:
        n = n - 1
        a[n] = a[n-1]
    a[i] = element
    print(a)

def sorting_problem_2(a,n):
    b=a[0:n-1]
    selection_sort(b)
    b.append(a[n-1])
    order_insert(b,n)



def insertion_sort(a):
    for i in range(1, len(a)):
        key = a[i]
        j = i - 1
        while j <= 0 and key < a[j]:
            a[j+1] = a[j]
            j = j - 1
        a[j+1] = key
    print(a)

def order_insert(a,n):
    element = a[0]
    for i in range(1, n):
        if element < a[i] :
            pos=i
            break
    i = 0
    while i < pos :
        a[i] = a[i+1]
        i = i+1
    a[pos-1] = element
    print(a)


def order_insert_recursion(a,n,i):
    if a[n-1] < a[n-i] and n > 1:
        a[n-1],a[n-i] = a[n-i],a[n-1]
        order_insert_recursion(a,n-1,i)
    elif a[n-1] > a[n-i] or n == 1:
       print("The Ordered array  :",a)


def sorting_problem(a,n):
    b=a[1:n]
    selection_sort(b)
    b.insert(0,a[0])
    order_insert(b,n)



a = []
read_array(a)
n = len(a)
print("The Original Array :", a)
#insertion_sort(a)
#order_insert(a,n)
#order_insert_recursion(a,n,2)
sorting_problem(a,n)



