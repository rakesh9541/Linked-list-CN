
#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data=data;
        next=NULL;
    }
};


node *takeinput()
{
    int data;
    cin>>data;
    node *head=NULL;
    node *tail=NULL;
    while(data!=-1)
    {
        node *newnode=new node(data);
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}

node* insertnode(node *head,int i,int data)
{
    node *newnode=new node(data);
    int count=0;
    node *temp=head;
    if(i==0)
    {
        newnode->next=head;
        head=newnode;
        return head;
    }
    while(temp!=NULL && count<i-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp!=NULL){
    node *a=temp->next;
    temp->next=newnode;
    newnode->next=a;
    }
    return head;
}

void display(node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main()
{
    node *head=takeinput();
    int i,data;
    cin>>i>>data;
    head=insertnode(head,i,data);
    display(head);
}

