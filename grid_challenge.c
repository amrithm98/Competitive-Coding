#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,i=0;
    scanf("%d",&n);
    char array[100][100]; 
    for(i=0;i<n;i++)
        scanf("%s",&array[i]);
    for(i=0;i<n;i++)
        sort(array[i],array[i]+n);
    return 0;
}
