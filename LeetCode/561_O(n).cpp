// https://leetcode.com/problems/array-partition-i/description/

class Solution {
    int maxN = 10 * 1000;
public:
    int arrayPairSum(vector<int>& nums) {
        vector<int> occurs(maxN * 2 + 1, 0);
        int n = nums.size();
        for (int i = 0; i < n; i++)
            occurs[nums[i] + maxN]++;
        
        int cnt = 1;
        long long ans = 0;
        for (int i = 0; i < occurs.size(); i++)
        {
            if (occurs[i])
            {
                ans += ((occurs[i] + cnt) / 2) * (i - maxN);
                cnt = (cnt + occurs[i]) % 2;
            }
        }
        return ans;
    }
};
