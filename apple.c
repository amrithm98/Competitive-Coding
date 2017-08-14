#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    long long int s,t,a,b,m,n; 
    scanf("%lld %lld",&s,&t);
    scanf("%lld %lld",&a,&b);
    scanf("%lld %lld",&m,&n);
    long long int apple,orange,apple_count=0,orange_count=0;
    long long int i,dist=0;
    for(i = 0; i < m; i++){
       scanf("%lld",&apple);
       if(apple>=0)
        {
            dist=a+apple;
            if(dist>=s)
                apple_count+=1;
        }
    }
    for(i = 0; i < n; i++){
       scanf("%lld",&orange);
       if(orange<=0)
        {
            dist=b+orange;
            if(dist<=t)
                orange_count+=1;
        }
    }
    printf("%lld\n%lld",apple_count,orange_count);
    return 0;
}
    