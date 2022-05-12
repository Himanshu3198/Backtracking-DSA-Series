class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        set<vector<int>>st;
        vector<vector<int>>res;
        res.push_back(nums);
        st.insert(nums);
        
        for(int i=0;i<nums.size();i++){
            
            for(int j=0;j<nums.size();j++){
                
                if(i==j) continue;
                
                swap(nums[i],nums[j]);
                if(!st.count(nums)){
                    st.insert(nums);
                    res.push_back(nums);
                
                }
                swap(nums[i],nums[j]);
                
            }
        }
        return res;
         
    }
};
