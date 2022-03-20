class Solution {
public:
      
//            time complexity O(2^12)
//            space complexity O(12)
             int maxSum;
        void helper(vector<int>alice,vector<int>bob,int numsArrows,vector<int>&ans,int idx, int sum){
        
            if(idx<=-1 or numsArrows==0){
                if(sum>maxSum){
                    ans=bob;
                     maxSum=sum;
                    if(numsArrows>0) ans[0]+=numsArrows;
                    return;
                }      
            }   
            
            if(idx>=0){
                 if(numsArrows<(alice[idx]+1)){
                  helper(alice,bob,numsArrows,ans,idx-1,sum);
                  return;
            }else{
                  helper(alice,bob,numsArrows,ans,idx-1,sum);
                  numsArrows-=(alice[idx]+1);
                  bob[idx]=(alice[idx]+1);
                  sum+=(idx);
               
                  helper(alice,bob,numsArrows,ans,idx-1,sum);
                  return;
               }
            }
           
        }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        
           maxSum=0;
           vector<int>bobArrows(12,0);
           vector<int>ans(12,0);
           helper(aliceArrows,bobArrows,numArrows,ans,11,0);
        
           return ans;
    }
};
