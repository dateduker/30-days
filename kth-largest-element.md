Map or heap can be used
#### Using quick select
```
class Solution {
public:
    int partition(vector<int>& a, int l, int r ){
        int pivot = a[r];
        int pI = l;
        for(int i = l; i < r; i++){
            if(a[i] <= pivot){
                swap(a[pI], a[i]);
                pI++;
            }
        }
        swap(a[pI], a[r]);
        
        return pI;
    }
    int qs(vector<int>& a, int l, int r, int k){
        
        if(l <= k && k <= r){
            
            int pI = partition(a, l, r);
            
            if(k == pI) return a[pI];
            if(pI < k)
                return qs(a, pI+1, r, k);
            return qs(a, l, pI-1, k);              
                
        }
        return -1;        
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int r = qs(nums, 0, n-1, n - k );
        return r;
    }
};
```
