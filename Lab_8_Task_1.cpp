#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* head = nullptr; 


void display() {
    Node* temp = head;
    cout << "List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


void insertAtHead(int val) {
    Node* n = new Node(val);
    n->next = head;
    head = n;
}


void insertAtEnd(int val) {
    Node* n = new Node(val);

    if (head == nullptr) {     
        head = n;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)    
        temp = temp->next;

    temp->next = n;
}


void insertAtPosition(int pos, int val) { 
    if (pos == 1) {
        insertAtHead(val);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Invalid position.\n";
        return;
    }

    Node* n = new Node(val);
    n->next = temp->next;
    temp->next = n;
}


void deleteHead() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}


void deleteEnd() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    if (head->next == nullptr) {  
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) 
        temp = temp->next;

    delete temp->next;
    temp->next = nullptr;
}


void deleteAtPosition(int pos) {
    if (pos == 1) {
        deleteHead();
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++)
        temp = temp->next;

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Invalid position.\n";
        return;
    }

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}


int main() {
    int ch, val, pos;

    while (true) {
        cout << "\n1. Insert at End\n"
             << "2. Insert at Head\n"
             << "3. Insert at Position\n"
             << "4. Delete End\n"
             << "5. Delete Head\n"
             << "6. Delete at Position\n"
             << "7. Display List\n"
             << "8. Exit\n"
             << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                insertAtEnd(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                insertAtHead(val);
                break;
            case 3:
                cout << "Enter position and value: ";
                cin >> pos >> val;
                insertAtPosition(pos, val);
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                deleteHead();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                deleteAtPosition(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
