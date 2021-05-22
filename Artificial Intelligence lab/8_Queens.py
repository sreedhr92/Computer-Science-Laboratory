import copy

def print_table(board):
    for i in range(0, len(board)):
        for j in range(0, len(board[0])):
            print(board[i][j], end=" ")
        print()

def get_queen(board,c):
    for i in range(8):
        if board[i][c] == 1:
            return i

def check_row(board,c):
    i = 0
    count = -1
    while i < 8:
        if board[i][c] == 1:
            count+=1
        i+=1
    return count

def check_column(board,r):
    i = 0
    count = -1
    # print("check column working")
    while i < 8:
        if board[r][i] == 1:
            count += 1
        i += 1
    #print("Column count", count)
    return count

def check_diagonal(board,r,c):
    i=r
    j=c
    count = 0
    # print("check_diagonal working ")
    while i < len(board) and j < len(board):
        if i == r and j == c:
            i += 1
            j += 1
            continue
        if board[i][j]==1:
            count+=1
        i+=1
        j+=1
    i = r
    j = c
    while i > -1 and j < len(board):
        if i==r and j==c:
            i -= 1
            j += 1
            continue
        if board[i][j]==1:
            count+=1
        i-=1
        j+=1
    i = r
    j = c
    while i > -1 and j > -1:
        if i==r and j==c:
            i -= 1
            j -= 1
            continue
        if board[i][j]==1:
            count+=1
        i-=1
        j-=1
    i = r
    j = c
    while i < len(board) and j > -1:
        if i==r and j==c:
            i += 1
            j -= 1
            continue
        if board[i][j]==1:
            count+=1
        i+=1
        j-=1
    return count

def objective(board):
    

def next_state(board,moves,c):
    i=0
    r = get_queen(board,c)
    while i < len(board):
        if i not in moves:
            board[i][c] =1
            board[r][c] =0
            break
        else:
            i+=1
    return board,i

def hill_climbing(board,count,c):
    count+=1
    if c==8:
        c=0
    goal = copy.deepcopy(board)
    # print("Hill_climbing working")
    error = objective(board)
    moves = set()
    while(1):
        r = get_queen(goal, c)
        if r not in moves:
            moves.add(r)
        moves.add(r)
        new,r = next_state(goal,moves,c)
        if r not in moves:
            moves.add(r)
        print(moves)
        new_error = objective(new)
        if len(moves) == 7:
            moves.clear()
            c = c + 1
        if new_error < error:
            error = new_error
            goal = new
            count+=1
            c+=1
            hill_climbing(goal,c+1,count+1)
            break
        if count == 500:
            return False
        if c == 8:
            print("\nFinal  state is \n")
            print_table(goal)
            print("Error",objective(goal))
            break
    return True


board = [[1, 0, 0, 0, 0, 0, 0, 0],
         [0, 0, 1, 0, 0, 0, 0, 0],
         [0, 1, 0, 0, 0, 0, 0, 0],
         [0, 0, 0, 0, 1, 0, 0, 0],
         [0, 0, 0, 0, 0, 0, 1, 0],
         [0, 0, 0, 1, 0, 0, 0, 0],
         [0, 0, 0, 0, 0, 1, 0, 0],
         [0, 0, 0, 0, 0, 0, 0, 1]]

print("Starting table")
print_table(board)
print(objective(board))
#if hill_climbing(board,0,0):
#    print("\nReached Local minima or Goal")
#else:
#    print("\nFailed!")

