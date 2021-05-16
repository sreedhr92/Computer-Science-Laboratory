def out_of_order(a):
    n=len(a)
    count=0
    for i in range(0,len(a)):
        for j in range(0,len(a)):
            if a[i] > a[j] and i<j:
                count = count + 1
                print("(",a[i],a[j],")")
    print("The maximum out of order pairs are",count)

a=[5,4,3,2,1]
#a=[1,2,3,4,5]
out_of_order(a)