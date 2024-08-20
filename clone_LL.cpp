#include<bits/stdc++.h>

using namespace std;

class node
{
    public:
        int data;
        node* next;
        node* arb;
        node(int data) : data(data),next(NULL),arb(NULL) {}
};

class solution
{
    public:
    node* copy_list(node* head)
    {
        if(head == NULL)
        {
            return head;
        }

        unordered_map<node*,node*> oldtonew;

        node* curr = head;
        while(curr != NULL)
        {
            node* newnode = new node(curr->data);
            oldtonew[curr] = newnode;
            curr = curr->next;
        }

        curr = head;
        while(curr != NULL)
        {
            oldtonew[curr]->next = curr->next;
            oldtonew[curr]->arb = curr->arb;
            curr = curr->next;
        }
        return oldtonew[head];
    }

void printLinkedList(node* head) {
    node* curr = head;
    while (curr != nullptr) {
        cout << "Data: " << curr->data;

        if (curr->arb != nullptr) {
            cout << ", Random: " << curr->arb->data;
        }

        cout << endl;
        curr = curr->next;
    }
}
};
int main()
{
    node* head = new node(1);
    node* node2 = new node(2);
    node* node3 = new node(3);
    node* node4 = new node(4);
    node* node5 = new node(5);

    head->next = node2;
    head->arb = node3;

    node2->next = node3;
    node2->arb = node5;

    node3->next = node4;
    node3->arb = node2;

    node4->next = node5;
    node4->arb = node3;

    node5->arb = node4;
    solution l1;
    // Print the original linked list
    cout << "Original Linked List:" << endl;
    l1.printLinkedList(head);

    // Create a copy of the linked list
    node* copied_head = l1.copy_list(head);

    // Print the copied linked list
    cout << "Copied Linked List:" << endl;
    l1.printLinkedList(copied_head);

    return 0;
}