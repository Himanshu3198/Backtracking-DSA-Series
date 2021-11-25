class Solution {
public:
    
    
        bool isPalindrome(string s){
            
            
            int  low=0,high=s.length()-1;
            
            
            while(low<high){
                
                if(s[low]!=s[high]){
                    return false;
                }
                low++;
                high--;
            }
            
            return true;
        }
    
       int ans=0;
    
      void solve(string &s,string &s1,string  &s2,int idx){
          
          
          if(idx>=s.length()){
              
              if(isPalindrome(s1) and isPalindrome(s2)){
                  
                  int n=s1.length();
                  int m=s2.length();
                  ans=max(ans,n*m);
              }
              return;
          }
          
          solve(s,s1,s2,idx+1);
          s1.push_back(s[idx]);
          solve(s,s1,s2,idx+1);
          s1.pop_back();
          
          s2.push_back(s[idx]);
          solve(s,s1,s2,idx+1);
          s2.pop_back();
      }
    int maxProduct(string s) {
        
        
        string s1="",s2="";
        
        
        solve(s,s1,s2,0);
        
        return ans;
        
    }
};
