// 1415. The k-th Lexicographical String of All Happy Strings of Length n

class Solution {
public:
       vector<string>res;
    
    
    void solve(int n,string str){
        
        if(str.length()==n){
            res.push_back(str);
            return;
        }
        
        for(char i='a';i<='c';i++){
            
            if( i==str.back()) continue;
            
            str.push_back(i);
            
            solve(n,str);
             
            str.pop_back();
            
            
        }
    }

    string getHappyString(int n, int k) {
         string str="";
         solve(n,str);
        
        
        if(k>res.size()){
            return "";
        }
        
        return res[k-1];
    }
};
