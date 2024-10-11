#include <iostream>
#include <utility>
using namespace std;

// Create a node
class Node {
    public:
    char data;
    Node* next;
};

//TRAVERSAL
void ListTraversal(Node* n) 
{
    while(n != nullptr) 
    {
        cout<< n ->data;
        n = n ->next; 
    }
    cout<< endl;
};

//Allocate new head
Node* NewHead(Node* head, char data)
{
    Node* newhead = new Node();
    newhead ->data = data;
    newhead->next = head;
    return newhead;
};

//Insert node everywhere
Node* Insert(Node* head, Node* replace, char data) 
{
	if (head == replace) 
	{
    cout << "Previous node cannot be null";
    return NULL;
    }
    Node* insert = new Node();
    insert ->data = data;
    insert ->next = replace ->next;
    replace ->next = insert;
    return head;
};

//Insert a node at the end
Node* insTail(Node* head, char data)
{
	Node* newtail = new Node();
	if (head == nullptr)
	{
		return newtail;
	}
	Node* replace = head;
	newtail ->data = data;
	newtail ->next = nullptr;
	while (replace ->next != nullptr)
	{
		replace = replace ->next;
	}
	replace ->next = newtail;
	return head;
};

//Delete a node
void delNode(Node* head, char item)
{
	
	Node* carry = head;
    while (carry->next != nullptr && carry->next->data != item) 
	{
        carry = carry->next;
    }
    Node* temp = carry->next;
    carry->next = temp->next;
    delete temp;
};

int main() {
	
    //MODIFIED FOR MORE SIMPLE
	//STEP 1
    Node* head = new Node;
    Node* two = new Node;
    Node* three = new Node;
    Node* four = new Node;
    Node* five = new Node;
    Node* last = new Node;
    
    //STEP 3
    head ->data = 'C';
    head ->next = two;
    
    two ->data = 'P';
    two ->next = three;
    
    three ->data = 'E';
    three ->next = four;
    
    four ->data = '0';
    four ->next = five;
    
    five ->data = '1';
    five ->next = last;
    
    last ->data = '0';
    last ->next = nullptr;
    
    //INITIALIZE TRAVERSAL
    cout << "Original list: " << endl;
    ListTraversal(head);
    cout << endl;
    
    //INSERTION NODE AT HEAD
    cout << "New head: " << endl;
    head = NewHead(head, 'G');
    ListTraversal(head);
    cout << endl;
    
    //INSERT NODE AT ANY PLACE
    cout << "Added E after P: " << endl;
    head = Insert(head, two, 'E');
    ListTraversal(head);
    cout << endl;
    
    //INSERT A NODE AT THE END
    cout << "Add node at the tail: " << endl;
    head = insTail(head, '1');
    ListTraversal(head);
    cout << endl;
    
    //DELETE A NODE
    cout << "Delete C: " << endl;
    delNode(head, 'C');
    ListTraversal(head);
    cout << endl;
    
    //DELETE A NODE
    cout << "Delete P: " << endl;
    delNode(head, 'P');
    ListTraversal(head);
    cout << endl;
}
