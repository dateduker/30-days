https://www.interviewbit.com/problems/implement-power-function/
```
int Solution::pow(int x, int n, int d) 
{
    x=x%d;
    if(x==0) return 0;
    
    int res=1;
   
    while(n>0)
    {
        if(n &1)
        res=(res*x)%d;
        x=(x*x)%d;
        n=n>>1;
    }
    if(res<0)
    {
        res=abs(res)%d;
        return d-res;
    }

	return res; 
}
```
