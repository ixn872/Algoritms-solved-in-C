class TicTacToe {
public:
    int gridS;
    vector<vector<int>> grid;
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        gridS = n;
        vector<vector<int>> temp(n, vector<int>(n, 0));
        grid = temp;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        
        int numCol = 0;
        int numRow = 0;
        int diagLR = 0;
        int diagRL = 0;
        int diagCol = gridS-1;
        int diagRow = 0;
        
        grid[row][col] = player;
        
        for (int i=0; i<gridS; i++) {
            if (grid[row][i] == player) numCol++;
            if (grid[i][col] == player) numRow++;
            if (grid[i][i] == player) diagLR++;
            if (grid[diagRow+i][diagCol-i] == player) diagRL++;
            
            if (numCol == gridS || numRow == gridS || diagLR == gridS || diagRL == gridS) {
                return player;
            }
                        
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
