#include<iostream>

using namespace std;

class node
{
    public:
     int data;
     node *next;

    node(int data)
    {
        this->data  = data;
        this->next = NULL;
    }
    ~node()
    {
        int value = this->data;
        if(this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout<<"free data : "<<value<<endl;
    }
};

void insert_head(node * &head , int data)
{
    node* temp = new node(data);
    temp->next = head;
    head = temp;
}

void insert_end(node* &tail ,int data)
{
    node* temp = new node(data);
    tail->next=temp;
    tail = tail->next;
}

void insert_position(node* head , node* &tail , int pos , int data)
{
    if(pos == 1)
    {
        insert_head(head,data);
        return;
    }
    node *temp = head;
    int cnt = 1;
    while(cnt < pos-1)
    {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL)
    {
        insert_end(tail,data);
        return;
    }
    node* newnode = new node(data);
    newnode->next = temp->next;
    temp->next = newnode;
}

void deletenode(int pos ,node* &head)
{
    //first position
    if(pos==1)
    {
        node *temp=head;
        head = head->next;
        delete temp;
    }
    //middle and last position
    else
    {
        node* current = head;
        node* prev = NULL;
        int cnt =1;
        while(cnt<pos)
        {
            prev  = current;
            current = current->next;
            cnt++;
        }
        prev->next = current->next;
        current->next = NULL;
        delete current;
    }
}

node* reverse_ll(node*head)
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

void print(node* &head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

bool iscicular(node*head)
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
int main()
{
    node* newnode =new node(90);
    // cout<<newnode->data<<endl;
    // cout<<newnode->next<<endl;

    // newnode = new node(20);
    // cout<<newnode->data<<endl;
    // cout<<newnode->next<<endl;

    node *head = newnode;
    node *tail = newnode;
    // cout<<head<<endl;
    // cout<<&newnode<<endl;

    // insert_head(head,12);
    // insert_head(head,13);
    // insert_head(head,14);
    // insert_head(head,15);

    // print(head);

    insert_end(tail,16);
    insert_end(tail,17);
    insert_end(tail,18);
    insert_end(tail,19);
    print(head);
    // cout<<endl;
    // insert_position(head,tail,3,90);
    // print(head);

    // deletenode(3,head);
    print(head);
    // reverse_ll(head);
    // print(tail);
    // if(iscicular(head))
    // {
    //     cout<<"list is circular"<<endl;
    // }
    // else
    // {
    //     cout<<"list is not circular"<<endl;
    // }
} 