#include <bits/stdc++.h>
using namespace std;

void findMedian(int arr[], int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output as specified in the question.
     */
	priority_queue<int> max_heap_left;
 	priority_queue<int,vector<int>,greater<int>> min_heap_right;
  	
  	int median = 0;
  	
  	for(int i = 0; i < n; i++)
    {
      	int x = arr[i];
      
      	if(max_heap_left.size() > min_heap_right.size())
        {
          	if(x >= median)
            {
              	min_heap_right.push(x);
              	//Now both heaps are balanced
            }
          	else
            {
              	//Pop one element from left and push in right
              	min_heap_right.push(max_heap_left.top());
              	max_heap_left.pop();
              	max_heap_left.push(x);
            }
          
          	median = (max_heap_left.top() + min_heap_right.top())/2;
        }
      
      	else if(max_heap_left.size() < min_heap_right.size())
        {
          	if(x > median)
            {
              	max_heap_left.push(min_heap_right.top());
              	min_heap_right.pop();
              	min_heap_right.push(x);
            }
          	else
            {
              	max_heap_left.push(x);
            }
          	median = (max_heap_left.top() + min_heap_right.top())/2;
        }
      
      	else  
        {
          	if(x < median)
            {
              	max_heap_left.push(x);
              	median = max_heap_left.top();
            }
          	else
            {
              	min_heap_right.push(x);
              	median = min_heap_right.top();
            }
        }
      
      	cout << median << endl;
    }
}