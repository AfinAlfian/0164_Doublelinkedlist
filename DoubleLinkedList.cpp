#include <iostream>
#include <string>
using namespace std;

struct Node {
    int noMhs;
    string name;
    Node* next;
    Node* prev;
};

Node* START = NULL;

void addNode() {
    Node* newNode = new Node();
    cout << "\nEnter the roll number of the student: ";
    cin >> newNode->noMhs;
    cout << "\nEnter the name of the student: ";
    cin >> newNode->name;

    if (START == NULL || newNode->noMhs <= START->noMhs)
    {
        if (START != NULL && newNode->noMhs == START->noMhs)
        {
            cout << "\033[31mDuplicate roll numbers not allowed\033[0m" << endl;
            return;
        }

        newNode->next = START;
        if (START != NULL)
        {
            START->prev = newNode;  //step 4 make first node ppoint to new node
        }
        newNode->prev = NULL;   // step 5 make the new node  point to null
        START = newNode;
    }
    else
    {
        //insert the newnode in the middle or at the end
        Node* current = START;  // step 1.a: start from the first node
        Node* previous = NULL;  // step 1.b: previous node is null initially

        while (current != NULL && current->noMhs < newNode->noMhs)      //step 1,c 
        {
            previous = current;         //step 1.d
            current = current->next;    //step 1.e
        }

        newNode->next = current;        //step 4
        newNode->prev = previous;       //step 5

        if (current != NULL)
        {
            current->prev = newNode;    //step 6
        }

        if (previous != NULL)
        {
            previous->next = newNode;   //step 7
        }
        else
        {
            //if previous is  still null, it means new node is now the first node
            START = newNode;
        }
    }
}

bool search(int rollNo, Node** previous, Node** current)
{
    *previous = NULL;
    *current = START;
    while (*current != NULL && (*current)->noMhs != rollNo)
    {
        *previous = *current;
        *current = (*current)->next;
    }
    return (*current != NULL);
}

void deleteNode() {
    Node* previous, * current;
    int rollNo;

    cout << "\nEnter the roll number of the student wose recort is to be deleted: ";
    cin >> rollNo;
}
int main() 
{

}