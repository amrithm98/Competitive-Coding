#include <vector>

/*******************
* Main function - 
*
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
**************************/


class PriorityQueue {
	vector<int> pq;

	public :

	PriorityQueue() {

	}

	bool isEmpty() {
		return pq.size() == 0;
	}

	// Return the size of priorityQueue - no of elements present
	int getSize() {
		return pq.size();
	}

	int getMin() {
		if(isEmpty()) {
			return 0;		// Priority Queue is empty
		}
		return pq[0];
	}

	void insert(int element) {
		pq.push_back(element);
		
		int childIndex = pq.size() - 1;

		while(childIndex > 0) {
			int parentIndex = (childIndex - 1) / 2;

			if(pq[childIndex] < pq[parentIndex]) {
				int temp = pq[childIndex];
				pq[childIndex] = pq[parentIndex];
				pq[parentIndex] = temp;
			}
			else {
				break;
			}
			childIndex = parentIndex;
		}

	}

    int removeMin() {
        // Complete this function
        int top = pq[0];
      	swap(pq[0],pq[pq.size()-1]);
      	pq.pop_back();
      	minHeapify(0);
      	return top;
    }
  
  	void minHeapify(int index)
    {
      	int left = 2*index+1;
      	int right = 2*index+2;
      	int smallest;
      	if(left < pq.size() && pq[index] > pq[left])
          	smallest = left;
      	else
          	smallest = index;
      
      	if(right < pq.size() && pq[smallest] > pq[right])
          	smallest = right;
      
      	if(smallest != index)
        {
          	swap(pq[smallest],pq[index]);
          	minHeapify(smallest);
        }
    }

};
