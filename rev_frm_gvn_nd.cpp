#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data) : data(data), next(NULL) {}
};

class reverse_class
{
private:
    node *head;

public:
    reverse_class() : head(NULL) {}

    node *agr()
    {
        cout<<head->data<<endl;
        return head;
    }
    void sethead(node* reversehead)
    {
        cout<<reversehead->data<<endl;
        head = reversehead;
    }
    void push(int data)
    {
        node *temp = new node(data);
        temp->next = head;
        head = temp;
    }

    void print()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void printabc()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    node *reverse_frm_k(int k, node *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        node *prev = NULL;
        node *curr = head;
        node *next = NULL;
        int count = 0;
        while (curr != NULL && count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if (next != NULL)
        {
            head->next = reverse_frm_k(k, next);
        }
        return prev;
    }
};

int main()
{
    reverse_class r1;
    r1.push(-1);
    r1.push(6);
    r1.push(5);
    r1.push(4);
    r1.push(3);
    r1.push(2);
    r1.push(1);
    r1.print();
    node*reversedhead = r1.reverse_frm_k(4, r1.agr());
    r1.sethead(reversedhead);
    r1.printabc();

    return 0;
}
