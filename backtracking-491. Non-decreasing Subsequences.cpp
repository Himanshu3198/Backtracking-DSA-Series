class Solution
{
    public:
        vector<vector < int>> res;

    void solve(vector<int> &nums, vector<int> v, int idx)
    {
        if (idx == nums.size())
        {
            if (v.size() >= 2)
                res.push_back(v);
            return;
        }
        solve(nums, v, idx + 1);
        if (v.size() == 0)
        {
            v.push_back(nums[idx]);
            solve(nums, v, idx + 1);
        }
        else if (v.size() > 0 && nums[idx] >= v.back())
        {
            v.push_back(nums[idx]);
            solve(nums, v, idx + 1);
        }
    }
    vector<vector < int>> findSubsequences(vector<int> &nums)
    {
        vector<int> v;
       	// for(int i=0;i < nums.size();i++){
       	//      v.push_back(nums[i]);
        solve(nums, v, 0);
       	//      v.pop_back();
       	// }

        return res;
    }
};
