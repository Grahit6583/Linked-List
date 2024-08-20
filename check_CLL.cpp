#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class node
{
    public:
        int data;
        node* next;
        node(int data) : data(data),next(NULL) {}
};

class cll
{
    private:
        node* head;
        node* tail;
    public:
        cll() : tail(NULL),head(NULL) {}
        void push(int data)
        {
            node *temp = new node(data);
            if (head == NULL)
            {
                temp->next = temp; // Point the new node's next pointer to itself
                head = temp;       // Update the head to point to the new node
            }
            else
            {
                temp->next = head; // Point the new node's next pointer to the current head
                tail = head;
                while (tail->next != head)
                {
                    tail = tail->next; // Traverse the list to find the last node
                }
                tail->next = temp; // Update the next pointer of the last node to the new node
                head = temp;       // Update the head to point to the new node
            }
        }
        bool iscicular()
        {
            if(head == NULL)
            {
                return true;
            }
            node* temp = head->next;
            while(temp !=NULL && temp != head)
            {
                temp = temp->next;
            }
            if(temp == head)
            {
                return true;
            }
        }
        void print()
        {
            node* temp = tail;
            if(temp == NULL)
            {
                cout<<"list is empty"<<endl;
                return;
            }
            do{
                cout<<temp->data<<" ";
                temp = temp->next;
            }while(temp != tail);
            cout<<endl;
        }
};

int main()
{
    cll c1;
    c1.print();
    if(c1.iscicular())
    {
        cout<<"circular list"<<endl;
    }
    else
    {
        cout<<"not circular list";
    }
}