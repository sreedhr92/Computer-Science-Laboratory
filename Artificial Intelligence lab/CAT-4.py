import heapq
import copy
from itertools import permutations
explored = set()
frontier = []
heapq.heapify(frontier)
discovered = set()
class Node:
    # initialising the node with state ,its no. of steps
    # the root in case no. of cuts already made(g), its heuristic (no.of. disstateed paragragh)(h).
    def __init__(self,s,parent):
        if parent == None:
            self.g = 0
        else:
            self.g = parent.g + 1
        self.s = s
        self.h = self.heuristic()
        self.f = self.h + self.g

    def heuristic(self):
        dist = 0
        for i in range(len(self.s)):
            for  j in self.s:
                if j!= i+1:
                    dist += 1
        return dist

    # overwritting the lt function to sort the min heapq according to heuristic
    def __lt__(self,other):
        if self.f == other.f:
            return self.h < other.f
        return self.f < other.f

def test_goal(state):
    count = 0
    for i in range(len(state)):
        for j in state:
            if i+1 != state:
                count+=1

    if count == 0:
        return True
    else :
        return False



def next_states(state):
    next_state = []
    for l in range(len(state)):
        for r in range(l + 1, len(state) + 1):
            sublist = list(state[l:r])
            prevlist = list([x for x in state])

            for i in range(r - 1, l - 1, -1):
                prevlist.pop(i)

            for i in range(len(prevlist) + 1):
                newlist = prevlist[:i] + sublist + prevlist[i:]

                if newlist != list(state) and tuple(newlist) not in next_state:
                    next_state.append(tuple(newlist))
    return next_state




def BFS(start,goal):
    heapq.heappush(frontier, Node(tuple(start),None))
    count = 0
    #print("Start state ->",start)
    discovered.add(tuple(start))
    while len(frontier) != 0:
        state = heapq.heappop(frontier)
        if tuple(state.s) in explored:
            continue
        explored.add(tuple(state.s))
        if tuple(state.s) == goal: 
            break # or we can use state.h == 0:
            print("The Paragraph is now sorted", state.s)
            return True
        for i in next_states(state.s):
            if tuple(i) == goal:
                print("The Paragraph is now sorted", state.s)
                return True
            if tuple(i) not in discovered:
                heapq.heappush(frontier, Node(tuple(i),None))
                discovered.add(tuple(i))
            elif tuple(i) not in explored:
                heapq.heappush(frontier, Node(tuple(i),None))
    return False

def Astar(start,g,goal):
    heapq.heappush(frontier, Node(start,None))
    count = 1
    # print("Start State ->", start)
    discovered.add(tuple(start))
    while len(frontier) != 0:
        state = heapq.heappop(frontier)
        if tuple(state.s) in explored:
            continue
        explored.add(tuple(state.s))
        if state.s == goal: # or we can use state.h == 0:
            print("The Paragraph is now sorted",state.s)
            break
            return True
        for i in next_states(state.s):
            if tuple(i) == goal:
                print("The Paragraph is now sorted", state.s)
                break
                return True
            if tuple(i) not in discovered:
                heapq.heappush(frontier, Node(i,state))
                discovered.add(tuple(i))
            elif tuple(i) not in explored:
                heapq.heappush(frontier, Node(i,state))
    return False


BFS([1,2,4,3], sorted((2, 1, 4, 3)))
print("Min number of states ",len(explored)-1)
print("Algorithm Completed")

# Performance Measure ...
print("Best First Search ")
print(len(discovered))
print(len(explored))
print(len(frontier))

explored = set()
frontier = []
heapq.heapify(frontier)
discovered = set()

Astar([2, 1, 4, 5], 0, sorted((2, 1, 4, 3)))
print("Min number of states ", len(explored) - 1)
print("Algorithm Completed")

print("A star Search ")
print(len(discovered))
print(len(explored))
print(len(frontier))

'''#Output:
Min number of states  23
Algorithm Completed
Best First Search
24
24
0
Min number of states  23
Algorithm Completed
A star Search
24
24
0'''