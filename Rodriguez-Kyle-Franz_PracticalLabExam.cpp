//Stack
//10 pushed into stack
//20 pushed into stack
//30 pushed into stack
//30 popped from stack
//stack elements are 
//20, 10

#include <iostream>
#include <stack>
using namespace std;
stack<int> practical;

void output(stack<int> practical)
{
	while (!practical.empty())
	{
		cout << practical.top() << ' ';
		practical.pop();
	}
}

int main()
{
	int n1,n2,n3;
	n1 = 10;
	n2 = 20;
	n3 = 30;
	
	//push and pop
	practical.push(n1);
	cout<< n1 <<" is pushed into stack" << endl;
	practical.push(n2);
	cout<< n2 <<" is pushed into stack" << endl;
	practical.push(n3);
	cout<< n3 <<" is pushed into stack" << endl;
	practical.pop();
	cout<< n3 <<" is popped from stack" << endl;
	
	//Show elements:
	cout<< "Stack elements are: " << endl;
	output(practical);
	return 0;
}
