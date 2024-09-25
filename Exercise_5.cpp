#include <iostream>
#include <stack>
using namespace std;

stack<string> bruh;

void display(stack<string>bruh)
{
	while(!bruh.empty())
	{
		cout << bruh.top() << endl;
		bruh.pop();
	}
}

void queue(stack<string>bruh)
{
	string arr;
	arr[bruh.size] = {};
	while(bruh.size() != 1)
	{
		arr[] = 
		    return;
	}
}

int main()
{
	//Add items
	bruh.push("C++");
	bruh.push("Java");
	bruh.push("Python");
	int full = bruh.size();
	//Printing the stack
	cout << "Stack:"<< endl << endl;
	//display
	display(bruh);
	cout << endl << "----------" << endl;

	//Printing the queue
	cout << "Queue:"<< endl << endl;
	//display

	//Stack is full
	bruh.push("Imposter");
    if(bruh.size > full()) {
        cout << "Stack is full" <<endl;
    }
    display(bruh);

	return 0;
}