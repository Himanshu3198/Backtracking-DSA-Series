// 526. Beautiful Arrangement

class Solution {
public:
 
    
    void solve(vector<bool>&vis,int n,int idx,int &count){
        if(idx>n){
            count++;
        }
        
        for(int i=1;i<=n;i++){
            if(!vis[i] and (idx%i==0 or i%idx==0)){
                vis[i]=true;
                solve(vis,n,idx+1,count);
                 vis[i]=false; //backtracking
            }
        }
       
    }
    int countArrangement(int n) {
           int count=0;
           vector<bool>vis(n+1,false);
        
        solve(vis,n,1,count);
        
        return count;
    }
};
