#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int main() {
    int q; 
    scanf("%d", &q);
    for(int a0 = 0; a0 < q; a0++){
        long int  n,i,j;
        int temp,flag=0;
        scanf("%ld", &n);
        int *a = malloc(sizeof(int) * n);
        int *t = malloc(sizeof(int) * n);
        for(i = 0;i < n;i++){
           scanf("%d",&a[i]);
            t[i]=a[i];
        }
        for(i=0;i<n;i++)
        {
               if(((a[i]-a[i+1])==1) || ((a[i]-a[i+1])==-1))
               {
                   for(j=0;j<n-1;j++)
                   {
                       if(a[j]>a[j+1])
                       {
                            temp=a[j];
                            a[j]=a[j+1];
                            a[j+1]=temp;
                       }
                       
                    }
                }
        }
        // printf("Test:");
        // for(i=0;i<n;i++)
        //     printf("%d\t",a[i]);
        for(i=0;i<n;i++)
        {
                   for(j=0;j<n-1;j++)
                   {
                       if(t[j]>t[j+1])
                       {
                           temp=t[j];
                           t[j]=t[j+1];
                           t[j+1]=temp;
                       }
                    }
        }
        // printf("Sorted:");
        // for(i=0;i<n;i++)
        //     printf("%d\t",t[i]);
        for(i=0;i<n;i++)
        {
            if(a[i]!=t[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
