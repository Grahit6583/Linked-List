#include<iostream>

using namespace std;

class node
{
    public:
        int data;
        node* next;
        node(int data) : data(data) , next(NULL){}
};
class singly_ll
{
    private:
        node* head;
        node* tail;
    public:
        singly_ll() : head(NULL),tail(NULL){}
        node* reverse_ll()
        {
            if(head == NULL || head->next == NULL)
            {
                return head;
            }

            node*prev = NULL;
            node*curr = head;
            node*forward = NULL;
            while(curr != NULL)
            {
                forward = curr->next;
                curr->next = prev;
                prev  = curr;
                curr = forward;
            }
            head = prev;
            return prev;
        }
        void print()
        {
            node* temp = head;
            while(temp != NULL)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }

        void push(int data)
        {
            node* temp = new node(data);
            temp->next = head;
            head = temp;
        }
};

int main()
{
    singly_ll l1;
    l1.push(0);
    l1.push(1);
    l1.push(2);
    l1.push(3);
    l1.push(4);
    l1.push(5);
    l1.print();
    l1.reverse_ll();
    l1.print();
    return 0;
}