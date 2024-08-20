#include<bits/stdc++.h>

using namespace std;

class node
{
    public:
        int data;
        node *next;
        node(int data): data(data),next(NULL) {}
};
class add_no_ll
{
    private:
        node *head;
        node *tail;
    public:
        add_no_ll() : head(NULL),tail(NULL) {}

        void insert_head(int data)
        {
            node* temp = new node(data);
            temp->next  = head;
            head = temp;
            if(tail == NULL) {
                tail = temp;
            }
        }
        void insert_end(int data)
        {
            node* temp = new node(data);
            if(tail != NULL) {
                tail->next = temp;
            }
            tail = temp;
            if(head == NULL) {
                head = temp;
            }
        }
        void print()
        {
            node* temp = head;
            while(temp != NULL)
            {
                cout<<temp->data;
                temp = temp->next;
            }
            cout<<endl;
        }
        node* reverse()
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
        node* add(node* first,node* second)
        {
            int carry = 0;
            node* anshead = NULL;
            node* anstail = NULL;
            while(first != NULL && second != NULL)
            {
                int sum = carry + first->data + second->data;
                int digit = sum % 10;
                insert_end(digit);
                carry = sum/10;
                first = first->next;
                second = second->next;
            }
            while(first != NULL)
            {
                int sum = carry + first->data;
                int digit = sum % 10;
                insert_end(digit);
                carry = sum/10;
                first = first->next;
            }
            while(second != NULL)
            {
                int sum = carry + second->data;
                int digit = sum % 10;
                insert_end(digit);
                carry = sum/10;
                second = second->next;
            }
            return anshead;
        }

        node* sum_LL(add_no_ll& l1,add_no_ll& l2)
        {
            //STEP->1  REVERSE THE LINK LIST;
            node* r_l1  = l1.reverse();
            node* r_l2  = l2.reverse();
            //STEP->2 ADD THE DATA OF THE LINK LIST;
            node* ans = add(r_l1,r_l2);
            node* result= reverse();
            return result;
        }
};

int main()
{
    add_no_ll l1,l2,l3;
    l1.insert_head(3);
    l1.insert_end(4);

    l2.insert_head(4);
    l2.insert_end(3);

    l1.print();
    l2.print();

    node* sum = l3.sum_LL(l1,l2);

    while (sum != NULL) {
        cout << sum->data;
        sum = sum->next;
    }
    cout << endl;

    return 0;
}