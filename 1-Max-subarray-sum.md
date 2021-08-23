#### Brute-force
```
int maxSubArray(vector<int>& a) {
        int n = a.size();
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int t = 0;
                for(int k = i ;  k <= j; k++){
                    t += a[k];
                }
                ans = max(ans, t);
            }
        }
        return ans;
    }
```

#### Kadane's Algorithm
```
int maxSubArray(vector<int>& a) {
        int n = a.size();
        int ans = a[0];
        int tmp = a[0];
        for(int i = 1; i < n; i++){
            tmp = max(tmp+a[i], a[i]);
            ans = max(ans, tmp);
        }
        return ans;
    }
```
