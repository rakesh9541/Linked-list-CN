#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

int length(Node* head){
    int l = 0;
    while(head != NULL){
        ++l;
        head = head->next;
    }
    return l;
}

Node *deleteNode(Node *head, int i){
    if(head == NULL){
        return head;
    }
    else if(i == 0){
        return head -> next;
    }
    else{
        int count = 0;
        Node* temp = head;
        while(temp != NULL && count < i-1){
            temp = temp -> next;
            count++;
        }
        if(temp != NULL && temp -> next != NULL){
            Node* target = temp -> next;
            temp -> next = target -> next;
            target -> next = NULL;
            delete target;
        }

        return head;
    }
}

Node *takeinput(){
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1){
        Node *newNode = new Node(data);
        if (head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head){
    Node *temp = head;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;

    while (t--){
        Node *head = takeinput();
        int pos;
        cin >> pos;
        head = deleteNode(head, pos);
        print(head);
    }

    return 0;
}
