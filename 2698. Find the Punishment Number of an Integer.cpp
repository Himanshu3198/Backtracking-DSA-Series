class Solution {
public:
    
    bool isPossible(int target,string s,int sum){
        if(s=="" && target==sum)
            return true;
        
        for(int i=1;i<=s.size();i++){
            string t=s.substr(0,i);
            int curr=stoi(t);
            if(isPossible(target+curr,s.substr(i),sum)==true) return true;
         }  
         return false;
    }
    int punishmentNumber(int n) {

        int ans=0;
        for(int i=1;i<=n;i++){
            int sq=i*i;
            string s=to_string(sq);
            if(isPossible(0,s,i))
                ans+=i*i;    
        }
        return ans;
    }
};
