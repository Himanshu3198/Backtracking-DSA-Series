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
