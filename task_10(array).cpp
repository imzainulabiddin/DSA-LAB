#include <iostream>
using namespace std;
#define n 20

class stack
{
    int *arr;
    int top;
    public:
        stack()
        {
            arr = new int[n];
            top = -1;
        }

        void push(int x)
        {
            if(top == n-1)
            {
                cout << "Stack overflow!\n";
                return;
            }

            arr[top++] = x;
        }

        void pop()
        {
            if(top == -1)
            {
                cout << "Empty stack!\n";
                return;
            }
            top--;
        }

        void Display()
        {
            if(top == -1)
            {
                cout << "Empty stack!\n";
                return;
            }

            cout << "Stack elements are: ";
            for(int i = top; i>=0; i--)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main()
{
    stack st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.pop();
    st.Display();
    cout << "After removing the topest element.\n";
    st.pop();
    st.Display();
}