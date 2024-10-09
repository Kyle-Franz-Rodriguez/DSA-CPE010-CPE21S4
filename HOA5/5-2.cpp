#include <iostream>
using namespace std;

class Node
{
	public:
		string data;
		Node* next;
};

Node *head = NULL, *tail = NULL;

class Queue
{
	public:
		string data;
	
	void push(string data)
	{
		Node* newDat = new Node;
		newDat->data = data;
		newDat->next = NULL;
		if(head==NULL)
		{
		    head = tail = newDat;
	        return;
		} 
	    else 
	    {
		    tail->next = newDat;
		    tail = newDat;
	    }
    }

	void pop()
	{
		Node* temp = head;
		if(head == NULL)
		{
			return;
		}
		else if(head == tail)
		{
			head == tail == NULL;
		}
		else
		{
			head = head->next;
		}
		delete(temp);
	}
	
	void show()
	{
		Node* curr = head;
		cout <<"All elements:" <<endl;
		while(curr != NULL)
		{
			cout<<curr->data <<' ';
			curr = curr->next;
		}
	}

};

int main()
{
	Queue students;
	students.push("Kent");
	cout << head->data <<" is pushed into queue"<< endl;
	students.push("Peter");
	cout << head->next->data <<" is pushed into queue"<< endl;
	students.push("Christian");
	cout << head->next->next->data <<" is pushed into queue"<< endl;
	students.push("Joseph");
	cout << head->next->next->next->data <<" is pushed into queue"<< endl;
	students.push("Jervie");
	cout << head->next->next->next->next->data <<" is pushed into queue"<< endl;
	students.show();
	return 0;
}
