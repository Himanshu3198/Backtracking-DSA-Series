// Expected Time Complexity: O(2N)
// Expected Auxiliary Space: O(N)
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
    
    
    public:

    void solve(vector<int> &arr,int index,int sum,int N,vector<int>&giveSubset){
        
        
        if(index==N){
            
            
            giveSubset.push_back(sum);
            return ;
        }
        
        
        
        solve(arr,index+1,sum+arr[index],N,giveSubset);
        solve(arr,index+1,sum,N,giveSubset);
    }
public:

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        
        vector<int>giveSubset;
        solve(arr,0,0,N,giveSubset);
        sort(giveSubset.begin(),giveSubset.end());
        
        return giveSubset;
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
