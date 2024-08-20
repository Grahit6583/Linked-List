#include<bits/stdc++.h>

using namespace std;

class node
{
    public:
        int data;
        node *next;
        node(int data) : data(data),next(NULL) {}
};
class middle_element
{
    private:
        node* head;
        node* tail;
    public:
        middle_element() : head(NULL),tail(NULL) {}
        int getlength()
        {
            node*temp = head;
            int len =0;
            while(temp != NULL)
            {
                len++;
                temp = temp->next;
            }
            return len;
        }
        node* middle()
        {
            // int len = getlength();
            // int ans = len/2;
            // node* temp = head;
            // int cnt =0 ;
            // while(cnt<ans)
            // {
            //     temp = temp->next;
            //     cnt++;
            // }
            // return temp;
            // *****************************second_Approach****************************
            if(head == NULL || head->next == NULL)
            {
                return head;
            }
            node* slow = head;
            node* fast = head;
            while(fast != NULL)
            {
                fast=fast->next;
                if(fast != NULL)
                {
                    fast = fast->next;
                }
                slow = slow->next;
            }
            return slow;
        }
        void push(int data)
        {
            node* temp = new node(data);
            temp->next = head;
            head = temp;
        }
        void printabc()
        {
            node* temp = head;
            while(temp)
            {
                cout<<temp->data<<" ";
                temp = temp->next; 
            }
            cout<<endl;
        }
        void print()
        {
            node *temp = middle();
            cout<<temp->data<<endl;
        }
};
int main()
{
    middle_element m1;
    m1.push(11);
    m1.push(12);
    m1.push(13);
    m1.push(14);
    m1.push(15);
    m1.push(16);
    m1.push(17);
    m1.push(18);
    m1.printabc();
    m1.middle();
    m1.print();
    return 0;
}