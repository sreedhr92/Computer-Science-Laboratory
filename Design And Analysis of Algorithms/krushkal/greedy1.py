from collections import defaultdict
vertices=[]
class Graph:
    def __init__(self,no_of_vertices):
        self.n=no_of_vertices
        self.graph=[]
    def insert_edge(self,x,y,w):
        self.graph.append([x,y,w])
    def find(self,parent,a):
        global vertices
        if parent[vertices.index(a)] < 0:
            return a
        return self.find(parent,parent[vertices.index(a)])
    def union(self,parent,x,y):
        parent_x=self.find(parent,x)
        parent_y=self.find(parent,y)
        if parent[vertices.index(parent_x)] > parent[vertices.index(parent_y)]:
            parent[vertices.index(parent_x)] = parent_y
        elif parent[vertices.index(parent_x)] < parent[vertices.index(parent_y)]:
            parent[vertices.index(parent_y)] = parent_x
        else:
            parent[vertices.index(parent_y)]=parent_x
            parent[vertices.index(parent_x)]-=1

    def Minimum_spaning_tree(self):
        mst=[]
        self.graph=sorted(self.graph,key= lambda x:x[2])
        parent=[]
        for i in range(self.n):
            parent.append(-1)
        print(parent)
        i=0
        j=0
        while j < self.n-1:
            a,b,w=self.graph[i]
            print(a,b,w)
            i+=1
            x=self.find(parent,a)
            y=self.find(parent,b)
            if x!=y:
                j+=1
                mst.append([a,b,w])
                self.union(parent,x,y)
                print(parent)
        print("MST are")
        for x,y,w in mst:
            print("edges=",x," ",y," ",w)


#num=int(input("Enter the no.of vertices:"))
g=Graph(8)
'''for i in range(num):
    num=int(input("Enter the vertex :"))
    vertices.append(num)'''
print("Construct the graph")
vertices=[1,2,3,4,5,6,7,8]
print(vertices)
g.insert_edge(1,3,7)
g.insert_edge(1,2,1)
g.insert_edge(2,4,5)
g.insert_edge(3,4,2)
g.insert_edge(2,5,6)
g.insert_edge(5,7,9)
g.insert_edge(5,6,3)
g.insert_edge(7,8,4)
g.insert_edge(6,8,8)

g.Minimum_spaning_tree()
'''Output:
C:\Users\sreed\PycharmProjects\DAA\venv\Scripts\python.exe C:/Users/sreed/PycharmProjects/DAA/krushkal/greedy1.py
Construct the graph
[1, 2, 3, 4, 5, 6, 7, 8]
[-1, -1, -1, -1, -1, -1, -1, -1]
1 2 1
[-2, 1, -1, -1, -1, -1, -1, -1]
3 4 2
[-2, 1, -2, 3, -1, -1, -1, -1]
5 6 3
[-2, 1, -2, 3, -2, 5, -1, -1]
7 8 4
[-2, 1, -2, 3, -2, 5, -2, 7]
2 4 5
[-3, 1, 1, 3, -2, 5, -2, 7]
2 5 6
[-3, 1, 1, 3, 1, 5, -2, 7]
1 3 7
6 8 8
[-3, 1, 1, 3, 1, 5, 1, 7]
MST are
edges= 1   2   1
edges= 3   4   2
edges= 5   6   3
edges= 7   8   4
edges= 2   4   5
edges= 2   5   6
edges= 6   8   8

'''



