#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int passedData)
    {
        data = passedData;
        next = NULL;
    }
};

struct LinkedList
{
    node *head = NULL;

    node *returnHead()
    {
        node *temp = head;
        return temp;
    }

    void addElement(int data)
    {
        if (head == NULL)
        {
            head = new node(data);
            return;
        }
        node *newNode = new node(data);
        newNode->next = head;
        head = newNode;
    }

    void addElementBack(int data)
    {
        if (head == NULL)
        {
            head = new node(data);
            return;
        }
        node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new node(data);
    }

    void printElements()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void searchElementIterative(int data)
    {
        node *temp = head;
        int ctr = 0;
        while (temp->next != NULL)
        {
            if (temp->data == data)
            {
                cout << "Element " << data << " is located at position " << ctr + 1 << " in linked list" << endl;
                return;
            }
            ctr++;
            temp = temp->next;
        }
        if (temp->next == NULL)
            cout << "Element " << data << " is not in the linked list!" << endl;
    }

    void searchElementRecursivly(int data, node *Node = NULL, int ctr = 0)
    {
        if (Node == NULL)
            Node = head;

        if (Node->next == NULL && Node->data != data)
        {
            cout << "Element " << data << " is not in the linked list" << endl;
            return;
        }
        if (Node->data == data)
        {
            cout << "Element " << data << " is located at position " << ctr + 1 << " in linked list" << endl;
            return;
        }
        Node = Node->next;
        searchElementRecursivly(data, Node, ctr + 1);
    }

    void lenghtIterativly()
    {
        int ctr = 0;
        node *temp = head;
        while (temp != NULL)
        {
            ctr++;
            temp = temp->next;
        }
        cout << "Length of linked list is " << ctr << endl;
    }

    void lengthRecursivly(int ctr = 0, node *temp = NULL)
    {
        if (temp == NULL && ctr == 0)
            temp = head;

        if (temp == NULL)
        {
            cout << "Length of linked list is " << ctr << endl;
            return;
        }
        lengthRecursivly(ctr + 1, temp->next);
    }
};

int main()
{
    LinkedList ll;
    ll.addElement(5);
    ll.addElement(1);
    ll.addElement(6);
    ll.addElementBack(3);
    ll.addElementBack(7);
    ll.printElements();
    // ll.searchElementIterative(8);
    // ll.searchElementRecursivly(6);
    // ll.lenghtIterativly();
    ll.addElementBack(11);
    ll.lengthRecursivly();
    return 0;
}