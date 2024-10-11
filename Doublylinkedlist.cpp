#include <iostream>
#include <utility>
using namespace std;

// Create a node
class Node {
    public:
    char data;
    Node* next;
    Node* prev;
};

//TRAVERSAL FORWARD
void FrontTraversal(Node* nhead) 
{
    while(nhead != nullptr) 
    {
        cout<< nhead ->data;
        nhead = nhead ->next; 
    }
    cout<< endl;
};

//TRAVERSAL BACKWARD
void BackTraversal(Node* ntail) 
{
	while (ntail != nullptr) 
	{
        cout << ntail->data;
        ntail = ntail->prev;
    }
    cout << endl;
}

//Allocate new head
Node* NewHead(Node* head, char data)
{
    Node* newhead = new Node();
    newhead ->data = data;
    newhead->next = head;
    head ->prev = newhead;
    newhead ->prev = nullptr;
    return newhead;
};

//Insert node everywhere
Node* Insert(Node* head, Node* replace, char data) 
{
	if (replace ->prev == nullptr) 
	{
    cout << "Previous node cannot be null";
    return NULL;
    }
    Node* insert = new Node();
    insert ->data = data;
    insert ->next = replace ->next;
    replace ->next = insert;
    insert ->prev = replace;
    insert ->next->prev = insert;
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
	newtail ->data = data;
	newtail ->next = nullptr;
	Node* prevtail = head;
	while (prevtail ->next != nullptr)
	{
		prevtail = prevtail ->next;
	}
	prevtail ->next = newtail;
	newtail ->prev = prevtail;
	return head;
};

//Delete a node
void delNode(Node* head, char item)
{
    Node* carry = head;
    while (carry != NULL) 
	{
        if (carry ->data == item) 
		{
            if (carry == head) 
			{
                head = carry->next;
                if (head != NULL) 
				{
                    head->prev = NULL;
                }
            }
            else if (carry->next == NULL) 
			{
                carry->prev->next = NULL;
            }
            else 
			{
                carry->prev->next = carry->next;
                carry->next->prev = carry->prev;
            }

            delete carry;
            return;
        }
        carry = carry->next;
    }
};

//JUST A DELETER FOR CLEANING
void deleteLinkedList(Node* head) {
    Node* current = head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        cout << current << " Deleted" << endl;
		delete current;
        current = next;
    }
}

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
    head ->prev = nullptr;
    
    two ->data = 'P';
    two ->next = three;
    two ->prev = head;
    
    three ->data = 'E';
    three ->next = four;
    three ->prev = two;
    
    four ->data = '0';
    four ->next = five;
    four ->prev = three;
    
    five ->data = '1';
    five ->next = last;
    five ->prev = four;
    
    last ->data = '0';
    last ->next = nullptr;
    last ->prev = five;
    
    //INITIALIZE TRAVERSAL
    cout << "Forward Traversal: " << endl;
    FrontTraversal(head);
    cout << "Backward Traversal: " << endl;
    BackTraversal(last);
    cout << endl;
    
    //INSERTION NODE AT HEAD
    cout << "New head: " << endl;
    head = NewHead(head, 'G');
    FrontTraversal(head);
    BackTraversal(last);
    cout << endl;
    
    //INSERT NODE AT ANY PLACE
    cout << "Added E after P: " << endl;
    head = Insert(head, two, 'E');
    FrontTraversal(head);
    BackTraversal(last);
    cout << endl;
    
    //INSERT A NODE AT THE END
    cout << "Add 1 at the tail: " << endl;
    head = insTail(head, '1');
    FrontTraversal(head);
    BackTraversal(last);
    cout << endl;
    
    //DELETE A NODE
    cout << "Delete C: " << endl;
    delNode(head, 'C');
    FrontTraversal(head);
    BackTraversal(last);
    cout << endl;
    
    //DELETE A NODE
    cout << "Delete P: " << endl;
    delNode(head, 'P');
    FrontTraversal(head);
    BackTraversal(last);
    cout << endl;
    
    deleteLinkedList(head);
}
