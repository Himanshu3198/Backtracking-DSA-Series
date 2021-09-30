class Solution {
public:
   
      
    
    bool solve(vector<int>&nums,vector<int>&vis,int k,int idx,int curr,int target){
            
            if(k==1){
                
                return true;
            }
            
           if(curr==target){
               
               
                return solve(nums,vis,k-1,0,0,target);
           }
        
           if(curr>target){
               return false;
           }
        
            
            
            for(int i=idx;i<nums.size();i++){
                
                   if(vis[i]){
                       continue;
                   } 
                       
                     vis[i]=1;
                      if( solve(nums,vis,k,i+1,curr+nums[i],target)){
                          return true;
                      } 
                         vis[i]=0;
                   
             
                  
                
            }
          
            return false;
            
        }
        
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k) return false;
         vector<int>vis(nums.size(),0);
        int i=0;
        int curr=0;
        int target=sum/k;
    
       return solve(nums,vis,k,i,curr,target);
        
       
        
        
        
       
        
         
    }
};
