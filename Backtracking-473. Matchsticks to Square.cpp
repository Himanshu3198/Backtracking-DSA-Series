class Solution {
public:
    
    bool solve(vector<int>& matchsticks,int idx,int &sum1,int &sum2,int &sum3,int &sum4,int &tot){
        
        if(idx>=matchsticks.size()){
            return sum1==sum2 && sum2==sum3 && sum3==sum4;
        }
       
      
        if(sum1+matchsticks[idx]<=tot){
             sum1+=matchsticks[idx];
             if(solve(matchsticks,idx+1,sum1,sum2,sum3,sum4,tot)==1) return true;
             sum1-=matchsticks[idx];
        }
        if(sum2+matchsticks[idx]<=tot){
             sum2+=matchsticks[idx];
             if( solve(matchsticks,idx+1,sum1,sum2,sum3,sum4,tot)==1) return true;
             sum2-=matchsticks[idx];
        }
       if(sum3+matchsticks[idx]<=tot){
             sum3+=matchsticks[idx];
             if( solve(matchsticks,idx+1,sum1,sum2,sum3,sum4,tot)==1) return true;
            sum3-=matchsticks[idx];
        }
        if(sum4+matchsticks[idx]<=tot){
             sum4+=matchsticks[idx];
             if( solve(matchsticks,idx+1,sum1,sum2,sum3,sum4,tot)==1) return true;
            sum4-=matchsticks[idx];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum=accumulate(matchsticks.begin(),matchsticks.end(),0);
        sum/=4;
        // if(sum%4!=0) return false;
        int a=0,b=0,c=0,d=0,idx=0;
        sort(matchsticks.rbegin(), matchsticks.rend());
        return solve(matchsticks,idx,a,b,c,d,sum);
    }
};
