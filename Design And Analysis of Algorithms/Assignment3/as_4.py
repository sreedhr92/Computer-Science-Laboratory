def max_subarray_sum_linear(a):
    suffix_max=[]
    subarray_max=[]
    suffix_max.append(a[0])
    for i in range(1,len(a)):
        suffix_max.append(max(suffix_max[i-1],a[i-1],0))
    print(suffix_max)
    subarray_max.append(0)
    for i in range(1,len(a)):
        subarray_max.append(max(subarray_max[i-1],suffix_max[i]))
    print(subarray_max)


a = [-2, -4, 3, -1, 5, 6, -7, -2, 4, 3, 2]
max_subarray_sum_linear(a)