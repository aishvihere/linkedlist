#include<iostream>
using namespace std;

class Node{
    public:                        //using oops for linked list definition
    int val;
    Node* next;

    Node (int data){                     //constructor
        val=data;
        next = NULL;

    }
};


//Performing different functions on linked list
void InsertAtHead(Node* &head, int val){
    Node* new_node=new Node(val);
    new_node->next=head;
    head =new_node;
    
    
}

void InsertAtTail(Node* &head, int val){
    Node* newtail_node=new Node(val);
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newtail_node;

}



void InsertAtPos(Node* &head, int val, int pos){
    if(pos==0){
        InsertAtHead(head,val);
    }

    int curr_pos=0;

    
    Node* newpos_node= new Node(val);
    Node* temp= head;
    while(curr_pos!=pos-1){
        temp=temp->next;
        curr_pos++;
    }

    newpos_node->next=temp->next;
    temp->next=newpos_node;

    
}

void UpdateAtpos(Node* &head,   int val, int pos){
    Node* newupd_node= new Node(val);
    Node* temp= head;
    int current_pos=0;
    while(current_pos!=pos){
        temp=temp->next;
        current_pos++;
    }
    temp->val=val;

}

void DelelteAtHead(Node* &head){

    Node* temp=head;
    head= head->next;
    free(temp);

}

void DeleteAtTail(Node* &head)
{
    Node* second_last=head;
    while(second_last->next->next!=NULL){
        second_last=second_last->next;
    }

    Node* temp=second_last->next;
    second_last->next=NULL;
    free(temp);

}

void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }

    cout<<"NULL"<<endl;
    

}

int main(){
    Node* head= NULL;
    InsertAtHead(head,5);      //TIme complexity: O(1)
    display(head);
    InsertAtHead(head,2);
    display(head);
    InsertAtTail(head,7);       //time complextity: O(n)
    display(head);
    InsertAtPos(head,11,1);
    display(head);
    UpdateAtpos(head,20,2);
    display(head);
    DelelteAtHead(head);
    display(head);
    DeleteAtTail(head);
    display(head);
    
    return 0;

}