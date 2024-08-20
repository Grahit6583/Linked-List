#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class node
{
    public:
        int data;
        node*next;
        node(int data) : data(data),next(NULL) {}
};

class sort_list
{
    private:
        node* tail;
        node* head;
    
    public:
        sort_list():head(NULL) , tail(NULL) {}
        void insert_head(int data)
        {
            node* temp = new node(data);
            temp->next = head;
            head = temp;
            tail = temp;
        }
        void insert_end(int data)
        {
            node*temp = new node(data);
            tail->next = temp;
            tail = tail->next;
        }
        void insert_tail(node* &tail,node* curr)
        {
            tail->next = curr;
            tail = curr;
        }
        void print()
        {
            node *temp = head;
            while (temp != NULL)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
        void sort_LL()
        {
            node* zerohead = new node(-1);
            node* zerotail = zerohead;
            node* onehead = new node(-1);
            node* onetail = onehead;
            node* twohead = new node(-1);
            node* twotail = twohead;

            node* curr = head;
            while (curr != NULL)
            {
                int value = curr -> data;
                if(value == 0)
                {
                    insert_tail(zerotail,curr);
                }
                else if(value == 1)
                {
                    insert_tail(onetail,curr);
                }
                else if(value == 2)
                {
                    insert_tail(twotail,curr);
                }
                curr = curr->next;
            }
            // merge list
            if(onehead->next != NULL)
            {
                zerotail->next = onehead->next;
            }
            else
            {
                zerotail->next = twohead->next;
            }

            onetail->next = twohead->next;
            twotail->next = NULL;

            // SET HEAD;
            head = zerohead->next;
            // DELETE DUMMY NODES
            delete zerohead;
            delete onehead;
            delete twohead;
        }
};

int main()
{
    sort_list s1;
    s1.insert_head(1);
    s1.insert_end(0);
    s1.insert_end(2);
    s1.insert_end(1);
    s1.insert_end(2);
    s1.insert_end(0);
    s1.print();
    s1.sort_LL();
    s1.print();
}