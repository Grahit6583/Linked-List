#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class node
{
    public:
        int data;
        node* next;
        node(int data):data(data),next(NULL) {}
};

class SLL
{
    private:
        node* head;
        node* tail;
        // bool checkPalindrome(vector<int> arr)
        // {
        //     int n = arr.size();
        //     int s = 0;
        //     int e = n-1;
        //     while(s<e)
        //     {
        //         if(arr[s] != arr[e])
        //         {
        //             return false;
        //         }
        //         s++;
        //         e--;
        //     }
        //     return true;
        // }
        node* get_mid(node* headx)
        {
            node* slow = headx;
            node* fast = headx->next;
            while(fast != NULL && fast->next != NULL)
            {
                fast = fast->next->next;
                slow = slow->next;
            }
            return slow;
        }

        node* reverse(node* headx)
        {
            node* curr = headx;
            node* prev = NULL;
            node* next = NULL;

            while(curr != NULL)
            {
                next = curr->next;
                curr->next = prev;
                prev  = curr;
                curr = next;
            }
            return prev;
        }
    public:
        SLL():head(NULL),tail(NULL) {}
        void insert_head(int data)
        {
            node* temp = new node(data);
            temp->next = head;
            head = temp;
            tail = temp;
        }
        void insert_tail(int data)
        {
            node* temp = new node(data);
            tail->next = temp;
            tail = tail->next;
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
        // bool isPlaindrome()
        // {
        //     node* temp = head;
        //     vector<int> arr;
        //     while(temp != NULL)
        //     {
        //         arr.push_back(temp->data);
        //         temp = temp->next;
        //     }
        //     return checkPalindrome(arr);
        // }
        bool isPlaindrome()
        {
            if(head == NULL || head->next == NULL)
            {
                return true;
            }
            node* middle = get_mid(head);
            node* temp = middle->next;
            middle->next = reverse(temp);

            node* head1 = head;
            node* head2 = middle->next;
            while(head2 != NULL)
            {
                if(head1->data != head2->data)
                {
                    return false;
                }
                head1 = head1->next;
                head2 = head2->next;
            }
            temp = middle->next;
            middle->next = reverse(temp);
            return true;
        }
};

int main()
{
    SLL l1;
    l1.insert_head(1);
    l1.insert_tail(2);
    l1.insert_tail(1);

    l1.print();

    if(! l1.isPlaindrome())
    {
        cout<<"LIST IS NOT PALINDROME";
    }
    else
    {
        cout<<"LIST IS PALNDROME";
    }
}