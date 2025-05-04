#include <iostream>
using namespace std;

class Node
{
	public:
		int Data;
		Node* next;
		Node(int d)
		{
			Data = d;
			next = NULL;
		}
};

class Queue
{
	Node* head;
	Node* tail;
	
	public:
		Queue()
		{
			head = tail = NULL;
		}
		
		bool empty()
		{
			
        return head == NULL;
        
		}
		
		void push(int x)
		{
			Node* newNode = new Node(x);
			
			if(empty())
			{
				head = tail = newNode;
			} else {
				tail->next = newNode;
				tail = newNode; 
			}
			
		}
		
		void pop()
		{
			if(empty()){
				cout << "Linked List is empty!\n";
				return;
			}
			
			Node* temp = head;
			head = head->next;
			delete temp;
			
		}
		
		void Display()
		{
			if(empty())
			{
				cout << "Empty Linked List\n";
				return;
			}
			
			Node* temp = head;
			cout << "Queue elements are: ";
			while(temp != NULL)
			{
				cout << temp->Data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
};

int main(){
	
	Queue Q;
	
	Q.push(10);
	Q.push(20);
	Q.push(30);
	Q.push(40);
	
	Q.Display();
	
	Q.pop();
	Q.pop();
	
	Q.Display();
	
	Q.pop();
	Q.pop();
	
	cout << "\nAfter removing all the elements from the queue linked list will be empty!\n\n";
	Q.Display();

	return 0;
}
