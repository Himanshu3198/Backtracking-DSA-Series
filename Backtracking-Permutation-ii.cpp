permutaion  II



class Solution {
public:
    
    vector<vector<int>>res;
    
    void solve(vector<int>&nums,int idx){
        
        if(idx==nums.size()){
            
            res.push_back(nums);
            return;
        }
          unordered_set<int>st;
        for(int i=idx;i<nums.size();i++){
            
           if(st.find(nums[i])!=st.end()==true){
               continue;
           }
              st.insert(nums[i]);
           swap(nums[i],nums[idx]);
            solve(nums,idx+1);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      
 
        solve(nums,0);
        return res;
    }
};
