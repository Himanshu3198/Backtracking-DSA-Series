// 79. Word Search

class Solution {
public:
    
  
 bool dfs(vector<vector<char>>&board,string word,vector<vector<int>>&vis,int x,int y,int n,int m,int idx){
        
     
          if(idx==word.size()){
              return true;
          }
        if(x<0 or x>=n or y<0 or y>=m or vis[x][y]==1){
            return false;
        }

          if(board[x][y]==word[idx]) {
        
                vis[x][y]=1;
             if(
           dfs(board,word,vis,x+1,y,n,m,idx+1)or
           dfs(board,word,vis,x-1,y,n,m,idx+1)or
           dfs(board,word,vis,x,y-1,n,m,idx+1)or
           dfs(board,word,vis,x,y+1,n,m,idx+1)){
                 
                 return true;
             }
                 
               
              
          }
     
                  vis[x][y]=0;
                return false;
    
    }
 
    bool exist(vector<vector<char>>& board, string word) {
        
        
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
           for(int i=0;i<n;i++){
               
               for(int j=0;j<m;j++){
                   
                   
                   if(board[i][j]==word[0]){
                       
                      if(  dfs(board,word,vis,i,j,n,m,0)==true){
                          return true;
                      }
                   }
               }
           }
        
        
         
        return false;
    }
};
