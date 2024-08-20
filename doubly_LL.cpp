#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

class node
{
    public:
        int data;
        node* prev;
        node*next;
        node(int data)
        {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
        ~node()
        {
            int value = this->data;
            if(next != NULL)
            {
                delete next;
                next = NULL;
            }
            cout<<"memory free with node data "<<value<<endl;
        }
};

class DoublyLinkList
{
    private:
        node* head;
        node* tail;
    public:
        DoublyLinkList() : head(nullptr), tail(nullptr) {}
        void insert_head(int data)
        {
            if(head == NULL)
            {
                node* newnode = new node(data);
                head = newnode;
                tail = newnode;
            }
            else
            {
                node*temp =new node(data);
                temp->next = head;
                head->prev = temp;
                head = temp;
            }
        }

        void insert_tail(int data)
        {
            if(head == NULL)
            {
                node* newnode = new node(data);
                head = newnode;
                tail = newnode;
            }
            else
            {
                node*temp = new node(data);
                temp->prev = tail;
                tail->next = temp;
                tail = temp;
            }
        }

        void insert_position(int data, int pos)
        {
            if (pos <= 0)
            {
                cout << "Invalid position" << endl;
                return;
            }
            //insert at head
            if(pos==1)
            {
                insert_head(data);
                return;
            }
            else
            {
                node* temp = head;
                int cnt=1;
                while(cnt < pos-1)
                {
                    if (temp == nullptr)
                    {
                        cout << "Invalid position" << endl;
                        return;
                    }
                    temp = temp->next;
                    cnt++;
                }
                if (temp == nullptr)
                {
                    cout << "Invalid position" << endl;
                    return;
                }               
                if(temp->next == NULL)
                {
                    insert_tail(data);
                    return;
                }
                node* insertnode = new node(data);
                insertnode->next  = temp->next;
                temp->next->prev = insertnode;
                temp->next = insertnode;
                insertnode->prev = temp;
            }
        }

        void delete_node(int pos)
        {
            node* temp = head;
            if(pos==1)
            {
                temp->next->prev = NULL;
                head = temp->next;
                temp->next = NULL;
                delete temp;
            }
            else
            {
                node* curr = head;
                node* prev = NULL;
                int cnt = 1;
                while(cnt<pos)
                {
                    prev = curr;
                    curr = curr->next;
                    cnt++;
                }
                if (curr == tail)
                {
                    tail = prev;
                }
                prev->next = curr->next;
                curr->next = NULL;
                cout<<"head : "<<head->data<<endl;
                cout<<"tail : "<<tail->data<<endl;
                delete curr;
            }
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

        int getlen()
        {
            node* temp = head;
            int len = 0;
            while(temp != NULL)
            {
                len++;
                temp = temp->next;
            }
            return len;
        }
};
int main()
{
    DoublyLinkList l1;
    int choice, data, position;

    do 
    {
        system("CLS");
        cout << "1. Insert at head\n2. Insert at tail\n3. Insert at position\n4. Print\n5. Exit\n6. Delete" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter the data : \n";
            cin>>data;
            l1.insert_head(data);
            break;
        case 2:
            cout<<"Enter the data : \n";
            cin>>data;
            l1.insert_tail(data);
            break;
        case 3:
            cout<<"Enter the data : \n";
            cin>>data;
            cout<<"Enter the position : \n";
            cin>>position;
            l1.insert_position(data,position);
            break;
        case 4:
            cout << "Doubly Linked List: \n";
            l1.print();
            break;
        case 5:
            cout<<"Exiting ...";
            return 0;
        case 6:
            cout<<"Enter the position to delete : \n";
            cin>>position;  
            l1.print();
            l1.delete_node(position);      
            l1.print();
            break;   
        default:
            cout<<" Invaild choice ";
            break;
        }
    getch();
    }while(choice != 0);
}