#include<bits/stdc++.h>

using namespace std;

class node
{
    public:
        int data;
        node* next;
        node(int data) : data(data),next(NULL) {}
};

class merge_LL
{
    private:
        node*head;
        node*tail;
    public:
        merge_LL():head(NULL),tail(NULL){}
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
    void solve(node* curr1, node* next1, node* curr2, node* next2)
        {
        if(curr1->next == NULL)
        {
            curr1->next = curr2;
            return;
        }
        while(next1 != NULL && curr2 != NULL)
        {
            if((curr2->data >= curr1->data) && (curr2->data <= next1->data))
            {
                curr1->next = curr2;
                next2 = curr2->next;
                curr2->next = next1;

                curr1 = curr2;
                curr2 = next2;
            }
            else
            {
                curr1 = next1;
                next1 = next1->next;
                if(next1 == NULL)
                {
                    curr1->next = curr2;
                    return ;
                }
            }
        }
        }
    void sort_list(merge_LL& list1, merge_LL& list2)
    {
        if (list1.head == NULL)
        {
            head = list2.head;
            tail = list2.tail;
            return;
        }
        if (list2.head == NULL)
        {
            head = list1.head;
            tail = list1.tail;
            return;
        }

        if (list1.head->data <= list2.head->data)
        {
            head = list1.head;
            tail = list1.tail;
            solve(head, head->next, list2.head, list2.head->next);
        }
        else
        {
            head = list2.head;
            tail = list2.tail;
            solve(head, head->next, list1.head, list1.head->next);
        }
    }

};

int main()
{
    merge_LL l1,l2,l3;
    l1.insert_head(0);
    // l1.insert_end(1);
    // l1.insert_end(2);
    // l1.insert_end(3);
    // l1.insert_end(4);
    // l1.insert_end(5);

    l2.insert_head(6);
    // l2.insert_end(7);
    // l2.insert_end(8);
    // l2.insert_end(9);
    // l2.insert_end(10);
    // l2.insert_end(11);

    l1.print();
    l2.print();

    l3.sort_list(l1,l2);
    l3.print();
}