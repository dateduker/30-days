https://leetcode.com/problems/pascals-triangle/
```
vector<vector<int>> generate(int n) {
        vector<vector<int>> res;
        
        vector<int> t(1,1);
        res.push_back(t);
        if(n == 1) return res;
        
        t.resize(2,1);
        res.push_back(t);
        if(n == 2) return res;
        
        
        for(int i = 2; i < n; i++){
            vector<int> tmp(i+1,1);
            for(int j = 1; j < i; j++){
                tmp[j] = res[i-1][j] + res[i-1][j-1];
            }
            res.emplace_back(tmp);
        }
        
//         for(int i = 2; i < n; i++){
//             for(int j = 1; j < i; j++){
//                 res[i][j] = res[i-1][j] + res[i-1][j-1];
//             }
//         }
        
      
//         for(int i = 1; i <= n; i++)
//             res[i-1].resize(i);
        return res;
    }
```
