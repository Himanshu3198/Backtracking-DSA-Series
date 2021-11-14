class CombinationIterator {
public:
    
      vector<string>res;
      int curr=0;
     
    
      void solve(string &ch,string temp, int idx,int len){
        
          
          if(temp.size()==len){
              res.push_back(temp);
              return;
              
          }
            if(idx>=ch.length()) return;
          
          solve(ch,temp+ch[idx],idx+1,len);
          solve(ch,temp,idx+1,len);
          
      }
    CombinationIterator(string ch ,int len) {
           
          string temp="";
        solve(ch,temp,0,len);
        
        for(auto it:res) cout<<it<<" ";
        
         
    }
    
    string next() {
          string ans="";
        if(curr!=res.size()){
            ans=res[curr];
            curr++;
          
        }
        return ans;
        
    }
    
    bool hasNext() {
        
        if(curr==res.size()) return false;
        
        return true;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
