class Solution {
public:
   
     void solve(vector<int>&nums,set<vector<int>>&st,vector<int>v){
         if(v.size()==nums.size()){
             st.insert(v);
             return;
         }
         for(int i=0;i<nums.size();i++){
             
             if(nums[i]!=3198){
                 int temp=nums[i];
                 nums[i]=3198;   
                 v.push_back(temp);
                 solve(nums,st,v);
                 v.pop_back();
                 nums[i]=temp;
             }
         }
     }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        set<vector<int>>st;
        vector<vector<int>>res;
        solve(nums,st,{});
        for(auto it:st){
            res.push_back(it);
        }
        return res;
         
    }
};
