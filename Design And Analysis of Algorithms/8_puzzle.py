END = [[1,2,3],[4,5,6],[7,8,0]]
class node:
    def __init__(self,state,previous,g,h,dir):
        self.state = state
        self.previous = previous
        self.g =g
        self.h=h
        self.dir=dir

    def f(self):
        return self.g+ self.h

    def equal(self):
        return self.state == END
    
