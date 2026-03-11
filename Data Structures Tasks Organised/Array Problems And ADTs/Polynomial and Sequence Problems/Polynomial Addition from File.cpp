#include <iostream>
#include <fstream>
using namespace std;

class Node
{
public:
    int coefficient;
    char var;
    int exponent;
    Node* next;

    Node()
    {
        coefficient = 0;
        var = 'x';
        exponent = 0;
        next = nullptr;
    }
};

class LinkedList
{
public:
    Node* head;

    LinkedList()
    {
        head = nullptr;
    }

    void appendNode(Node* n)
    {
        if (head == nullptr)
        {
            head = n;
        }
        else
        {
            Node* temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = n;
        }
    }

    void outputList()
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->coefficient << "x^" << temp->exponent << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList* p1 = new LinkedList;
    LinkedList* p2 = new LinkedList;

    ifstream inputfile;
    inputfile.open("polynomials.txt.txt");

    if (!inputfile)
    {
        cout << "YOUR FILE IS UNABLE TO OPEN!";
    }
    else
    {
        char letter;
        while (inputfile >> letter)
        {
            Node* temp = new Node;
            temp->coefficient = letter - '0';

             //Read 'x'
            inputfile >> letter;

             //Read '^'
            inputfile >> letter;

             //Read exponent
            inputfile >> letter;
            temp->exponent = letter - '0';

            p1->appendNode(temp);
        }
        inputfile.close();
    }

    p1->outputList();

    return 0;
}
