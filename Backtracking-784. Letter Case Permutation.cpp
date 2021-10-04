// 784. Letter Case Permutation

class Solution {
public:
    
    vector<string>res;
   
    
      void solve(string s,int idx,string curr){
          
          
          if(curr.length()==s.length()) {
              res.push_back(curr);
              return;
          }
         
          
          if(isdigit(s[idx])){
              
              solve(s,idx+1,curr+s[idx]);
          }else{
              
              solve(s,idx+1,curr+(char)(toupper(s[idx])));
               solve(s,idx+1,curr+(char)(tolower(s[idx])));
              
          }
            
         
      }
    vector<string> letterCasePermutation(string s) {
        
          
        solve(s,0,"");
        return res;
    }
};
