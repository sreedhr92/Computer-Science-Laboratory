MAX=1000
class Heap:
    def __init__(self):
        self.n=0
        self.a=[]
        self.a.append([-1,-1])

    def insert(self,i,k):
        self.n+=1
        j=self.n
        while(a[j/2][1]>k):
            self.a.insert(j,self.a[j/2])
            j/=2
        self.a.insert(j,[i,k])

    def Deletemin(self):
        min=[]
        min.append(self.a[1])
        self.n-=1
        last=[]
        last.append(self.a[self.n])
        j=1
        while(2*j<=self.n):
            c=j*2
            if self.a[c+1][1] < self.a[c][1]:
                c=c+1
            if last[1] > self.a[c][1]:
                self.a[j]=self.a[c]
            else:
                break
            j=c
        self.a[j]=last
        return min

    def print(self,x,h):
        if x <=self.n:
            for i in range(0,h+1):
                print("\t\t",end="")
            print("Item= ",self.a[x][0],"Key=",self.a[x][1])
            self.print(2*x,h+1)
            self.print(2*x+1,h+1)
    def parent(self,i):
        return (i-1)/2
    def get_index(self,item):
        for i in range(1,n+1):
            if item == self.a[i][0]:
                return i
    def DecreaseKey(self,x,k):
        i=self.get_index(x)
        self.a[i]=[x,k]
        while i!=0 and self.a[self.parent(i)][1] > self.a[i][1]:
            self.a[i],self.a[self.parent(i)]=self.a[self.parent(i)],self.a[i]

class DirectedEdge:
    def __init__(self,v,w,weight):
        self.x=v
        self.y=w
        self.weigth=weight
    def weight(self):
        return self.weight
    def from_(self):
        return self.x
    def to_(self):
        return self.y

class WeightedDigraph:
    def __init__(self,n):
        self.n=n
        self.v=[]
        self.a=[[0 for i in range(n)]for j in range(n)]
        self.e=0
    def EdgeWeightedDigraph(self,g,e,v):
        self.v=v
        self.e=e
        self.a=g
    def V_(self):
        return self.n
    def E_(self):
        return self.e
    def add_edge(self,source,desti,weight):
        for i in range(self.n):
            for j in range(self.n):
                if self.v[i]==source and self[j]==desti:
                    self.a[i][j] = weight
                    break
    def adj(self,vertex):
        i=self.v.index(vertex)
        for j in range(self.n):
            if self.a[i][j] >0:
                print("The adj edge are:",self.v[j])
    def edges(self):
        for i in range(self.n):
            for j in range(self.n):
                if self.a[i][j] > 0:
                    print("The start vertex =",self.v[i],"The end vertex =",self.v[j],"Weight =",self.a[i][j])

class SP:
    dist=[]
    size=0
    v_id=[]
    minheap=Heap()
    def __init__(self,g,s):
        self.source=s
        self.graph=g
        self.G = G
        self.v_id = G.v
        pos = self.findIndex(s)
        self.size = len(self.v_id)
        for i in range(0, len(self.v_id)):
            if (i == pos):
                self.dist.append([self.v_id[i], 0])
            else:
                self.dist.append([self.v_id[i], MAX])
            self.minheap.insert(self.v_id[i], self.dist[pos][1])
    def disTo(self,vertex):
        i= self.graph.v.index(self.source)
        j= self.graph.v.index(vertex)
        if self.graph.a[i][j]>0:
            return self.graph.a[i][j]
        else
            return 1000

    def findIndex(self, v):
        pos = -1
        for i in range(0, len(self.v_id)):
            if (self.v_id[i] == v):
                pos = i
                return pos
        return pos

    def relax(self, e):
        f = self.findIndex(e.From())
        t = self.findIndex(e.to())
        w = e.Weight()
        self.dist[t][1] = self.dist[f][1] + w
        self.minheap.DecreaseKey(e.to(), w)

    def tense(self, e):
        f = self.findIndex(e.From())
        t = self.findIndex(e.to())
        w = e.Weight()
        if (self.dist[f][1] + w < self.dist[t][1]):
            return True
        else:
            return False

    def findMin(self):
        min1 = self.minheap.DeleteMin()
        return min1[0]

    def dijkstra(self):
        for i in range(0, self.size):
            min1 = self.findMin()
            edges = self.G.adj(min1)
            for j in edges:
                if (self.tense(j)):
                    self.relax(j)
        print(self.dist)





