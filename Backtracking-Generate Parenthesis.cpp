
// 22. Generate Parentheses

class Solution {
public:
    
  
    
     void helper(string curr,int open,int close,vector<string>&res,int n){
          
         
            if(curr.length()==2*n){       // length of generated combination must be equal to 2*n
                res.push_back(curr);        // when length of current string become 2*n push it into the  vector
            }
         
         if(open<n) helper(curr+"(",open+1,close,res,n);  //  add the open bracket in current string until its less than n
         if(close<open) helper(curr+")",open,close+1,res,n);  // add close bracket in current string untill its less than open bracket reason why  less than open bracket is close bracket cannot be more than open bracket and we have already inlcude one open bracket
     }
    vector<string> generateParenthesis(int n) {
      
          vector<string>res;
        
        helper("(",1,0,res,n);
        
        return res;
    }
};
