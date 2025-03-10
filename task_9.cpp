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

class CircularLinkedList
{
    Node* Head;
    
    public:
        CircularLinkedList()
        {
            Head = NULL;
        }
        
        void insertFirst(int Val)
        {
            Node* NewNode = new Node(Val);
            if(Head == NULL)
            {
                Head = NewNode;
                Head->Next = Head;
                Head->Prev = Head;
            }
            else
            {
                NewNode->Next = Head;
                NewNode->Prev = Head->Prev;
                Head->Prev->Next = NewNode;
                Head->Prev = NewNode;
                Head = NewNode;
            }
        }
        
        void insertLast(int Val)
        {
            if(Head == NULL)
            {
                insertFirst(Val);
                return;
            }
            Node* NewNode = new Node(Val);
            NewNode->Next = Head;
            NewNode->Prev = Head->Prev;
            Head->Prev->Next = NewNode;
            Head->Prev = NewNode;
        }
        
        void insertNth(int Val, int Pos)
        {
            if(Pos < 0)
            {
                cerr << "Invalid position\n";
                return;
            }
            if(Pos == 0)
            {
                insertFirst(Val);
                return;
            }
            Node* Temp = Head;
            for(int i = 0; i < Pos - 1; i++)
            {
                Temp = Temp->Next;
                if(Temp == Head) 
                {
                    cerr << "Position out of bounds\n";
                    return;
                }
            }
            Node* NewNode = new Node(Val);
            NewNode->Next = Temp->Next;
            NewNode->Prev = Temp;
            Temp->Next->Prev = NewNode;
            Temp->Next = NewNode;
        }
        
        void insertCenter(int Val)
        {
            if(!Head)
            {
                insertFirst(Val);
                return;
            }
            Node* Slow = Head;
            Node* Fast = Head;
            while(Fast->Next != Head && Fast->Next->Next != Head)
            {
                Slow = Slow->Next;
                Fast = Fast->Next->Next;
            }
            Node* NewNode = new Node(Val);
            NewNode->Next = Slow->Next;
            NewNode->Prev = Slow;
            Slow->Next->Prev = NewNode;
            Slow->Next = NewNode;
        }
        
        void displayForward()
        {
            if(!Head) return;
            Node* Temp = Head;
            do
            {
                cout << Temp->Data << "->";
                Temp = Temp->Next;
            } while(Temp != Head);
            cout << "(Head)" << endl;
        }
        
        void displayReverse()
        {
            if(!Head) return;
            Node* Temp = Head->Prev;
            do
            {
                cout << Temp->Data << "->";
                Temp = Temp->Prev;
            } while(Temp != Head->Prev);
            cout << "(Tail)" << endl;
        }
};

int main()
{
    CircularLinkedList CLL;
    CLL.insertFirst(1);
    CLL.insertFirst(2);
    CLL.insertLast(3);
    CLL.insertNth(4, 1);
    CLL.insertCenter(5);
    
    cout << "Circular Linked List (Forward): ";
    CLL.displayForward();
    
    cout << "Circular Linked List (Reverse): ";
    CLL.displayReverse();
    
    return 0;
}