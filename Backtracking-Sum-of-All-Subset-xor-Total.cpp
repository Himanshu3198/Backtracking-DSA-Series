
// 1863. Sum of All Subset XOR Totals

class Solution {
public:
    
    /* we have to do include the  xor with nums and exclude the nums  */
      
    
        vector<int>vec;
    
     int solve(vector<int>&nums,int idx,int xo,int n){
        
        if(idx==n){
            return xo ;
        }
        
     
         
           int  include= solve(nums,idx+1,xo^nums[idx],n);
           int exclude=solve(nums,idx+1,xo,n);
         
        
          return include+exclude;
          
           
      
    }
    int subsetXORSum(vector<int>& nums) {
     
        
           int res=0;
         int n=nums.size();
        
        int  xo=0;
        
      return solve(nums,0,xo,n);
        
        
    
        
     
    }
};
