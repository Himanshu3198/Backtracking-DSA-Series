
class Solution {  
public:
         void solve(vector<int>&arr,int index,int target,vector<int>vec, vector<vector<int>>&ans){
             if(index==arr.size()){
                 if(target==0){
                     ans.push_back(vec);       
                 }
                  return;
             }
             
                  solve(arr,index+1,target,vec,ans); 
             if(arr[index]<=target){
                 
                 vec.push_back(arr[index]);
                 solve(arr,index,target-arr[index],vec,ans);
                
             } 
             
        
               
         }
    

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>>ans;
        vector<int>vec;
        solve(candidates,0 ,target,vec,ans);
        return ans;
        
        
    }
};
