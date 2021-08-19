/*
Method 1 
    Approach:The problem is similar to our old post Segregate 0s and 1s in an array, and both of these problems are variation of famous Dutch national flag problem.
    The problem was posed with three colours, here `0′, `1′ and `2′. The array is divided into four sections: 
        a[1..Lo-1] zeroes (red)
        a[Lo..Mid-1] ones (white)
        a[Mid..Hi] unknown
        a[Hi+1..N] twos (blue)
        If the ith element is 0 then swap the element to the low range, thus shrinking the unknown range.
        Similarly, if the element is 1 then keep it as it is but shrink the unknown range.
        If the element is 2 then swap it with an element in high range.
    Algorithm: 
        Keep three indices low = 1, mid = 1 and high = N and there are four ranges, 1 to low (the range containing 0), low to mid (the range containing 1), mid to high (the range containing unknown elements) and high to N (the range containing 2).
        Traverse the array from start to end and mid is less than high. (Loop counter is i)
        If the element is 0 then swap the element with the element at index low and update low = low + 1 and mid = mid + 1
        If the element is 1 then update mid = mid + 1
        If the element is 2 then swap the element with the element at index high and update high = high – 1 and update i = i – 1. As the swapped element is not processed
        Print the output array.
        
        0 0 0 1 1 1 1 1 ? ? ? ? ? ? ? 2 2 2
              l         m           h
 */
 void sort012(int a[], int arr_size)
{
    int lo = 0;
    int hi = arr_size - 1;
    int mid = 0;

    while (mid <= hi) {
        switch (a[mid]) {
         case 0:
            swap(a[lo++], a[mid++]);
            break;
         case 1:
            mid++;
            break;
         case 2:
            swap(a[mid], a[hi--]);
            break;
        }
    }
}
