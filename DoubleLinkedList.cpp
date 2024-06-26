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

    current = START;
    previous = NULL;

    while (current != NULL && current->noMhs != rollNo)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {

        cout << "\033{31mThe record with roll number " << rollNo << "not found\033[0m" << endl;
        return;
    }

    if (current == START)
    {
        START = START->next;
        if (START != NULL)
        {
            START->prev = NULL;
        }
    }
    else
    {
        previous->next = current->next;
        if (current->next != NULL)
        {
            current->next->prev = previous;
        }
    }
    delete current;
    cout << "\x1b[32mRecord with roll number" << rollNo << " deleted\x1b[0m" << endl;
}

bool listEmpty() {
    return (START == NULL);
}

void traverse()
{
    if (listEmpty())
        cout << "\nList is empty" << endl;
    else
    {
        cout << "\nRecorts in ascending order of roll number are:" << endl;
        Node* currentNode = START;
        while (currentNode != NULL)
        {
            cout << currentNode->noMhs << " " << currentNode->name << endl;
            currentNode = currentNode->next;
        }
    }
}

void revtraverse() {
    if (listEmpty())
        cout << "\nList  is empty" << endl;
    else
    {
        cout << "\nRecord in descending order of roll number are:" << endl;
        Node* currentNode = START;
        while (currentNode->next != NULL)
            currentNode = currentNode->next;

        while (currentNode != NULL)
        {
            cout << currentNode->noMhs << " " << currentNode->name << endl;
            currentNode = currentNode->prev;
        }
    }
}

void searchData() {
    if (listEmpty() == true)
    {
        cout << "\nList empty" << endl;
    }
    Node* prev, * curr;
    prev = curr = NULL;
    cout << "\nEnter the roll nnumber of  the student whose record youo want to search: ";
    int num;
    cin >> num;
    if (search(num, &prev, &curr) == false)
        cout << "\nRecord not found" << endl;
    else
    {
        cout << "\nRecord found" << endl;
        cout << "\nRoll number: " << curr->noMhs << endl;
        cout << "\nName: " << curr->name << endl;
    }
}

int main() 
{
    while (true)
    {
        try
        {
            cout << "\nMenu" << endl;
            cout << "1. Add a record to the list" << endl;
            cout << "2. Delete a record from the list" << endl;
            cout << "3. View all record in the ascending order of roll numbers" << endl;
            cout << "4. View all record in the descending order of roll numbers;" << endl;
            cout << "5. Search for a record in the list" << endl;
            cout << "6. Exit" << endl;
            cout << "\nEnter your choice (1-6): ";
            char ch;
            cin >> ch;

            switch (ch)
            {
            case '1':
                addNode();
                break;
            case '2':
                deleteNode();
                break;
            case '3':
                traverse();
                break;
            case '4':
                revtraverse();
                break;
            case '5':
                searchData();
                break;
            case '6':
                return 0;
            default:
                cout << "\nInvalid option" << endl;
                break;
            }
        }
        catch (exception& e)
        {
            cout << "check for  the values entered." << endl;
        }
    }
}