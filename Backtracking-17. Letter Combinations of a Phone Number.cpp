#define ll long long int
class Solution {
public:
    vector<string>res;
    void solve(string digits,unordered_map<char,string>&mp,int idx,string curr){
         
        if(curr.size()==digits.size()){
            res.push_back(curr);
            return;
        }
        for(int i=idx;i<digits.size();i++){
              
              for(auto s:mp[digits[i]]){
                  if(idx>=digits.size()) return;
                  curr+=s;
                  if(idx<digits.size())
                  solve(digits,mp,idx+1,curr);
                  if(curr.size()>0)
                     curr.pop_back();
                  
              }
              
              
              
              
        }
         
    }
    vector<string> letterCombinations(string digits) {
           int n=digits.size();
           string curr;
           unordered_map<char,string>mp; 
          
           mp['2']="abc";
           mp['3']="def";
           mp['4']="ghi";
           mp['5']="jkl";
           mp['6']="mno";
           mp['7']="pqrs";
           mp['8']="tuv";
           mp['9']="wxyz";
          
    
        int i=0;
       solve(digits,mp,i,curr);
           return res;
          
           
    }
};
