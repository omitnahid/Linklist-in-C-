#include<iostream>
using namespace std;

struct node {
           int data;
           node *next;

           node(int value){
            data = value;
            next = NULL;
           }

}; node *head = NULL;


void insert_first(int value){

    node *newnode= new node(value);

    newnode -> next = head;
    head = newnode;
}

void insert_last(int value){
            node *newnode= new node(value);
            node *cur= head;
            while(cur->next != NULL){
                cur= cur->next;
            }
            cur->next = newnode;
}

void insert_middle(int value,int target){
            node* newnode= new node(value);
            node* cur = head;
            while(cur->data!= target){
                cur= cur->next;
            }
            newnode->next=cur->next;
            cur->next = newnode;

}
void delet_first(){
    if(head==NULL){
        cout <<"there is no node:" << endl;

    }
    else {
        node*cur = head;
        head = cur->next;
        delete(cur);
    }
}
void delet_last(){
    if(head == NULL){
        cout << "there is no node:"<<endl;

    }else if(head->next==NULL){
        
        delete(head);
        head=NULL;
    }else{
        node*cur = head;
        while(cur->next->next!= NULL){
            cur = cur->next;
        }
        delete(cur->next);
        cur->next = NULL;
    }
}

void delet_any(int target){
       if(head == NULL){
        cout << "there is no node:"<<endl;
       }else if (head->data == target){
        node*cur= head;
        delete (cur);
        head= NULL;
       }else{
        node* prev = NULL;
        node*cur = head;

        while(cur->data != target){
              prev = cur;
              cur=prev->next;
        }
        prev->next=cur->next;
        delete(cur);
       }

}



void print_node(){
    if(head == NULL) return;
    node *newn= head;
            while (newn != NULL){
                cout << newn->data << endl;
                newn = newn->next;
            }
}

int main(){

        insert_first(20);
        insert_last(30);
        insert_first(40);
        insert_first(70);
        insert_last(11);
        insert_middle(11,20);
        print_node();

        delet_first();
        cout << endl;
        cout << "your node after delet 1st element:" << "" << endl;
        
        print_node();
        cout << "your linklist after delete the last element:"<<" "<<endl;
        delet_last();
        print_node();
        delet_any(11);

        cout <<"your final linklist after dleting the any value:"<<endl;
        print_node();

}