https://leetcode.com/problems/longest-increasing-subsequence/


* T: O(nlogn)
* S: O(n)

```
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n  = nums.size();
        vector<int> dp(n+1, INT_MAX);
        
        dp[0] = INT_MIN;
        
        //upperbound for not strictly increasing, lowerbound for strictly increasing
        for(int i: nums){
            auto it = lower_bound(dp.begin(), dp.end(), i) - dp.begin(); 
            dp[it] = i;            
        }
        
        for(int i = n; i>=0; i--)
            if(dp[i] != INT_MAX)
                return i;
        return 1;
    }
};
```

* T: O(n^2)
* S: O(n)

```
class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n  = a.size();
        vector<int> dp(n, 1);
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(a[i] > a[j] )
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
```
