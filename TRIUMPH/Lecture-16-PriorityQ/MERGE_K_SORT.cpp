#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> iPair;

/*****Approach is This

{{1,2,3},
{4,5,6},
{7,8,9}}

be the initial arrays

Push first 3 elements to heap
{1,4,7}

Now pop element one by one, and push element in the next index of the array of element just popped
See, 
pop 1 , 1 is in first array, so push 2 to heap (next element in first array)
{2,4,7}
pop 2, 2 is in the first array, so push 3 to heap
{3,4,7}
pop 3, 3 is in the first array , there's nothing to push
{4,7}
pop 4, 4 is in the 2nd array , push 5 to heap
{5,7}


etc.

REMEMBER TO KEEP INDEX OF ARRAY IN WHICH EACH ELEMENT BELONGS


*/

vector<int> mergeKSortedArrays(vector<vector<int>*> input){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return the output.
     * Taking input and printing output is handled automatically.
     */
	priority_queue<iPair,vector<iPair>,greater<iPair>> pq;
  	
  	int max_size = 0;
  	for(int i = 0; i < input.size(); i++)
    {
      	pq.push(make_pair(input[i]->at(0),i));
      	max_size = max(max_size,(int)input[i]->size());
    }
  
  	vector<int> ans;
  	vector<int> ptrs(input.size(),1);
  
  	int end_ptr = 0;
  
  	while(!pq.empty())
    {
      	for(int i = 0; i < input.size() && !pq.empty(); i++)
        {
          	iPair node = pq.top();
            pq.pop();
          	ans.push_back(node.first);
          	
            int index = node.second;
            if(ptrs[index] < input[index]->size())
            {
            	pq.push(make_pair(input[index]->at(ptrs[index]),index));
              	ptrs[index]++;
              	end_ptr = max(end_ptr,ptrs[index]);
            }
          	
        }
    }
  
  	return ans;
  	
}
