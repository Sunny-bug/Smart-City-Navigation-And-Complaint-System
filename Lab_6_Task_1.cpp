#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class linkedlist{
public:
    Node *head;

    linkedlist(){
        head = nullptr;
    }

    void insert(int val){
        Node* n = new Node(val);

        if(head == nullptr){
            head = n;
        }
        else{
            Node* tem = head;
            while(tem->next != nullptr){
                tem = tem->next;
            }
            tem->next = n;
        }
    }
};

int main(){
    linkedlist l;
    l.insert(5);
    l.insert(10);
    l.insert(15);

    // Printing without creating a print function
    Node* temp = l.head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
