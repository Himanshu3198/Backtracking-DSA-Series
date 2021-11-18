class Solution {
public:
       vector<string>res;
    
    
       void helper(string s,set<string>st,int idx,string curr){
           
           if(idx==s.length()){
               
               res.push_back(curr.substr(1));
               return;
           }
           
           string temp="";
           
           for(int i=idx;i<s.length();i++){
               
               temp+=s[i];
               if(st.find(temp)!=st.end()){
                   
                   helper(s,st,i+1,curr+" "+temp);
               }
           }
       }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
         
        
        int n=s.length();
        set<string>st;
        
        for(auto it:wordDict) st.insert(it);
        
        
        helper(s,st,0,"");
        return res;
    }
};
