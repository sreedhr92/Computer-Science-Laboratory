table = {}


def fibi(n):
    f1 = 0
    f2 = 1
    for i in range(1, n):
        f3 = f1+f2
        f1 = f2
        f2 = f3
    return f2


def fibr(n):
    if n <= 1:
        return n
    else:
        return fibr(n-1)+fibr(n-2)


def fibm(n):
    for i in range(0, n):
        num = int(input("Enter the number :"))
        if num in table:
            print("Already in table ", num, " fibonacci=", table[num])
            n = n + 1
        else:
            table[num] = fibi(num)
    print(table)
    table.clear()


while 1:
    print("\n1.Fibonacci using Iterative function")
    print("2.Fibonacci using recursive function\n3.Fibonacci memoized function")
    print("4.Exit")
    a = int(input("Enter choice :"))
    if a == 1:
        num = int(input("Enter the number :"))
        print("The fibonacci is ", fibi(num))
    elif a == 2:
        num = int(input("Enter the number :"))
        print("The fibonacci is ", fibr(num))
    elif a == 3:
        num = int(input("Enter the table length :"))
        fibm(num)
    elif a == 4:
        break
    else:
        print("Invalid Input")
print("Done Exiting...")

