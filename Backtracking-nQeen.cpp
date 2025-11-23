class Solution {
public:
     vector<vector<string>> ret;
    bool is_valid(vector<string> &board, int row, int col){
        // check col
        for(int i=row;i>=0;--i)
            if(board[i][col] == 'Q') return false;
        // check left diagonal
        for(int i=row,j=col;i>=0&&j>=0;--i,--j)
            if(board[i][j] == 'Q') return false;
        //check right diagonal
        for(int i=row,j=col;i>=0&&j<board.size();--i,++j)
            if(board[i][j] == 'Q') return false;
        return true;
    }
    void dfs(vector<string> &board, int row){
        // exit condition
        if(row == board.size()){
            ret.push_back(board);
            return;
        }
        // iterate every possible position
        for(int i=0;i<board.size();++i){
            if(is_valid(board,row,i)){
                // make decision
                board[row][i] = 'Q';
                // next iteration
                dfs(board,row+1);
                // back-tracking
                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
		// return empty if n <= 0
        if(n <= 0) return {{}};
        vector<string> board(n,string(n,'.'));
        dfs(board,0);
        return ret;
    }
};

// java version
class Solution {

    private Boolean isValid(List<List<Character>> board, int row, int col, int n) {

        // check in col
        for (int r = 0; r <row; r++) {

            if (board.get(r).get(col) == 'Q')
                return false;
        }

        // left up diagonal

        for (int r = row, c = col; r >= 0 && c >= 0; r--, c--) {

            // if(board[r][c] == 'Q') return false;  
            if (board.get(r).get(c) == 'Q')
                return false;
        }

        // right up diagonal

        for (int r = row, c = col; r >= 0 && c < n; r--, c++) {

            // if(board[r][c] == 'Q') return false;  
            if (board.get(r).get(c) == 'Q')
                return false;
        }

        return true;

    }

    public Boolean dfs(List<List<Character>> board, List<List<String>> res, int row, int n) {

        if (row == n) {
            List<String> solution = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                StringBuilder sb = new StringBuilder();
                for (int j = 0; j < n; j++) {
                    sb.append(board.get(i).get(j));
                }
                solution.add(sb.toString());
            }
            res.add(solution);
            return true;
        }
        for (int col = 0; col < n; col++) {

              if (isValid(board, row, col, n)) {

                board.get(row).set(col, 'Q');
                dfs(board, res, row + 1, n);
                board.get(row).set(col, '.');
            }

        }
        return false;
    }

    public List<List<String>> solveNQueens(int n) {

        List<List<Character>> board = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            List<Character> row = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                row.add('.');
            }
            board.add(row);
        }

        List<List<String>> res = new ArrayList<>();
        dfs(board, res, 0, n);

        return res;
    }
}

