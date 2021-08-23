https://leetcode.com/problems/merge-sorted-array/
```
1. 
Create extra space m+n and merge
Refill the given arrays using auxillary array
```

[Youtube](https://www.youtube.com/watch?v=hVl2b3bLzBw&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=5)

#### Using insertion
T: O(mn)
S: O(1)
```
class Solution {
public:
    void insert(vector<int>& a, int n){
        int i = 0;
        while(i+1<n && a[i] > a[i+1]){
            swap(a[i],a[i+1]);
            i++;
        }
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return;      
        for(int i = 0; i < m; i++){
            if(  nums1[i] <= nums2[0]){
               continue;
            }
            swap(nums1[i], nums2[0]);
            insert(nums2, n);
        }
        //section specified to leetcode input
        //for(int i = m, k = 0; i < nums1.size() && k<n;  )
        //    nums1[i++] = nums2[k++];
    }
    
}; 
```

#### Using gap
T: O(nlogn)
```
class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        if(n == 0) return;
        int gap = ceil((m+n)/2.0);
        int i;
        int j;
        while(gap > 0){
            i = 0;
            for(; i + gap < m; i++){
                if(a[i]>a[i+gap])
                    swap(a[i], a[i+gap]);
            }
            
            j = i+gap-m;
            for(; i < m && j < n; i++, j++){
                if(a[i] > b[j])
                    swap(a[i], b[j]);
            }
            
            if(j<n){
                for(i = 0; i+gap < n;  i++){
                    if(b[i]>b[i+gap])
                        swap(b[i], b[i+gap]);
                }
            }
            

            if(gap == 1) break;
            else gap = ceil(gap/2.0);
            
        }
        // section specified to leetcode input
        // for(int k = 0,l=m; k < n; k++, l++)
        //     a[l] = b[k];
    }
};
```


#### T: O(m+n)
[GFG](https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/)

