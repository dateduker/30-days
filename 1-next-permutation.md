#### Short
```
void nextPermutation(vector<int>& a) {
        int n = a.size();
        int i = n-1;
        int j;
        while(i>0 && a[i-1] >= a[i]) 
            i--;
        
        if(i==0) {
            j = n-1;
            while(i<j) swap(a[i++], a[j--]);
            return;
        }
        
        for( j = n-1; j >=i; j--)
            if(a[j] > a[i-1]){
                swap(a[i-1], a[j]); 
                break;
            }
        j = n-1;

        while(i<j) swap(a[i++], a[j--]);
        
        
    }
```

#### [Interviewbit](https://www.interviewbit.com/problems/next-permutation/)
```
void rev(vector<int>& s, int l, int r) 
{ 
    while (l < r) 
        swap(s[l++], s[r--]); 
} 
  
int bsearch(vector<int>& s, int l, int r, int key) 
{ 
    int index = -1; 
    while (l <= r) 
    { 
        int mid = l + (r - l) / 2; 
        if (s[mid] <= key) 
            r = mid - 1; 
        else { 
            l = mid + 1; 
            if (index == -1 || s[index] >= s[mid]) 
                index = mid; 
        } 
    } 
    return index; 
} 
  
bool permutation(vector<int>& s) 
{ 
    int len = s.size(), i = len - 2; 
    while (i >= 0 && s[i] >= s[i + 1]) 
        --i; 
    if (i < 0) 
        return false; 
    else { 
        int index = bsearch(s, i + 1, len - 1, s[i]); 
        swap(s[i], s[index]); 
        rev(s, i + 1, len - 1); 
        return true; 
    } 
} 
vector<int> Solution::nextPermutation(vector<int> &A) 
{
    if(A.size()==0 || A.size()==1) return A;
    if(permutation(A)) return A;
    sort(A.begin(),A.end());
    return A;
}
```
