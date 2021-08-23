#### Using stack
T: O(nlogn)
S: O(n)
```
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        stack< pair<int,int> > s;
        int n = intervals.size();
        
        sort(intervals.begin(),intervals.end());
        
        for(int i = 0; i< n; i++){
            if(!s.empty() && s.top().second >= intervals[i][0] ){
                pair<int,int> tp = s.top();
                s.pop();
                s.push({tp.first,max(intervals[i][1], tp.second)});
            }
            else
            s.push({intervals[i][0], intervals[i][1]});
        }
        
        n = s.size();
        vector<vector<int>> res(n,vector<int>(2,0));
        
        for(int i = n-1; i >= 0; i--){
            res[i][0] = s.top().first;
            res[i][1] = s.top().second;
            s.pop();
        }
        
        return res;
    }
```

#### Without extra space
```
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> res;
        
        sort(intervals.begin(), intervals.end());
        
        int ind = 0;
        
        for(int i = 1; i < n; i++){
            if(intervals[i][0] <= intervals[ind][1] ){
                intervals[ind][0] = min(intervals[ind][0], intervals[i][0]);
                intervals[ind][1] = max(intervals[ind][1], intervals[i][1]);
            }
            else{
                ind++;
                intervals[ind][0] = intervals[i][0];
                intervals[ind][1] = intervals[i][1];
            }
        }
        
        for(int i = 0; i <= ind; i++)
        {
            vector<int> tmp(2);
            tmp[0] = intervals[i][0];
            tmp[1] = intervals[i][1];
            res.push_back(tmp);
        }
        
        return res;
    }
```
