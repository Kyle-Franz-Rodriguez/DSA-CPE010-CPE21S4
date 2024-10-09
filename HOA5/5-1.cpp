#include <iostream>
#include <queue>
using namespace std;

//For displaying names
void displaynames(queue <string> q)
{
    queue <string> c = q;
    while (!c.empty())
    {
        cout<< c.front() << " ";
        c.pop();
    }
    cout << "\n";
};

//Pass array into queue
void pass(string arr[], int size, queue<string>& q)
{
    for (int i = 0; i < size; i++)
    {
        q.push(arr[i]);
    }
};

int main()
{
    queue <string> qstud;
    string student[5] = {"Kent", "Peter", "Christian", "Franz", "Jervie"};
    int studentno = sizeof(student) / sizeof(student[0]);
    //Pass array into the queue
    pass(student,studentno,qstud);
    displaynames(qstud);
    return 0;
}
