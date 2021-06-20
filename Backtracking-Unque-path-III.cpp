// 980. Unique Paths III
class Solution {
public:
   
    
      int dfs(vector<vector<int>>& grid,int i,int j,int n,int m,int zeros){
          
          if(i<0 or i>=n or j<0 or j>=m or grid[i][j]==-1 ){
              return 0;
          }
          
          if(grid[i][j]==2){
              return zeros==-1?1:0;
          }
          zeros--;
          grid[i][j]=-1;
          
          int total_ways=dfs(grid,i-1,j,n,m,zeros)+
              dfs(grid,i+1,j,n,m,zeros)+
              dfs(grid,i,j-1,n,m,zeros)+
              dfs(grid,i,j+1,n,m,zeros);
          
          grid[i][j]=0;
          zeros++;
          
          return total_ways;
      }
    int uniquePathsIII(vector<vector<int>>& grid) {
     
        
        int zeros=0,xx,yy;
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==0){
                    zeros++;
                }
                else if(grid[i][j]==1){
                    xx=i,yy=j;
                }
            }
        }
        
     return   dfs(grid,xx,yy,n,m,zeros);
        
    
    }
};
