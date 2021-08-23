https://leetcode.com/problems/set-matrix-zeroes

#### Using extra space
```
 void setZeroes(vector<vector<int>>& grid) {
        set<int> rset, cset;
        int r = grid.size(), c = grid[0].size();
        for(int i = 0; i < r; i++){
            for(int j = 0; j <c; j++){
                if(grid[i][j] == 0){
                    rset.insert(i);
                    cset.insert(j);
                }
            }
        }
        
        for(auto it : rset){
            for(int j = 0; j < c; j++){
                grid[it][j] = 0;
            }
        }
        for(auto it : cset){
            for(int j = 0; j < r; j++){
                grid[j][it] = 0;
            }
        }
    }
```

#### Without using set
```
 void setZeroes(vector<vector<int>>& m) {
        int left = 0, top = 0;
        int r = m.size(), c = m[0].size();
        
        for(int i = 0; i<r; i++) if(m[i][0] == 0) left = 1;
        for(int j = 0; j < c; j++) if(m[0][j] == 0) top  = 1;
        
        for(int i = 1; i <r; i++){
            for(int j = 1; j <c; j++){
                if(m[i][j] == 0){
                    m[0][j] = 0;
                    m[i][0] = 0;
                }
            }
        }
        for(int i = 1; i <r; i++){
            for(int j = 1; j < c; j++){
                if( m[0][j] == 0 || m[i][0]==0){
                   m[i][j] = 0;
                }
            }
        }
        
        if(left) for(int i = 0; i < r; i++) m[i][0] = 0;
        if(top) for(int j = 0; j < c; j++) m[0][j] = 0;
        
        return ;
        
    }
```
