1219. Path with Maximum Gold

class Solution {
public:
    
       int maxGold=0;
    
       void dfs(vector<vector<int>>&grid,int i,int j,int n,int m,int currGold){
           
           if(i<0 or i>=n or j<0 or j>=m or grid[i][j]==0 ){
               return;
           }
           
         
           
           currGold+=grid[i][j];
           int temp=grid[i][j];
           grid[i][j]=0;
           
           maxGold=max(maxGold,currGold);
           
           dfs(grid,i+1,j,n,m,currGold);
           dfs(grid,i-1,j,n,m,currGold);
           dfs(grid,i,j+1,n,m,currGold);
           dfs(grid,i,j-1,n,m,currGold);
           
           grid[i][j]=temp;
       }
    int getMaximumGold(vector<vector<int>>& grid) {
        
         int n=grid.size();
         int m=grid[0].size();
        
        
        int currGold=0;
        
           
         for(int i=0;i<n;i++){
             
             for(int j=0;j<m;j++){
                 
                 if(grid[i][j]==0) continue;
                 
                 dfs(grid,i,j,n,m,currGold);
             }
             
         }
        
        return maxGold;
    }
};
