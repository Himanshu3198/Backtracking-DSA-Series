class Solution {
public:
    
    
    void solve(vector<vector<int>>&res,int curr_index,int n,int k,vector<int>&v){
        
        

       
        if(v.size()==k){
            res.push_back(v);
            
         
            return;
            
        }
       
      
        for(int i=curr_index;i<=n;i++){
            
            v.push_back(i);
            solve(res,i+1,n,k,v);
            v.pop_back();
        }
      
        
    }
    vector<vector<int>> combine(int n, int k) {
     
        int i=1;
        vector<vector<int>>res;
        vector<int>v;
        solve(res,i,n,k,v);
        
        return res;
    }
};
