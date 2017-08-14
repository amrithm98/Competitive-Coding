#include<iostream>
#include<string>
#include<sstream>
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high- 1; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int findMax(int a[],int n,int max,int nth)
{
    int i;
    int max_here=0;
    quickSort(a,0,n-1);
    // for(i=0;i<5;i++)
    //     std::cout<<a[i]<<"\t";
    if(max==-1)
        return a[4];
    for(i=n-1;i>=0;i--)
    {
        if(a[i]<max)
        {
            nth--;
            if(nth==-1)
            {
                max_here=a[i];
                break;
            }
        }
    }
    return max_here;
}


int main()
{
    int n,i,j;
    std::string line;
    std::cin>>n;
    int **arr=new int*[n];
    for(int i=0;i<n;i++)
        arr[i]=new int[5];
    for(int i=0;i<n;i++)
    {
        std::cin>>line;
        std::istringstream is(line);
        std::string number_as_string;
        int j=0;
        while(std::getline(is,number_as_string,',')){
            arr[i][j]=std::stoi(number_as_string);
            j++;
        }
    }
    int startMax=findMax(arr[n-1],5,-1,0);
    std::cout<<startMax<<"\n";
    long sum=startMax;
    for(i=n-2;i>=0;i--)
    {
        int m=0;
        int currentMax=findMax(arr[i],5,startMax,m);
        if(currentMax==0)
        {
            sum-=startMax;
            i++;
            currentMax=findMax(arr[i],5,startMax,++m);
        }
        std::cout<<currentMax<<"\n";
        sum+=currentMax;
        startMax=currentMax;
    }
    std::cout<<sum;
    return 0;
}