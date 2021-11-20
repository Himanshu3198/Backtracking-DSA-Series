class Solution {
public:
    
       vector<int>res;
    
       void dfs(int curr,int prev,int n,int k,int maxReach){
           
           
           if(n==0){
               res.push_back(curr);
               return;
           }
           if(curr>maxReach){
               return;
           }
           
           int next=prev+k;
           
           
           if(next<=9){
               
              int num=curr*10+next;

               dfs(num,next,n-1,k,maxReach);
           }
           
           next=prev-k;
           
           if(next>=0 and k!=0){
              int num=curr*10+next;
               dfs(num,next,n-1,k,maxReach);
           }
       }
    vector<int> numsSameConsecDiff(int n, int k) {
      
             if(n==1){
                 
                 return {1,2,3,4,5,6,7,8,9};
             }
        
          int maxReach=pow(10,n);
            maxReach--;
        
        for(int i=1;i<=9;i++){
            
            dfs(i,i,n-1,k,maxReach);
        }
        
        return res;
        
    }
};
