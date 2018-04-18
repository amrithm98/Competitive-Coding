#include <bits/stdc++.h>
using namespace std;

class PriorityQueue {
    // Complete this class
    public:
    vector<int> pq;
    PriorityQueue()
    {
        
    }

    void insert(int data)
    {
        pq.push_back(data);
        max_heapify(pq.size()-1);
    }

    void max_heapify(int index)
    {
        int parent = (index-1)/2;
        int largest = index;
        if(parent >= 0 && pq[parent] < pq[index])
        {   
            largest = parent;
        }
        else
            largest = index;

        if(largest != index)
        {
            swap(pq[index],pq[largest]);
            max_heapify(parent);
        }
    }
  
  	void downHeapify(int index,int size)
    {
      	int left = 2*index+1;
      	int right = 2*index+2;
      	int largest;
      	if(left < size && pq[index] < pq[left])
          	largest = left;
      	else
          	largest = index;
      
      	if(right < size && pq[largest] < pq[right])
          	largest = right;
      
      	if(largest != index)
        {
          	swap(pq[largest],pq[index]);
          	downHeapify(largest,size);
        }
    }
  
  	void heapSort(int input[],int n)
    {
      	for(int i = 0; i < n; i++)
      		insert(input[i]);
        
      	int size = pq.size();
      	while(size > 0)
        {
          	int currMax = pq[0];
            swap(pq[0],pq[size-1]);
          	size--;
            downHeapify(0,size);
        }
      
      	for(int i = 0; i < n; i++)
        {
          	input[i] = pq[n-i-1];
        }
    }
};

void inplaceHeapSort(int input[], int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Change in the given input itself.
     * Taking input and printing output is handled automatically.
     */
  	PriorityQueue pq;
  	pq.heapSort(input,n);

}
