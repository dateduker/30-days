[Leetcode](https://leetcode.com/problems/find-the-duplicate-number/)
#### Using Floyds cycle
```
int findDuplicate(vector<int>& a) {
        int s = 0, f = 0;
        s = a[s], f = a[a[f]];
        while(s != f){
            s = a[s];
            f = a[a[f]];
        }
        
        f = 0;
        while(s!=f){
            s = a[s];
            f = a[f];
        }
        return s;
    }
```
