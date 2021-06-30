#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
    int c=0,d=0,e=0,f=0,g=0,h=0;
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            c=i&j;
            if(c>d && c<k)
                d=c;
            e=i|j;
            if(e>f && e<k)
                f=e;
            g=i^j;
            if(g>h && g<k)
                h=g;
        }
    }
    printf("%d",d);
    printf("\n%d",f);
    printf("\n%d",h);

}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}