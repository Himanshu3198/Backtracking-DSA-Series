// 1980. Find Unique Binary String

class Solution {
public:
    
        string ans="";
    
    void solve(set<string>st,string curr,int n){
        
        if(curr.length()>n){
            return;
        }
        
        if(curr.length()==n){
            
            if(st.find(curr)!=st.end()){
                return;
            }
            else{
                ans=curr;
                return;
            }
        }
        
        solve(st,curr+'0',n);
        if(ans!=""){
            return;
        }
        solve(st,curr+'1',n);
        if(ans!=""){
            return;
        }
        
       
    }
    string findDifferentBinaryString(vector<string>& nums) {
            
            set<string>st;
        
           int n=nums[0].length();
        
          for(auto it:nums){
              
              st.insert(it);
          }
        
          solve(st,"",n);
          return ans;
    } 
};
