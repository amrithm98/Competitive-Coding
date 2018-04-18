//Note than i < n/2 is important

bool checkMaxHeap(int arr[], int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Taking input and printing output is handled automatically.
     */
  	for(int i = 0; i < n/2; i++)
    {
      	if((2*i+1) < n && arr[i] < arr[2*i+1] || arr[i] < arr[2*i+2])
          return false;
    }
  
  	return true;
}
