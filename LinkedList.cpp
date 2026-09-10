// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int d){
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class LL{
    public:
    Node* head;

    LL(){
        head = NULL;
    }

    void insertFront(int data){
        Node* newnode = new Node(data);
        if (head==NULL){
            head = newnode;
        }
        else{
            newnode->next = head;
            head = newnode;
        }
    }

    void insertBack(int data){
        if (head==NULL){
            insertFront(data);
        }
        else{
            Node* newnode = new Node(data);
            Node* temp = head;
            while(temp->next!=NULL) temp = temp->next;
            temp->next = newnode; 
        }
    }

    void deleteFirst(){
        if (head==NULL) return;

        if (head->next==NULL){
            delete head;
            head = NULL;
            return;
        }
        
        Node* temp = head->next;
        delete head;
        head = temp;
    }

    void deleteLast(){
        if (head==NULL){
            return;
        }
        if (head->next==NULL){
            delete head;
            head = NULL;
            return;
        }
        else{
            Node* temp = head;
            while(temp->next->next!=NULL) temp = temp->next;
            delete temp->next;
            temp->next = NULL;
             
        }
    }

    void print(){
        if (head == NULL) return;
        Node* temp = head;
        cout << head->data << " ";
        while(temp->next!=NULL){
            cout << temp->next->data << " ";
            temp = temp->next;
        }
        cout << '\n';
    }
};

class DLL{
    public:
    Node* head;

    DLL(){
        head = NULL;
    }

    void insertFront(int data){
        Node* newnode = new Node(data);
        if (head==NULL){
            head = newnode;
        }
        else{
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }
    void insertLast(int data){
        Node* newnode = new Node(data);
        if (head==NULL){
            head = newnode;
        }
        else{
            Node* temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;

        }
    }

    void deleteFirst(){
        if (head == NULL) return;

        if (head->next==NULL){
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head->next;
        delete head;
        head = temp;
    }

    void deleteLast(){
        if (head==NULL){
            return;
        }
        if (head->next==NULL){
            delete head;
            head = NULL;
            return;
        }
        else{
            Node* temp = head;
            while(temp->next->next!=NULL) temp = temp->next;
            delete temp->next;
            temp->next = NULL;
             
        }
    }

    void deletePos(int pos){
        if (head==NULL) return;
        if (pos==1){
            deleteFirst();
            return;
        }
        if (pos==4){
            deleteLast();
            return;
        }
        int cnt = 1;
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
            cnt++;
            if (cnt==pos){
                Node* agla = temp->next;
                Node* pichla = temp->prev;
                delete temp;
                pichla->next = agla;
                agla->prev = pichla;
                break;
            }
        }
        
    }

    
    void print(){
        if (head == NULL) return;
        Node* temp = head;
        cout << head->data << " ";
        while(temp->next!=NULL){
            cout << temp->next->data << " ";
            temp = temp->next;
        }
        cout << '\n';
    }
};

int main() {
    // LL linklist;
    // linklist.insertBack(1);
    // linklist.insertBack(2);
    // linklist.insertBack(3);
    // linklist.insertBack(4);
    // linklist.print();

    // linklist.deleteLast();
    // linklist.print();

    // linklist.deleteFirst();
    // linklist.print();

    // linklist.insertFront(1);
    // linklist.print();

    DLL linklist;
    linklist.insertLast(1);
    linklist.insertLast(2);
    linklist.insertLast(3);
    linklist.insertLast(4);
    linklist.print();

    int pos;
    cout << "Enter pos: "; cin>>pos;
    cout << '\n';
    linklist.deletePos(pos);
    linklist.print();



    
	return 0;
}
