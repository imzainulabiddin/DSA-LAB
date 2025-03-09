#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
    Node* head;
    Node* tail;
    
    public:
        List()
        {
            head = tail = NULL;
        }
        
        void push_front(int val)
        {
            Node* newNode = new Node(val);
            
            if(head == NULL)
            {
                head = tail = newNode;  
            }
            else
            {
                newNode->next = head;
                head = newNode;
            }
        }
        
        void push_back(int val)
        {
            Node* newNode = new Node(val);
            
            if(head == NULL)
            {
                head = tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }
        
        //Function to insert at any position.
        void insert(int val, int pos){
				if(pos<0){
					cerr << "Invalid pos\n";
					return;
				}
				if(pos == 0){
					push_front(val);
					return;
				}
				Node* temp = head;
				for(int i = 0; i<pos-1; i++){
					temp = temp->next;
				}
				Node* newNode = new Node(val);
				newNode->next = temp->next;
				temp->next = newNode;
			}
        
        void DisplayLL()
        {
            Node* temp = head;
            while(temp != NULL)
            {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL" << endl; 
        }
};

int main()
{
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    
    ll.DisplayLL();
    
    ll.push_back(4);
    
    ll.DisplayLL();
    
    ll.insert(5, 0);
    ll.DisplayLL();

    return 0;
}
