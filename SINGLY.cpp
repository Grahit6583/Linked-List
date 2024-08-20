#include<iostream>

using namespace std;

class node
{
    public:
        int data;
        node* next;
    node(int data) : data(data),next(next) {}
};

class Circular_SLL
{
    private:
        node* tail;
        node* head;
    public:
        Circular_SLL() : tail(nullptr),head(nullptr) {}

        void insert(int data,int element)
        {
            if(tail == nullptr)
            {
                node* newnode = new node(data);
                tail = newnode;
                newnode->next = newnode;
                head = newnode;
            }
            else
            {
                node* curr = tail;
                bool elementFound = false;

            do {
                if (curr->data == element)
                {
                    elementFound = true;
                    break;
                }
                curr = curr->next;
            } while (curr != tail);

                if (elementFound)
                {
                    // Insert the new node here
                    node* newnode = new node(data);
                    newnode->next = curr->next;
                    curr->next = newnode;
                }
                else
                {
                    cout << "Element not found in the list." << endl;
                }
            }
        }


        void print()
        {
            node* temp = tail;
            if(tail == NULL)
            {
                cout<<"list is empty";
                cout<<tail->next<<" "<<endl;
            }
            do{
                cout<<tail->data<<" ";
                tail  = tail->next;
            }while(tail != temp);
            cout<<endl;
        }

        void delete_node(int element)
        {
            node*prev = tail;
            node*curr = prev->next;
            if(prev == NULL)
            {
                cout<<"Underflow";
                return;
            }
            else
            {
                cout<<"world";
                while(curr->data != element)
                {
                    prev = curr;
                    curr= curr->next;
                }
                prev->next = curr->next;
                //only one element present in list
                if(prev == curr)
                {
                    tail = NULL;
                }
                else if(tail == curr)
                {
                    tail = prev;
                }
                curr->next = NULL;
                delete curr;
            }
        }
};

int main()
{
    Circular_SLL c1;
    c1.insert(3,3);
    c1.insert(4,3);
    c1.insert(5,4);
    c1.insert(6,5);
    c1.insert(7,6);
    
    c1.print();
    cout<<"hello"<<endl;
    c1.delete_node(3);
    c1.delete_node(5);
    c1.delete_node(7);
    c1.delete_node(6);
    c1.delete_node(4);
    c1.print();
    c1.delete_node(0);
}