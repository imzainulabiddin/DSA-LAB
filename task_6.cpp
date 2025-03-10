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
        void insert(int val, int pos)
		{
			if(pos<0)
			{
				cerr << "Invalid pos\n";
				return;
			}
			if(pos == 0)
			{
				push_front(val);
				return;
			}
			Node* temp = head;
			for(int i = 0; i<pos-1; i++)
			{
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
        
        // Display the first node
        void displayFirst() 
		{
            if (head)
                cout << "First Node: " << head->data << endl;
        }

        // Display the last node
        void displayLast() 
		{
            if (!head) return;
            Node* temp = head;
            while(temp->next) 
			{
                temp = temp->next;
            }
            cout << "Last Node: " << temp->data << endl;
        }

        // Display the Nth node (0-based index)
        void displayNth(int n) 
		{
            Node* temp = head;
            int count = 0;
            while(temp) 
			{
                if(count == n) 
				{
                    cout << "Nth Node (" << n << "): " << temp->data << endl;
                    return;
                }
                temp = temp->next;
                count++;
            }
            cout << "Invalid position!" << endl;
        }

        // Display the center node
        void displayCenter() 
		{
            if(!head) return;
            Node* slow = head;
            Node* fast = head;
            while(fast && fast->next) 
			{
                slow = slow->next;
                fast = fast->next->next;
            }
            cout << "Center Node: " << slow->data << endl;
        }

        // Delete first node
        void deleteFirst() {
            if (!head) return;
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        // Delete last node
        void deleteLast() {
            if (!head) return;
            if (!head->next) {
                delete head;
                head = nullptr;
                return;
            }
            Node* temp = head;
            while (temp->next->next) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }

        // Delete Nth node
        void deleteNth(int position) {
            if (!head || position < 0) return;
            if (position == 0) {
                deleteFirst();
                return;
            }
            Node* temp = head;
            for (int i = 0; temp && i < position - 1; i++) {
                temp = temp->next;
            }
            if (!temp || !temp->next) return;
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }

        // Delete center node
        void deleteCenter() {
            if (!head || !head->next) {
                deleteFirst();
                return;
            }
            Node* slow = head;
            Node* fast = head;
            Node* prev = nullptr;
            while (fast && fast->next) {
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            if (prev) {
                prev->next = slow->next;
            }
            delete slow;
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

    ll.displayFirst();
    ll.displayLast();
    ll.displayNth(4); // Display 4th index node
    ll.displayCenter();

    ll.deleteFirst();
    cout << "After deleting first node: ";
    ll.DisplayLL();

    ll.deleteLast();
    cout << "After deleting last node: ";
    ll.DisplayLL();

    ll.deleteNth(2);
    cout << "After deleting 2nd node: ";
    ll.DisplayLL();

    ll.deleteCenter();
    cout << "After deleting center node: ";
    ll.DisplayLL();

    return 0;
}
