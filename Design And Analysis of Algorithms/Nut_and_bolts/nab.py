def nut_and_bolts(a,b):
    n=len(a)
    for i in range(len(a)):
        for j in range(len(b)):
            if a[i] == b[j]:
                print("The nut",i+1,"has its bolt in",j+1,"position")

a=[1,2,3,4,5]
b=[4,2,3,1,5]
nut_and_bolts(a,b)