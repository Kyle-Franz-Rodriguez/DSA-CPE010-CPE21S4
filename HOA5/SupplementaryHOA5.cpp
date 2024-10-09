#include <iostream>
using namespace std;

class Node
{
	public:
		string data;
		Node* next;
};

Node *head = NULL, *tail = NULL;

class Job
{
    public:
        int pages;
        string ID, name;
};

class Printer
{
	public:
		string data;
	
	Node* addpending(Node* tail, string data)
	{
		Node* newDat = new Node;
		newDat->data = data;
		newDat->next = NULL;
		if(head==NULL)
		{
		    head = tail = newDat;
	        return newDat;
		} 
	    else 
	    {
		    Node* temp = tail;
		    while (temp->next != NULL)
		    {
		        temp = temp->next;
		    }
		    
		    temp->next = newDat;
		    return head;
	    }
    };

	void process(Node* head)
	{
		Node* temp = head;
		if(head == NULL)
		{
			cout <<"All jobs have been processed" <<endl;
			return;
		}
		cout <<"Now processing jobs"<<endl;
		head = head->next;
		cout << "Job completed for: " << temp->data;
	    delete(temp);
		cout <<endl;
	}
	
	void showpending(Node* head)
	{
		if (head == NULL)
		{
		    cout<<"No current pending jobs"<<endl;
		    return;
		}
		Node* curr = head;
		cout <<"Now processing for employee ID: "<<endl;
		while(curr != NULL)
		{
			cout<<curr->data <<endl;
			curr = curr->next;
		}
		cout<< endl;
	}
};

int main()
{
	Printer store;
	Job emp1, emp2, emp3, emp4, emp5;
	Node* PendingJob = NULL;
	
	//Employee 1
	emp1.name = "John Doe";
	emp1.ID = "cc2134";
	emp1.pages = 5;
	
	//Employee 2
	emp2.name = "Stalin Silvester";
	emp2.ID = "cw2137";
	emp2.pages = 5;
	
	//Employee 3
	emp3.name = "Jasmine James";
	emp3.ID = "cq2139";
	emp3.pages = 5;
	
	//Employee 4
	emp4.name = "Martin Martin";
	emp4.ID = "ct2132";
	emp4.pages = 5;
	
	//Employee 5
	emp5.name = "Hannah Monroe";
	emp5.ID = "cg2135";
	emp5.pages = 5;
	
	//Adding their jobs
	PendingJob = store.addpending(PendingJob, emp1.ID);
	PendingJob = store.addpending(PendingJob, emp2.ID);
	PendingJob = store.addpending(PendingJob, emp3.ID);
	PendingJob = store.addpending(PendingJob, emp4.ID);
	PendingJob = store.addpending(PendingJob, emp5.ID);
	store.showpending(PendingJob);
	
	//Processing their jobs
	store.process(PendingJob);
	return 0;
}
