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

    int lenghtIterativly()
    {
        int ctr = 0;
        node *temp = head;
        while (temp != NULL)
        {
            ctr++;
            temp = temp->next;
        }
        return ctr;
    }

    int lengthRecursivly(int ctr = 0, node *temp = NULL)
    {
        if (temp == NULL && ctr == 0)
            temp = head;

        if (temp == NULL)
        {
            return ctr;
        }
        return lengthRecursivly(ctr + 1, temp->next);
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

    void deleteKey(int key)
    {
        node *temp, *temp2;
        temp = head;
        if (searchElementIterative(key) == -1)
        {
            cout << "This element is not part of linked list " << endl;
            return;
        }
        while (temp->next->data != key)
            temp = temp->next;

        temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
    }
    void deletePosition(int position)
    {
        int ctr = 0;
        node *temp = head, *temp2;

        if (lenghtIterativly() < position)
        {
            cout << "There is no element in that position " << endl;
            return;
        }
        for (int i = 0; i < position - 2; i++)
        {
            if (temp->next != NULL)
            {
                temp = temp->next;
                ctr++;
            }
        }
        temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
    }

    // method to get Nth node in ll
    void getNth(int pos)
    {

        if (lenghtIterativly() < pos)
        {
            cout << "There is no element in that position " << endl;
            return;
        }
        node *temp = head;
        for (int i = 0; i < pos - 1; i++)
            temp = temp->next;
        cout << "\tAt position " << pos << " is node with value " << temp->data << endl;
    }
    // method to get Nth node from the end of ll

    // method to delete ll

    void iterReverse()
    {
        node *curr, *next = NULL, *prev = NULL;
        curr = head;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
};

int main()
{
    LinkedList ll;
    ll.addElement(5);
    ll.addElement(1);
    ll.addElement(6);
    ll.addElementBack(3);
    ll.addElementBack(6);
    // ll.printElements();
    // cout << "\t" << ll.searchElementIterative(10) << endl;
    // cout << "\t" << ll.searchElementRecursivly(5) << endl;
    // ll.lenghtIterativly();
    ll.addElementBack(11);
    ll.lengthRecursivly();
    // ll.reverseList();
    ll.printElements();
    // ll.deleteKey(1);
    // cout << "After deleting 1" << endl;
    // ll.deletePosition(5);
    // cout << "Aftere deleting on position 5" << endl;
    // ll.printElements();
    // ll.getNth(4);
    cout << "-----------------------------------------------------------------------------\n";
    ll.iterReverse();
    ll.printElements();
    return 0;
}