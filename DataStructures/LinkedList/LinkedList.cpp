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

    int searchElementIterative(int data)
    {
        node *temp = head;
        int ctr = 0;
        while (temp->next != NULL)
        {
            if (temp->data == data)
                return ++ctr;
            ctr++;
            temp = temp->next;
        }
        return -1;
    }

    int searchElementRecursivly(int data, node *Node = NULL, int ctr = 0)
    {
        if (Node == NULL)
            Node = head;

        if (Node->next == NULL && Node->data != data)
            return -1;
        if (Node->data == data)
            return ++ctr;
        Node = Node->next;
        return searchElementRecursivly(data, Node, ctr + 1);
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

    node *rList(node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        node *rest = rList(head->next);
        head->next->next = head;
        head->next = NULL;
        return rest;
    }
    void reverseList()
    {
        this->head = this->rList(this->head);
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
    // cout << "\t" << ll.searchElementIterative(10) << endl;
    // cout << "\t" << ll.searchElementRecursivly(5) << endl;
    // ll.lenghtIterativly();
    ll.addElementBack(11);
    ll.lengthRecursivly();
    ll.reverseList();
    ll.printElements();
    return 0;
}