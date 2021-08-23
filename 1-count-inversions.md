#### [Leetcode](https://leetcode.com/problems/global-and-local-inversions/)
```
bool isIdealPermutation(vector<int>& a) {
        int n = a.size();
        int tmp = INT_MIN;
        for(int i = 0; i < n-2; i++){
           tmp = max(tmp, a[i]);
            if(tmp > a[i+2]) return false;
        }
        return 1;
    }
---------------------------------------------------------
#define ll size_t
class Solution {
public:
    int local = 0;
    bool todo = 1;
    ll merge(vector<int> &a, int l, int mid, int r, vector<int> &tmp){
        if(todo == 0) return 0;
        int i = l;
        int j = mid;
        int k = l;
        ll count = 0;
        
        while( i < mid && j <= r){
            if(a[i] <= a[j])
                tmp[k++] = a[i++];
            else{
                tmp[k++] = a[j++];
                count += (mid - i); 
            }
        }
        while(i < mid) tmp[k++] = a[i++];
        while(j <= r) tmp[k++] = a[j++];
        
        for(int i = l, k = l; i <= r; i++)
            a[i] = tmp[k++];
        
        if(count > local) todo = 0;
        return count;
    }
    int mergesort(vector<int> &a, int l, int r, vector<int> &tmp){
        if(l < r && todo){
            ll count = 0;
            int mid = l + (r-l)/2;
            count += mergesort(a, l, mid, tmp);
            count += mergesort(a, mid+1, r, tmp);
            count += merge(a, l, mid+1, r, tmp);
            if(count > local) todo = 0;
            return count;
        }
        return 0;
    }
    bool isIdealPermutation(vector<int>& a) {
        int n = a.size();
        if(n == 1) return 1;
        vector<int> tmp(n,0);
        local = 0;
        todo = 1;   
        for(int i = 0; i < n-1; i++)
            if(a[i] > a[i+1]) local++;
        int k = mergesort(a, 0, n-1, tmp);
        return todo == 1 && local == k ;
    }
};
```

#### [Interviewbit](https://www.interviewbit.com/problems/inversions/)
```

#define ll size_t

    ll merge(vector<int> &a, int l, int mid, int r, vector<int> &tmp){
        int i = l;
        int j = mid;
        int k = l;
        ll count = 0;
        
        while( i < mid && j <= r){
            if(a[i] <= a[j])
                tmp[k++] = a[i++];
            else{
                tmp[k++] = a[j++];
                count += (mid - i); 
            }
        }
        while(i < mid) tmp[k++] = a[i++];
        while(j <= r) tmp[k++] = a[j++];
        
        for(int i = l, k = l; i <= r; i++)
            a[i] = tmp[k++];
        
        return count;
    }
    int mergesort(vector<int> &a, int l, int r, vector<int> &tmp){
        if(l < r ){
            ll count = 0;
            int mid = l + (r-l)/2;
            count += mergesort(a, l, mid, tmp);
            count += mergesort(a, mid+1, r, tmp);
            count += merge(a, l, mid+1, r, tmp);
            return count;
        }
        return 0;
    }
    int Solution::countInversions(vector<int> &a) {
        int n = a.size();
        if(n == 1) return 0;
        vector<int> tmp(n,0);
        int k = mergesort(a, 0, n-1, tmp);
        return  k ;
    }

```
