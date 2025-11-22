// 37. Sudoku Solver


class Solution {
public:
    
    bool isValid(vector<vector<char>>&board, char val,int row,int col){
        
        
        for(int i=0;i<9;i++){
            
            if(board[row][i]==val) return false;
            
            if(board[i][col]==val) return false;
            
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val) return false;
            
            
        
        }
        return true;
    }
    bool solve(vector<vector<char>>&board){
        
        int row=board.size();
        int col=board[0].size();
        for(int i=0;i<row;i++){
            
          for(int j=0;j<col;j++){
              
              
              if(board[i][j]=='.'){
                  
                  
                  for(char num='1';num<='9';num++){
                      
                      
                      if(isValid(board,num,i,j)==true){
                             board[i][j]=num;
                           if(solve(board)==true) return true;
                           
                           else board[i][j]='.';
                         
                      }
                     
                  }
                   return false;
                  
              }
                
              
          }
         
          
        }
          return true;
    }
    
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        
        
    }
};


// java version of this

class Solution {

    private Boolean isValid(char [][] board,int row,int col, char c){
   
        for(int i=0;i<9;i++){

            if(board[i][col] == c) return false;
            if(board[row][i] == c) return false;

            int r = 3*(row/3) + i/3;
            int cc = 3*(col/3) + i%3;

            if(board[r][cc] == c) return false;
        }

        return true;
    }
    private Boolean solve(char [][] board){
                
                int n = board.length;

                for(int i=0;i<n;i++){
                    for(int j=0; j<n;j++){

                        if(board[i][j] == '.'){

                            for(char c = '1'; c<='9';c++){
                                
                                if(isValid(board,i,j,c))
                                    {
                                    
                                      board[i][j] = c;
                                      if(solve(board) == true){
                                         return true;
                                    }
                                    else
                                    {
                                        board[i][j] = '.';
                                    }
                                }
                              
                            }
                            return false;
                        }
                    }
                }

                return true;
        
    }

    public void solveSudoku(char[][] board) {

        solve(board);
    }
}
