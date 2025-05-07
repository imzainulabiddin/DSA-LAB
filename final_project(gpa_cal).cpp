#include <iostream>
#include <iomanip>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <limits> 

using namespace std;

const int MAX_COURSES = 8;
const int MAX_SEMESTERS = 8;

//======== Function to validate marks input (0-100) ========
int validateMarks() 
{
    int marks;
    while (true) 
	{
        cin >> marks;
        if (cin.fail() || marks < 0 || marks > 100) 
		{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter marks between 0-100: ";
        } 
		else 
		{
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return marks;
        }
    }
}

//========= Function to validate credits input (positive integer) ========
int validateCredits() 
{
    int credits;
    while (true) 
	{
        cin >> credits;
        if (cin.fail() || credits <= 0) 
		{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter positive integer for credits: ";
        } 
		else 
		{
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return credits;
        }
    }
}

//========== Function to validate GPA input (0.0-4.0) ==========
float validateGPA() 
{
    float gpa;
    while (true) 
	{
        cin >> gpa;
        if (cin.fail() || gpa < 0.0 || gpa > 4.0) 
		{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter GPA between 0.0-4.0: ";
        } 
		else 
		{
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return gpa;
        }
    }
}

//========= Function to convert marks to grade points ========
float marksToGrade(int marks) 
{
    if (marks >= 85) return 4.0;
    if (marks >= 80) return 3.7;
    if (marks >= 75) return 3.3;
    if (marks >= 70) return 3.0;
    if (marks >= 65) return 2.7;
    if (marks >= 60) return 2.3;
    if (marks >= 55) return 2.0;
    if (marks >= 50) return 1.7;
    return 0.0;
}

//======== Function to calculate GPA using array and stack ==========
float calculateGPA() 
{
    system("cls");
    int n;
    cout << "GPA CALCULATION\n";
    cout << "Enter number of courses (max " << MAX_COURSES << "): ";
    while (!(cin >> n) || n <= 0 || n > MAX_COURSES) 
	{
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter number between 1-" << MAX_COURSES << ": ";
    }

    int marks[MAX_COURSES], credits[MAX_COURSES];
    for (int i = 0; i < n; i++) 
	{
        cout << "\nCourse " << i+1 << " details:\n";
        cout << "Marks (0-100): ";
        marks[i] = validateMarks();
        cout << "Credits: ";
        credits[i] = validateCredits();
    }

    stack<float> gpStack;
    stack<int> crStack;
    float totalGP = 0;
    int totalCr = 0;

    for (int i = 0; i < n; i++) 
	{
        float gp = marksToGrade(marks[i]);
        gpStack.push(gp);
        crStack.push(credits[i]);
    }

    while (!gpStack.empty()) 
	{
        totalGP += gpStack.top() * crStack.top();
        totalCr += crStack.top();
        gpStack.pop();
        crStack.pop();
    }

    system("cls");
    return totalGP / totalCr;
}

// Function to calculate CGPA using queue
float calculateCGPA() 
{
    system("cls");
    int n;
    cout << "CGPA CALCULATION\n";
    cout << "Enter number of semesters (max " << MAX_SEMESTERS << "): ";
    while (!(cin >> n) || n <= 0 || n > MAX_SEMESTERS) 
	{
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter number between 1-" << MAX_SEMESTERS << ": ";
    }

    queue<float> gpaQueue;
    queue<int> crQueue;
    float totalGP = 0;
    int totalCr = 0;

    for (int i = 0; i < n; i++) 
	{
        cout << "\nSemester " << i+1 << " details:\n";
        cout << "GPA (0.0-4.0): ";
        float gpa = validateGPA();
        cout << "Credits: ";
        int cr = validateCredits();
        gpaQueue.push(gpa);
        crQueue.push(cr);
    }

    while (!gpaQueue.empty()) 
	{
        totalGP += gpaQueue.front() * crQueue.front();
        totalCr += crQueue.front();
        gpaQueue.pop();
        crQueue.pop();
    }

    system("cls");
    return totalGP / totalCr;
}

int main() 
{
    int choice;
    do 
	{
        system("cls");
        cout << "\nGPA/CGPA CALCULATOR\n";
        cout << "1. Calculate GPA\n2. Calculate CGPA\n";
        cout << "3. Exit\n\nChoice (1-3): ";
        
        while (!(cin >> choice) || choice < 1 || choice > 3) 
		{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice! Please enter 1, 2, or 3: ";
        }

        switch(choice) 
		{
            case 1: 
			{
                float gpa = calculateGPA();
                cout << "GPA RESULT\n";
                cout << "Your GPA: " << fixed << setprecision(2) << gpa << endl;
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;
            }
            case 2: 
			{
                float cgpa = calculateCGPA();
                cout << "CGPA RESULT\n";
                cout << "Your CGPA: " << fixed << setprecision(2) << cgpa << endl;
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;
            }
            case 3:
                cout << "Exiting program..." << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}