#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

// Insert node at end
void insert(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == NULL) {
        head = tail = newNode;
        newNode->next = head;
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
}

// Traverse Circular Linked List
void traverse() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

// Reverse Circular Linked List
void reverse() {
    if (head == NULL || head->next == head)
        return;

    Node* prev = tail;
    Node* curr = head;
    Node* nextNode;

    do {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    } while (curr != head);

    tail = head;
    head = prev;

    cout << "List reversed successfully\n";
}

// Split Circular Linked List
void splitList() {
    if (head == NULL || head->next == head) {
        cout << "Cannot split the list\n";
        return;
    }

    Node *slow = head, *fast = head;

    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* head1 = head;
    Node* head2 = slow->next;

    slow->next = head1;
    fast->next = head2;

    cout << "First half: ";
    Node* temp = head1;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head1);

    cout << "\nSecond half: ";
    temp = head2;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head2);

    cout << endl;
}


int main() {
    int choice, value;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Insert into Circular Linked List\n";
        cout << "2. Traverse Circular Linked List\n";
        cout << "3. Reverse Circular Linked List\n";
        cout << "4. Split Circular Linked List\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insert(value);
                break;

            case 2:
                traverse();
                break;

            case 3:
                reverse();
                break;

            case 4:
                splitList();
                break;

            case 0:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}
