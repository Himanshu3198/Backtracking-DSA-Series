// 40. Combination Sum II


class Solution {
public:
    
    vector<vector<int>>res;
    
    void solve(vector<int>nums,int target,vector<int>&v,int idx){
        
        if(target==0){
            res.push_back(v);
            return;
        }
        
             for(int i=idx;i<nums.size();i++){
                 
                 if(nums[i]>target) return;
                 
                 if( i>idx and nums[i]==nums[i-1]) continue;
                 
                 v.push_back(nums[i]);
                 
                 solve(nums,target-nums[i],v,i+1);
                 v.pop_back();
             }
            
        }

    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<int>v;
       
        sort(candidates.begin(),candidates.end());
        
        solve(candidates,target,v,0);
        
        return res;
    }
};
