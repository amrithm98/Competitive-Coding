#include <iostream>
using namespace std;

/*** Given an array B which is a rearrangement of array A by taking mid of A each time
 * and putting it into another array:
 * Eg: A - 1 2 3 4 5
 *     B - 3 2 4 1 5
 * Given B recover A
 * 
 * Odd and Even Cases. There is a pattern. In B,first element goes to input of output if n is odd. 
 * For the remaining elements , put mid-1 in left and mid+1 in right and so on
 * */

void recoverArray(int *input,int n,int *output)
{
    int i = 0;
    int mid = n/2;
    int left,right;

    if(n % 2 != 0)
    {
        output[mid] = input[i++];
        left = mid - 1;
        right = mid + 1;
    }
    else
    {
        left = mid - 1;
        right = mid;
    }

    while(i < n)
    {
        output[left] = input[i++];
        left--;
        output[right] = input[i++];
        right++;
    }

    cout << "\nOriginal Array: ";
    for(int i = 0; i < n; i++)
    {
        cout << output[i] << " ";
    }
}

int main()
{
    int n;
    cin >> n;

    int *input = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int *output = new int[n];
    recoverArray(input,n,output);

    return 0;
}