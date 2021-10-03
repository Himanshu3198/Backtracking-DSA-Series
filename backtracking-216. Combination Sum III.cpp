// 216. Combination Sum III

class Solution {
public:
     vector<vector<int>>res;
    
    void solve(vector<int>&v,int k,int n,int curr){
          
          if(v.size()>k or n<0){
              
              return;
          }
        
        if(v.size()==k and n==0){
            
            res.push_back(v);
            return;
        }
        
     
        
          for(int i=curr;i<=9;i++){
              
              if(i>n) return;
              
              v.push_back(i);
                
              solve(v,k,n-i,i+1);
              v.pop_back();
          }
        
        
        
        
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>v;
        
        solve(v,k,n,1);
        
        return res;
        
        
        
    }
};
