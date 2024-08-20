#include<bits/stdc++.h>

using namespace std;

class node
{
    public:
        int data;
        node* next;
        node(int data) : data(data),next(NULL) {}
};

class Loop_ll
{
    private:
        node*head;
        node*tail;
    public: 
        Loop_ll():head(NULL) , tail(NULL) {}
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
        bool detect_loop()
        {
            if(head == NULL)
            {
                return false;
            }
            node* temp = head;
            map<node*,bool> visited;
            while(temp != NULL)
            {
                if(visited[temp]==true)
                {
                    // cout<<"CYCLE IS PRESENT AT "<<temp->data<<endl;
                    return true;
                }
                visited[temp] = true;
                temp = temp->next;
            }
            return false;
        }
        node* floyds_detect()
        {
            if(head == NULL)
            {
                return NULL;
            }
            node* slow = head;
            node* fast = head;
            while(slow != NULL && fast != NULL)
            {
                fast = fast->next;
                if(fast != NULL)
                {
                    fast = fast->next;
                }
                slow = slow->next;
                if(slow == fast)
                {
                    // cout<<"CYCLE IS PRESENT AT "<<slow->data<<endl;
                    return slow;
                }
            }
            return NULL;
        }

        node* get_loop_start_node()
        {
            if(head == NULL)
            {
                return NULL;
            }
            node* intersection = floyds_detect();
            node* slow = head;
            while(slow != intersection)
            {
                slow = slow->next;
                intersection = intersection->next;
            }
            return slow;
        }
        void setloop()
        {
            tail->next = head->next;
        }
        void remove_loop()
        {
            if(head == NULL)
            {
                return;
            }
            node* start_node = get_loop_start_node();
            node* temp = start_node;
            while(temp->next != start_node)
            {
                temp = temp->next;
            }
            temp->next = NULL;
        }
};

int main()
{
    Loop_ll l1;
    l1.insert_head(5);
    l1.insert_end(10);
    l1.insert_end(20);
    l1.insert_end(30);
    l1.insert_end(40);
    l1.print();
    l1.setloop();
    if(l1.detect_loop())
    {
        cout<<"loop is present"<<endl;
    }
    else
    {
        cout<<"loop is not present"<<endl;
    }
    if(l1.floyds_detect())
    {
        cout<<"loop is present"<<endl;
    }
    else
    {
        cout<<"loop is not present"<<endl;
    }
    node*loop = l1.get_loop_start_node();
    cout<<"starting node of loop is : "<<loop->data<<endl;
    l1.remove_loop();
    l1.print();
    if(l1.floyds_detect())
    {
        cout<<"loop is present"<<endl;
    }
    else
    {
        cout<<"loop is not present"<<endl;
    }
}