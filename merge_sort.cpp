#include<bits/stdc++.h>

using namespace std;

class node
{
    public:
        int data;
        node* next;
        node(int data) : data(data),next(NULL) {}
};

class solution
{
    private: 
        node* head;
        node* tail;
    public:
        solution() : head(NULL),tail(NULL) {}


    void insert_head(int data)
    {
        node* temp = new node(data);
        temp->next  = head;
        head = temp;
        if (tail == NULL) {
            tail = temp;
        }
    }

    void insert_end(int data)
    {
        node* temp = new node(data);
        if (tail != NULL) {
            tail->next = temp;
        }
        tail = temp;
        if (head == NULL) {
            head = temp;
        }
    }
    node* findmid(node* start, node* end)
    {
        node* slow = start;
        node* fast = start;
        while (fast != end && fast->next != end)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }


    node* merge(node* left, node* right)
    {
        if (right == NULL)
        {
            return left;
        }

        if (left == NULL)
        {
            return right;
        }

        node* ans = NULL;
        if (left->data <= right->data)
        {
            ans = left;
            ans->next = merge(left->next, right);
        }
        else
        {
            ans = right;
            ans->next = merge(left, right->next);
        }
        return ans;
    }


    node* mergesort(node* start, node* end)
    {
        if (start == end || start->next == end)
        {
            start->next = NULL;
            return start;
        }

        node* mid = findmid(start, end);
        node* left = mergesort(start, mid);
        node* right = mergesort(mid, end);

        return merge(left, right);
    }


        void sort()
        {
            head = mergesort(head,NULL);
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
};

int main()
{
    solution l1;
    l1.insert_head(5);
    l1.insert_end(4);
    l1.insert_end(3);
    l1.insert_end(2);
    l1.insert_end(1);
    l1.insert_end(0);
    l1.insert_end(-1);

    l1.print();

    l1.sort();
    l1.print();
}