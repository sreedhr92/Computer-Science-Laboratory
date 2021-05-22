import heapq
import copy
explored = set()
frontier = []
heapq.heapify(frontier)
discovered = set()
goal_state = ((0, 1, 2), (3, 4, 5), (6, 7, 8))


class Node:
    def __init__(self, s,parent):
        if parent == None:
            self.g = 0
        else:
            self.g = parent.g+1
        self.s = s
        self.h = self.heuristic()
        self.f = self.h + self.g

    def heuristic(self):
        dist =0
        for i in range(0, 3):
            for j in range(0, 3):
                if self.s[i][j] != goal_state[i][j]:
                    dist += 1
        return dist

    def __lt__(self, other):
        if self.f == other.f:
            return self.h < other.h
        return self.f < other.f


def find_blank(s):
    index1 = []
    for i in range(0, 3):
        for j in range(0, 3):
            if s[i][j] == 0:
                index1.append(i)
                index1.append(j)
    return index1


def swap_position(a, i1, j1, i2, j2):
    # print("swapping values",a[i1][j1],a[i2][j2])
    a1 = []
    for i in a:
        a1.append(list(i))
    a1[i1][j1], a1[i2][j2] = a1[i2][j2], a1[i1][j1]
    a2 = []
    for i in a1:
        a2.append(tuple(i))
    return tuple(a2)


def next_states(s):
    x = []
    blank_index = find_blank(s)
    a, b = blank_index[0], blank_index[1]
    # print("a,b",a,b)
    l = list(s)
    if a - 1 != -1:
        l1 = copy.deepcopy(l)
        s1 = swap_position(l1, a, b, a - 1, b)
        # print(discovered)
        if s1 not in discovered and s1 not in explored:
            x.append(s1)
    if b - 1 != -1:
        l2 = copy.deepcopy(l)
        s2 = swap_position(l2, a, b, a, b - 1)
        if s2 not in discovered and s2 not in explored:
            x.append(s2)
    if b + 1 != 3:
        l3 = copy.deepcopy(l)
        s3 = swap_position(l3, a, b, a, b + 1)
        if s3 not in discovered and s3 not in explored:
            x.append(s3)
    if a + 1 != 3:
        l4=copy.deepcopy(l)
        s4 = swap_position(l4, a, b, a + 1, b)
        if s4 not in discovered and s4 not in explored:
            x.append(s4)
    # states[tuple(s)] = x
    return x


def Astar(start,g):
    heapq.heappush(frontier, Node(start,None))
    count = 1
    print("Start State ->", start)
    discovered.add(start)
    while len(frontier) != 0:
        state = heapq.heappop(frontier)
        if state.s in explored:
            continue
        explored.add(state.s)
        if state.s == goal_state:
            print('Achieved Goal State', goal_state)
            return True
        for i in next_states(state.s):
            if i not in discovered:
                heapq.heappush(frontier, Node(i,state))
                discovered.add(i)
            elif i not in explored:
                heapq.heappush(frontier, Node(i,state))
        count +=1
    return False


start = ((7, 2, 4), (5, 0, 6), (8, 3, 1))
if not Astar(start,0):
    print("Couldn't reach goal")
else:
    print("Discovered Nodes",len(explored))

'''output:
Start State -> ((1, 4, 3), (5, 0, 6), (8, 2, 7))
Achieved Goal State ((0, 1, 2), (3, 4, 5), (6, 7, 8))
Discovered Nodes 46420

'''