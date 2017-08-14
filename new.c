#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    scanf("%d",&n);
    int grade[n],d,diff,i;
    for(int i = 0; i < n; i++){
        scanf("%d",&grade[i]);
        if(grade[i]>=38){
            d=(grade[i]/5)+1;
            diff=grade[i]-5*d;
	    if(diff<0)
		diff*=-1;
	    if(diff<3)
		grade[i]+=diff;
        }
    }
    for(i=0;i<n;i++)
		printf("\n%d",grade[i]);
    return 0;
}

