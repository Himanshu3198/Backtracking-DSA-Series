class Solution {
public:
    vector<int>res;
    void solve(int n,int k,int maxNum,long long int curr){
        
        if(n==0) res.push_back(curr);
        if(curr>=maxNum) return;
        int prev=curr%10;
        int next=prev+k;
        long long int same;
        if(next<=9){
            long long int x=curr*10LL+(next);
            same=x;
            solve(n-1,k,maxNum,x);
        } 
            bool flag=false;
            for(int i=0;i<=9;i++){

                if(abs(prev-i)==k){
                long long int x;
                    if(i==0) x=curr*10;
                    else x=curr*10+i;
                    if(same!=x){
                    solve(n-1,k,maxNum,x);
                    flag=true;
                    break;
                    }
                }
            }
            if(!flag) return;
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        
         int maxNum=pow(10,n)-1;
         for(long long int i=1;i<=9;i++){
             solve(n-1,k,maxNum,i);
         }
        return res;
    }
};
