```
1. Sort the input array. 
   Traverse the array and check for missing and repeating.
   Time Complexity: O(nLogn)
```

```
2. Approach: 

    Create a temp array temp[] of size n with all initial values as 0.
    Traverse the input array arr[], and do following for each arr[i] 
        if(temp[arr[i]] == 0) temp[arr[i]] = 1;
        if(temp[arr[i]] == 1) output “arr[i]” //repeating
    Traverse temp[] and output the array element having value as 0 (This is the missing element)

Time Complexity: O(n)
Auxiliary Space: O(n)
```

```
 3 (Use elements as Index and mark the visited places)
Time Complexity: O(n)

void printTwoElements(int arr[], int size)
{
    int i;
    cout << " The repeating element is ";
 
    for (i = 0; i < size; i++) {
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else
            cout << abs(arr[i]) << "\n";
    }
 
    cout << "and the missing element is ";
    for (i = 0; i < size; i++) {
        if (arr[i] > 0)
            cout << (i + 1);
    }
}
```

```
4.
Missing - 7, Repeating - 5
x, y
N = {1, 2, 3, 4, 5, 6, 7}
a = {1, 2, 3, 4, 5, 5, 6}

-> xor of above two arrays gives xor of required numbers = xor1 [010]
-> set bits in xor1 are caused by set bits in either x or y
-> Finding set bit from right in xor1, xor1 = ~(xor1 - 1) [10]
 e.g., 101100 -> 100
 -> Split above arrays in to sets  using right-set-bit
 -> 2, 3, 6, 7 | 1, 4, 5 
 -> 2, 3, 6    | 1, 4, 5, 5
-> xor of two sets separately is 7, 5


void getTwoElements(int arr[], int n) 
{
    /* Will hold xor of all elements
    and numbers from 1 to n */
    
    int xor1;
    int x = 0, y = 0;
 
    /* Will have only single set bit of xor1 */
    int set_bit_no;
 
    int i;
 
    xor1 = arr[0];
 
    /* Get the xor of all array elements */
    for (i = 1; i < n; i++)
        xor1 = xor1 ^ arr[i];
 
    /* XOR the previous result with numbers
    from 1 to n*/
    for (i = 1; i <= n; i++)
        xor1 = xor1 ^ i;
 
  
    /* Get the rightmost set bit in set_bit_no */
    set_bit_no = xor1 & ~(xor1 - 1);
 
    /* Now divide elements into two sets by comparing a rightmost set bit of xor1 with the bit at the same position in each element. 
    Also, get XORs of two sets. The two XORs are the output elements. The following two for loops serve the purpose */
  
    for (i = 0; i < n; i++) {
        if (arr[i] & set_bit_no)
            /* arr[i] belongs to first set */
            x = x ^ arr[i];
 
        else
            /* arr[i] belongs to second set*/
            y = y ^ arr[i];
    }
    for (i = 1; i <= n; i++) {
        if (i & set_bit_no)
            /* i belongs to first set */
            x = x ^ i;
 
        else
            /* i belongs to second set*/
            y = y ^ i;
    }
 
    /* *x and *y hold the desired
        output elements */
}
```

```
5. Use Map
```

```
Method 7 (Make two equations using sum and sum of squares)
Approach:

    Let x be the missing and y be the repeating element.
    Let N is the size of array.
    Get the sum of all numbers using formula S = N(N+1)/2
    Get the sum of square of all numbers using formula Sum_Sq = N(N+1)(2N+1)/6
    Iterate through a loop from i=1….N
    S -= A[i]
    Sum_Sq -= (A[i]*A[i])
    It will give two equations 
    x-y = S – (1) 
    x^2 – y^2 = Sum_sq 
    x+ y = (Sum_sq/S) – (2) 
     

Time Complexity: O(n) 
```
