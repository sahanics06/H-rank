/*
Given a string, s, consisting of alphabets and digits, find the frequency of each digit in the given string.

Input Format
The first line contains a string,  which is the given number.

Constraints
1<= len(num) <=1000

All the elements of num are made of english alphabets and digits.

Output Format
Print ten space-separated integers in a single line denoting the frequency of each digit from 0 to 9.

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int arr[10]={0},t,c=0,j=0;    
    char s[1001];
    scanf("%s",s);
     for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
        arr[(int)(s[i]-'0')]++;
        }
    }
    
    while(c<10){
        printf("%d  ",arr[c]);
        c++;
    }
    return 0;
}

/*
Sample Input

1v88886l256338ar0ekk

Sample Output 

1 1 1 2 0 1 2 0 5 0 

*/
