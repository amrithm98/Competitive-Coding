#include <bits/stdc++.h>
using namespace std;

class PriorityQueue {
    // Complete this class
    vector<int> pq;
    public:
    PriorityQueue()
    {
        
    }
    int getSize()
    {
        return pq.size();
    }
    bool isEmpty()
    {
        return pq.size() == 0;
    }
    int getMax()
    {
        if(isEmpty())
            return INT_MAX;
        else
            return pq[0];
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

    int removeMax() {
        // Complete this function
        if(isEmpty())
            return INT_MAX;

        int top = pq[0];
      	swap(pq[0],pq[pq.size()-1]);
      	pq.pop_back();
      	downHeapify(0);
      	return top;
    }
  
  	void downHeapify(int index)
    {
      	int left = 2*index+1;
      	int right = 2*index+2;
      	int largest;
      	if(left < pq.size() && pq[index] < pq[left])
          	largest = left;
      	else
          	largest = index;
      
      	if(right < pq.size() && pq[largest] < pq[right])
          	largest = right;
      
      	if(largest != index)
        {
          	swap(pq[largest],pq[index]);
          	downHeapify(largest);
        }
    }
};

int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;
    while(choice != -1) {
        switch(choice) {
            case 1 : // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2 : // getMax
                cout << pq.getMax() << endl;
                break;
            case 3 : // removeMax
                cout << pq.removeMax() << endl;
                break;
            case 4 : // size
                cout << pq.getSize() << endl;
                break;
            case 5 : // isEmpty
                if(pq.isEmpty()) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
            default :
                return 0;
        }
        cin >> choice;
    }

}