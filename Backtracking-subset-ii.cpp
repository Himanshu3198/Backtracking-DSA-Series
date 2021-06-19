
// 90. Subsets II

class Solution {
public:
    vector<vector<int>>res;
    
    void solve(vector<int>&nums,vector<int>&v,int idx){
        
        res.push_back(v);
        
        for(int i=idx;i<nums.size();i++){
            
              if(i>idx and nums[i]==nums[i-1]) continue;
            
                v.push_back(nums[i]);
               solve(nums,v,i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
     
        
        vector<int>v;
        sort(nums.begin(),nums.end());
        
        solve(nums,v,0);
        return res;
    }
};
