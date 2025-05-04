#include <iostream>
using namespace std;

#define n 20
class Queue
{
	int* arr;
	int front, rear;
	
	public:
		
	Queue(){
		arr = new int[n];
		front = rear = -1;
	}
	
	void push(int x)
	{
		if(rear == n-1){
			cout << "Queue overflow!\n";
			return;
		}
		
		rear++;
		arr[rear] = x;
		
		if(front == -1)
			front++;
	}
	
	void pop()
	{
		if(front == -1 || front>rear){
			cout << "Empty Queue!\n";
			return;
		}
		
		front++;
	}
	
	void display() {
        if(front == -1 || front > rear) {
            cout << "Queue is empty!\n";
            return;
        }
        
        cout << "Queue elements: ";
        for(int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
	
};

int main()
{
	Queue Q;
	
	Q.push(10);
	Q.push(20);
	Q.push(30);
	Q.display();
	
	Q.pop();
	Q.pop();
	Q.display();
	Q.pop();
	Q.pop();
	
	

	return 0;
}
