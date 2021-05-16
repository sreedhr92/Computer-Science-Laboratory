from collections import defaultdict
class stable_matching:
    def __init__(self,m,w):
        self.men=m
        self.women=w
        self.wives={}
        self.pair={}
        self.comp={}
        # creating a nested directory for ranking
        self.mrank=defaultdict(dict)
        self.wrank=defaultdict(dict)
        self.propose_track=defaultdict(dict)
        for man,pref in self.men.items():
            self.comp[man]=0
            for i,w in enumerate(pref,1):
                self.mrank[man][w] = i
        for wo,pref in self.women.items():
            for i,me in enumerate(pref,1):
                self.wrank[wo][me] = i
        #  print(self.mrank)
        #  print(self.wrank)
        for man,pref in self.men.items():
            for i,w in enumerate(pref):
                self.propose_track[man][w]=0

    def get_prefered(self,man):
        for i,j in self.propose_track.items():
            if i == man:
                for m,val in j.items():
                    if val == 0:
                        return m

    def propose(self,man):
        match=self.get_prefered(man)
        self.propose_track[man][match]=1
        self.wives[man]=match
        return match

    def undo_propose(self,man):
        del self.wives[man]

    def accept_proposal(self,man,woman):
        self.pair[woman]=man

    def reject_proposal(self,woman):
        self.comp[self.pair[woman]]=0
        del self.pair[woman]

    def completed(self):
        for i in self.comp.keys():
            if self.comp[i] == 0:
                return False
        return True
    def complete(self,man):
       self.comp[man]=1


    def get_unmatched(self):
        for i in self.comp.keys():
            if self.comp[i]==0:
                return i

    #def unstable(self,man,woman):


    def Gayle_shapeley_matching(self):
        count=0
        while True:
            if self.completed():
                break

            print("iteration #",count)
            man = self.get_unmatched()
            woman = self.propose(man)
           # print(man,woman,'\n')
            print("Man's status:",self.comp,'\n')
            if woman not in self.pair.keys():
                self.accept_proposal(man,woman)
                self.complete(man)
            else:
                man1 = self.pair[woman]
                if self.wrank[woman][man] < self.wrank[woman][man1]:
                    self.reject_proposal(woman)
                    self.accept_proposal(man,woman)
                    self.complete(man)
                else:
                    self.undo_propose(man)
            count+=1
            print("Pair made",self.pair)
        print("Non stable matching\n",self.comp)
        print(self.pair)

#m = {'a':('r','q','s'),'b':('s','q','r'),'c':('q','r','s')}
#w = {'q':('a','c','b'),'r':('c','a','b'),'s':('a','b','c')}

#m = {'a':('u','r','t','s'),'b':('r','t','u','s',),'c':('t','u','s','r'),'d':('u','r','t','s')}
#w = {'r':('a','c','d','b'),'s':('d','a','b','r'),'t':('c','b','d','a'),'u':('b','d','c','a')}
m=dict()
w=dict()
count=0
for line in open('data.txt'):
    val=[]
    j=0
    k=0
    if len(line)<3:
        count=1
        continue
    if count ==0:
        mkey=line.split(' ')
        for i in mkey:
            if j == 0:
                key1 = i
          #      print('key:',key1)
                j += 1
            else:
                val.append(i[0])
       # print(val)
        m[key1]=val
    else:
        wkey=line.split(' ')
        for i in wkey:
            if k == 0:
                key1=i
              #  print('key:', key1)
                k += 1
            else:
                val.append(i[0])
       # print(val)
        w[key1]=val


#print(m)
#print(w)
stable = stable_matching(m,w)
stable.Gayle_shapeley_matching()
