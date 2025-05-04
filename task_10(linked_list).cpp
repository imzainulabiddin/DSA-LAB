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

class Stack
{
	Node* top;
	public:
		Stack()
		{
			top = NULL;
		}
		
		void push(int x)
		{
			Node* newNode = new Node(x);
			newNode->next = top;
			top = newNode;
		}
		
		void pop()
		{
			if(top == NULL)
			{
				cout << "stack not exist!\n";
				return;
			}
			
			Node* temp = top;
			top = top->next;
			delete temp;
		}
		
		void Display()
		{
		
		Node* temp = top;
		cout << "Stack elements: ";
		while(temp != NULL)
		{
			cout << temp->Data << " ";
			temp = temp->next;
		}
		cout << endl;
		
		}
};
int main(){
	
	Stack S;
	
	S.push(10);
	S.push(20);
	S.push(30);
	
	S.Display();
	
	S.pop();
	
	S.Display();
	
	S.pop();
	S.pop();
	S.pop();

	return 0;
}
