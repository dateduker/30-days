#### [Leetcode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
#### [Interviewbit](https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-i/)
```
class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        if(n == 0) return 0;
        int ans = 0;
        int mn = a[0];
        for(int i = 1; i < n; i++){
            if(a[i] < mn) mn = a[i];
            else
                ans = max( ans, a[i] - mn);
        }
        return ans;
    }
};
```


