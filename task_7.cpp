#include <iostream>
using namespace std;

class Node
{
    public:
        int Data;
        Node* Next;
        Node* Prev;
    Node(int Val)
    {
        Data = Val;
        Next = Prev = NULL;
    }
};

class List
{
    Node* Head;
    Node* Tail;
    
    public:
        List()
        {
            Head = Tail = NULL;
        }
        
        void push_front(int Val)
        {
            Node* NewNode = new Node(Val);
            
            if(Head == NULL)
            {
                Head = Tail = NewNode;  
            }
            else
            {
                NewNode->Next = Head;
                Head->Prev = NewNode;
                Head = NewNode;
            }
        }
        
        void push_back(int Val)
        {
            Node* NewNode = new Node(Val);
            
            if(Head == NULL)
            {
                Head = Tail = NewNode;
            }
            else
            {
                Tail->Next = NewNode;
                NewNode->Prev = Tail;
                Tail = NewNode;
            }
        }
        
        // Function to insert at any position
        void insert(int Val, int Pos)
        {
            if(Pos < 0)
            {
                cerr << "Invalid position\n";
                return;
            }
            if(Pos == 0)
            {
                push_front(Val);
                return;
            }
            Node* Temp = Head;
            for(int i = 0; i < Pos - 1; i++)
            {
                Temp = Temp->Next;
            }
            Node* NewNode = new Node(Val);
            NewNode->Next = Temp->Next;
            NewNode->Prev = Temp;
            if (Temp->Next)
                Temp->Next->Prev = NewNode;
            Temp->Next = NewNode;
        }
        
        // Insert at center
        void insertCenter(int Val)
        {
            if (!Head)
            {
                push_front(Val);
                return;
            }
            Node* Slow = Head;
            Node* Fast = Head;
            while(Fast && Fast->Next)
            {
                Slow = Slow->Next;
                Fast = Fast->Next->Next;
            }
            Node* NewNode = new Node(Val);
            NewNode->Next = Slow->Next;
            NewNode->Prev = Slow;
            if(Slow->Next)
                Slow->Next->Prev = NewNode;
            Slow->Next = NewNode;
        }
        
        void displayForward()
        {
            Node* Temp = Head;
            while(Temp != NULL)
            {
                cout << Temp->Data << "->";
                Temp = Temp->Next;
            }
            cout << "NULL" << endl;
        }
        
        void displayReverse()
        {
            Node* Temp = Tail;
            while(Temp != NULL)
            {
                cout << Temp->Data << "->";
                Temp = Temp->Prev;
            }
            cout << "NULL" << endl;
        }
};

int main()
{
    List dll;
    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);
    
    dll.displayForward();
    
    dll.push_back(4);
    dll.displayForward();
    
    dll.insert(5, 0);
    dll.displayForward();
    
    dll.insertCenter(6);
    cout << "After inserting at center: ";
    dll.displayForward();
    
    cout << "Display in reverse order: ";
    dll.displayReverse();
    
    return 0;
}