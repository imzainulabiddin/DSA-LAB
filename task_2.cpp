#include <iostream>
using namespace std;

void findMaxNum(int arr[], int n)
{   
    int MaxVal = arr[0];

    for(int i = 1; i < n; i++ )
    {
        if(arr[i] > MaxVal)
        {
            MaxVal = arr[i];
        }
    }

    //Display Statement
    cout << "The maximum number in this array: " << MaxVal;

}

int main()
{
    int num;

    cout << "Enter the number of array elements: ";
    cin  >> num;

    int* arr = new int[num];

    cout << "Enter " << num << " elements: ";
    for(int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }

    findMaxNum(arr, num);

    delete[]arr;

    return 0;
}