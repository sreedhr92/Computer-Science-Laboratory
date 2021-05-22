GameState = namedtuple('GameState', ['to_move', 'utility', 'board', 'moves'])

class TicTacToe:
    def __init__(self, h=3, v=3, k=3):
        self.h = h
        self.v = v
        self.k = k
        moves = [(x, y) for x in range(1, h + 1)
                 for y in range(1, v + 1)]
        self.initial = GameState(to_move='X', utility=0, board={}, moves=moves)
    
    def 
        
