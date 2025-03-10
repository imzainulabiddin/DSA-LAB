#include <iostream>
using namespace std;

class Node
{
    public:
        int Data;
        Node* Next;
    Node(int Val)
    {
        Data = Val;
        Next = NULL;
    }
};

class SinglyLinkedList
{
    Node* Head;
    Node* Tail;
    
    public:
        SinglyLinkedList()
        {
            Head = Tail = NULL;
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
                Tail = NewNode;
            }
        }
        
        void display()
        {
            Node* Temp = Head;
            while(Temp != NULL)
            {
                cout << Temp->Data << "->";
                Temp = Temp->Next;
            }
            cout << "NULL" << endl;
        }
        
        void merge(SinglyLinkedList &OtherList)
        {
            if (!Head)
            {
                Head = OtherList.Head;
                Tail = OtherList.Tail;
            }
            else if (OtherList.Head)
            {
                Tail->Next = OtherList.Head;
                Tail = OtherList.Tail;
            }
        }
};

class DNode
{
    public:
        int Data;
        DNode* Next;
        DNode* Prev;
    DNode(int Val)
    {
        Data = Val;
        Next = Prev = NULL;
    }
};

class DoublyLinkedList
{
    DNode* Head;
    DNode* Tail;
    
    public:
        DoublyLinkedList()
        {
            Head = Tail = NULL;
        }
        
        void push_back(int Val)
        {
            DNode* NewNode = new DNode(Val);
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
        
        void displayForward()
        {
            DNode* Temp = Head;
            while(Temp != NULL)
            {
                cout << Temp->Data << "->";
                Temp = Temp->Next;
            }
            cout << "NULL" << endl;
        }
        
        void displayReverse()
        {
            DNode* Temp = Tail;
            while(Temp != NULL)
            {
                cout << Temp->Data << "->";
                Temp = Temp->Prev;
            }
            cout << "NULL" << endl;
        }
        
        void merge(DoublyLinkedList &OtherList)
        {
            if (!Head)
            {
                Head = OtherList.Head;
                Tail = OtherList.Tail;
            }
            else if (OtherList.Head)
            {
                Tail->Next = OtherList.Head;
                OtherList.Head->Prev = Tail;
                Tail = OtherList.Tail;
            }
        }
};

int main()
{
    SinglyLinkedList List1, List2;
    List1.push_back(1);
    List1.push_back(2);
    List1.push_back(3);
    List2.push_back(4);
    List2.push_back(5);
    List2.push_back(6);
    
    cout << "Singly Linked List 1: ";
    List1.display();
    cout << "Singly Linked List 2: ";
    List2.display();
    
    List1.merge(List2);
    cout << "Merged Singly Linked List: ";
    List1.display();
    
    DoublyLinkedList DList1, DList2;
    DList1.push_back(10);
    DList1.push_back(20);
    DList1.push_back(30);
    DList2.push_back(40);
    DList2.push_back(50);
    DList2.push_back(60);
    
    cout << "\nDoubly Linked List 1: ";
    DList1.displayForward();
    cout << "Doubly Linked List 2: ";
    DList2.displayForward();
    
    DList1.merge(DList2);
    cout << "Merged Doubly Linked List (Forward): ";
    DList1.displayForward();
    cout << "Merged Doubly Linked List (Reverse): ";
    DList1.displayReverse();
    
    return 0;
}