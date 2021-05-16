def prefix_sum(a):
    prefix = []
    max = -100
    sum = 0
    for i in range(len(a)):
        prefix.append(0)
        sum = sum + a[i]
        prefix[i] = sum
    for i in range(len(a)):
        for j in range(i, len(a)):
            sum = prefix[j] - prefix[i]
            if sum > max:
                start = i
                max = sum
                end = j
    print(max, start + 1, end + 1)

#Another approach

def prefix_sum_add(a):
    max=-100
    for i in range(len(a)):
        sum=0
        for j in range(i,len(a)):
            sum=sum+a[j]
            if sum > max:
                max=sum
                start=i
                end=j
    print(max, start, end + 1)

a = [-2, -4, 3, -1, 5, 6, -7, -2, 4, 3, 2]
prefix_sum(a)
prefix_sum_add(a)

