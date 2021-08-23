1. lineaar search whole matrix T: O(n^2)
2. Binary search in each row T: O(nlogm)
3. Binary search in last column to find the row and binary search in that row T: O(logn.logm)

https://leetcode.com/problems/search-a-2d-matrix-ii/
```
T: O(m+n)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        int i, j;
        i = 0; j = c-1;
        
        while(i < r && j >= 0){
            if(matrix[i][j] == target)
            return 1;
            if(matrix[i][j] < target)
            i++;
            else
            j--;
        }
        return 0;
    }
};
```

https://leetcode.com/problems/search-a-2d-matrix/

https://www.interviewbit.com/problems/matrix-search/
```
T: O(log(n+m)) 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size();
        int c = matrix[0].size();

        int h = r*c - 1; 
        while(l <= h){
            int mid = l + (h - l)/2;
            if( matrix[mid/c][mid%c] == target) return 1;
            if( matrix[mid/c][mid%c] < target)
            l = mid + 1;
            else
            h = mid - 1;
        }
        return 0;

    }
};
```
