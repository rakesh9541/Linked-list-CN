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
int main()
{
    node n1(1);  // anpother way to initalize      node *n1=new node(1);  cout<<n1->data; op- 1
    node *head=&n1;
    cout<<head->data<<endl;  //op 1
    node n2(2);
    n1.next=&n2;
    cout<<n1.data<< " "<<n2.data<<endl;  //op - 1 2
    cout<<n1.next<<" "<<n2.next<<endl;   //op 0x61fe00 0
}
