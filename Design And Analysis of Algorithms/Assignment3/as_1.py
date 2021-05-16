def sum(a):
    sum = 0
    for i in a:
        sum += i
    if sum < 0:
        sum = 0
    return sum


def max(a):
    max = a[0]
    for i in a:
        if max < i:
            max = i
    return max


def maximum_subarray_sum(a):
    b = []
    r = []
    for i in range(len(a)):
        for j in range(i, len(a)):
            if i == j:
                continue
            b.append(sum(a[i:j]))
            r.append(a[i:j])
    k = b.index(max(b))
    start = a.index(r[k][0])
    end = a.index(r[k][len(r[k]) - 1])
    print("The Maximum subarray is A[", start, ":", end + 1, "]")
    print("The Maximum Subarray is :", r[k])
    print("The Maximum Subarray sum is", max(b))


a = [2, -4, 3, -1, 5, 6, -7, -2, 4, 3, 2]
maximum_subarray_sum(a)







