    #include <iostream>
    #include <stdio.h>
    #include <stdlib.h>
    #include<algorithm>
    #include<unordered_map>
    using namespace std;
    void mostFreq3(int *a, int n, int b[3]) {

        int i=0,j=0;
        for(i=0;i<n-1;i++)
        {
            for(j=0;j<n-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    int temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
        int max_block=-1;
        int count=0,max_elem3=0;
        for(i=0;i<n-1;i++)
        {
            if(a[i]==a[i+1])
            {
                count+=1;
                max_elem3=a[i];
            }
            if(count>max_block)
                count=max_block;
        }
        b[0]=max_elem3;
        max_block=-1;
        count=0;
        int max_elem2=0;
        for(i=0;i<n-1;i++)
        {
            if(a[i]==a[i+1] && a[i]!=max_elem3)
            {
                count+=1;
                max_elem2=a[i];
            }   
            if(count>max_block)
                count=max_block;
        }
        b[1]=max_elem2;
        max_block=-1;
        count=0;
        int max_elem1=0;
        for(i=0;i<n-1;i++)
        {
            if((a[i]|| a[i+1] || a[i]==a[i+1]) && a[i]!=max_elem3 && a[i]!=max_elem2)
            {
                count+=1;
                max_elem1=a[i];
            }
            if(count>max_block)
                count=max_block;
        }
        b[2]=max_elem1;

    }
    int main()
    {
        int n;
        int a[100];
        int b[3];
        int i=0;
        cin >> n;
        for(i=0;i<n;i++){
            cin >> a[i];
        }

        mostFreq3(a,n,b);
        for(i=0; i<3; i++)
            cout << b[i] << " ";
        return 0;
    }