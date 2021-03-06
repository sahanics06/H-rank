/*
Array Reversal
Given an array, of size n , reverse it.

Example: If array, arr = [1,2,3,4,5],after reversing it, the array should be, arr= [5,4,3,2,1].
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, t=0, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }
    
    for(i=0;i<num/2;i++)
    {   
        *(arr+i)= *(arr+i)+ *(arr+num-i-1);
        *(arr+num-i-1)=*(arr+i)- *(arr+ num-i-1);
        *(arr+i)=*(arr+i)- *(arr+ num-i-1);
    }
    

    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}

/*
Output:

Sample Input 
6
16 13 7 2 1 12

Sample Output 
12 1 2 7 13 16 

*/