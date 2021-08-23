#### https://leetcode.com/problems/rotate-image/

#### https://www.interviewbit.com/problems/rotate-matrix/

For 90 deg rotation
1. Transpose
2. Reverse row, if clockwise rotation, else reverse colum, if anti clockwise rotation
```
class Solution {
public:
    void rev(vector<int> &v, int l, int r){
        while(l<r) swap(v[l++], v[r--]);
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++)
            swap(matrix[i][j], matrix[j][i]);
        } 
        for(int i = 0; i < n; i++)
        rev(matrix[i], 0, n-1);
    }
};
```

#### https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation
```
class Solution {
public:
    void rev(vector<int> &v, int l, int r){
        while(l<r) swap(v[l++], v[r--]);
    }
    bool rotate(vector<vector<int>>& matrix, vector<vector<int>>& target){
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++)
            swap(matrix[i][j], matrix[j][i]);
        } 
        for(int i = 0; i < n; i++)
        rev(matrix[i], 0, n-1);
        
        return matrix == target;

    }
    bool findRotation(vector<vector<int>>& matrix, vector<vector<int>>& target) {
        if(matrix == target) return 1;
        return rotate(matrix, target) || rotate(matrix, target) || rotate(matrix, target) ;
    }
};
```
