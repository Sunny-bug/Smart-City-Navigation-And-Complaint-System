#include <iostream>
using namespace std;

// Doubly Linked List Node
struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

// ---------------- DISPLAY LIST ----------------
void display() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    cout << "List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// ---------------- QUESTION 1 ----------------
// Playlist App: Insert after current node
void insertAfterCurrent(int currentValue, int newValue) {
    Node* current = head;

    while (current != NULL && current->data != currentValue) {
        current = current->next;
    }

    if (current == NULL) {
        cout << "Current lecture not found\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = newValue;

    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != NULL)
        current->next->prev = newNode;
    else
        tail = newNode;

    current->next = newNode;

    cout << "Lecture added after current lecture\n";
}

// ---------------- QUESTION 2 ----------------
// Browser History: Insert at tail
void insertAtTail(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    cout << "New page added to browser history\n";
}

// ---------------- QUESTION 3 ----------------
// Shopping Cart: Delete last item (Undo)
void deleteLast() {
    if (tail == NULL) {
        cout << "Cart is empty\n";
        return;
    }

    Node* temp = tail;

    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }

    delete temp;
    cout << "Last item removed (Undo successful)\n";
}

// ---------------- MAIN MENU ----------------
int main() {
    int choice, value, currentValue;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Playlist: Add lecture after current\n";
        cout << "2. Browser History: Visit new page\n";
        cout << "3. Shopping Cart: Undo last item\n";
        cout << "4. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter current lecture value: ";
                cin >> currentValue;
                cout << "Enter_toggle new lecture value: ";
                cin >> value;
                insertAfterCurrent(currentValue, value);
                break;

            case 2:
                cout << "Enter page value: ";
                cin >> value;
                insertAtTail(value);
                break;

            case 3:
                deleteLast();
                break;

            case 4:
                display();
                break;

            case 0:
                cout << "Program exited\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}
