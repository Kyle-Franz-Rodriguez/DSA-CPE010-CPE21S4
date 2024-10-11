#include <iostream>
#include <utility>
#include <string>
using namespace std;

class Node {
	public:
		string data;
		Node* next, * prev;
	
	//SO I HAVE DONT HAVE TO USE ->Data!!!
	Node(string music)
	{
		data = music;
		next = prev = nullptr;
	}
};


//INSERT A SONG AT THE HEAD
void NewHead(Node** head, string data) {
    Node* newhead = new Node(data);

    if (*head == NULL) {
        *head = newhead;
        newhead->next = newhead;
        return;
    }
    
    newhead->next = *head;
    (*head)->prev = newhead;
    Node* last = *head;
    while (last->next != *head) {
        last = last->next;
    }
    last->next = newhead;
    *head = newhead;
}


//TRAVERSAL OF CIRCULAR
void Traversal(Node* head) {
    if (head == NULL) {
        return;
    }

    Node* carry = head;
	do 
	{
        cout << carry->data << endl;
        carry = carry->next;
    } while (carry != head);
}

//SHOW PREVIOUS OR NEXT
void Show(Node* head) {
    if (head == NULL) {
        return;
    }

    Node* current = head;
    int choice;

    do {
        cout <<"Playing " << current->data <<endl;
		cout <<"[1]Previous song" <<endl;
		cout <<"[2]Next song" <<endl;
		cout <<"[0]Back" <<endl;
        cin >> choice;

        switch (choice) {
            case 1:
                current = current->prev;
            case 2:
                current = current->next;
            case 0:
                break;
            default:
                break;
        }
    } while (choice != 0);
}

//DELETE A SONG
void delNode(Node* head, string item)
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

int main() {
	//CURRENT PLAYLIST
	Node* playlist = new Node("Usurper");
	Node* playlist1 = new Node("Blinding lights");
	Node* playlist2 = new Node("Nine In The Afternoon");
	
	playlist ->next = playlist1;
	playlist ->prev = playlist2;
	
	playlist1 ->next = playlist2;
	playlist1 ->prev = playlist;
	
	playlist2 ->next = playlist;
	playlist2 ->prev = playlist1;

	string data;
	int choice = 0;
	cout << "Press 1 to continue" <<endl;
	cin >> choice;
	if (choice == 1) 
	{
		while (choice != 0) 
		{
			cout << "Current playlist: " <<endl;
			//MAKE A PLAYLIST
			if (playlist == NULL) 
			{
				//I WAS SUPPOSED TO MAKE AN EMPTY LIST AT START, BUT TIME IS MY ENEMY
				cout << "You currently don't have a playlist. Create one? " <<endl;
				cout << " [1] Yes" << endl;
				cout << " [0] No" << endl;
				cin >> choice;
				if (choice == 1) 
				{
					cout << "Enter a title for your music: " <<endl;
					getline(cin,data);
					playlist = new Node(data);
				}
				else
				{
					cout << "---Exiting playlist---" <<endl;
					return 0;
				}
			}
			else
			{
				Traversal(playlist);
				cout <<endl <<"What would you like to do?" <<endl;;
				cout << "[1] Play music" <<endl;
				cout << "[2] Play all music" <<endl;
				cout << "[3] Add a music" <<endl;
				cout << "[4] Remove a music" <<endl;
				cout << "[0] Exit" <<endl;
				cin >> choice;
				if (choice == 1)
				{
					
					Show(playlist);
				}
				else if (choice == 2)
				{
					cout << "Now playing " <<endl;
					Traversal(playlist);
					cout <<endl;
					cout <<"Cycle ended" <<endl;
				}
				else if (choice == 3)
				{
					string addsong;
					cout <<"Enter a title for your music: "<<endl;
					cin >> addsong;
					NewHead(&playlist,addsong);
				}
				else if (choice == 4)
				{
					string delsong;
					cout <<"Enter the title you want to delete "<<endl;
					cin >> delsong;
					delNode(playlist,delsong);
			    }
				else
				{
					cout << "---Exiting playlist---";
					return 0;
				}
			}
	    }
    }
    else
    {
    	cout << "--exiting--";
    	return 0;
	}
}
