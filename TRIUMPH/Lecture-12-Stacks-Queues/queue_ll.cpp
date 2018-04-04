#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
    public:
    T data;
    Node *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

template<typename T>
class Queue {
    
    Node<T> *head,*rear;
  	int size;
    public :
    
    
    Queue() {
        head = NULL;
      	rear = NULL;
      	size = 0;
    }
    
    void enqueue(T data) {
        if(head == NULL)
        {
          	head = new Node<T>(data);
          	rear = head;	
        }	
      	else
        {
          	Node<T> *node = new Node<T>(data);
          	rear->next = node;
          	rear = node;
        }
      	size++;
    }
    
    int getSize() {
        	return size;
    }
    
    bool isEmpty() {
        	return size == 0;
    }	
    
    T dequeue() {
        // Return 0 if queue is empty
      	if(head != NULL)
        {
          size--;
          Node<T> *temp = head;
          head = head->next;
          T val = temp->data;
          free(temp);
          return val;
        }
      	else if(head == rear)
        {
          	rear = NULL;
        }
       	return 0;
    }
    
    T front()  {
        // Return 0 if queue is empty
      	if(head)
          	return head->data;
      	else
          	return 0;
    }
};

int main()
{
    Queue<int> q;
    q.enqueue(10);
    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    return 0;
}
