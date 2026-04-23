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

class CircularLinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    CircularLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void insertAtHead(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = tail = newNode;
            newNode->next = head;
        }
        else {
            newNode->next = head;
            head = newNode;
            tail->next = head; 
        }

        size++;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = tail = newNode;
            newNode->next = head;
        }
        else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head; 
        }

        size++;
    }

    void insertAtPosition(int pos, int val) {
        if (pos < 1 || pos > size + 1) {
            cout << "Invalid position.\n";
            return;
        }

        if (pos == 1) {
            insertAtHead(val);
            return;
        }
        if (pos == size + 1) {
            insertAtEnd(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;

        for (int i = 1; i < pos - 1; i++)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;

        size++;
    }
    void display() {
            if (head == nullptr) {
                cout << "List is empty.\n";
                return;
            }

            Node* temp = head;
            cout << "List: ";

            do {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != head);

            cout << "\nSize: " << size << endl;
        }

    void deleteHead() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        }
        else {
            Node* toDelete = head;
            head = head->next;
            tail->next = head; 
            delete toDelete;
        }

        size--;
    }
    void deleteEnd() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }


        if (head == tail) {
            delete head;
            head = tail = nullptr;
        }
        else {
            Node* temp = head;

            while (temp->next != tail)
                temp = temp->next;

            Node* toDelete = tail;
            temp->next = head;
            tail = temp;

            delete toDelete;
        }

        size--;
    }

    void deleteAtPosition(int pos) {
        if (pos < 1 || pos > size) {
            cout << "Invalid position.\n";
            return;
        }

        if (pos == 1) {
            deleteHead();
            return;
        }
        if (pos == size) {
            deleteEnd();
            return;
        }

        Node* temp = head;

        for (int i = 1; i < pos - 1; i++)
            temp = temp->next;

        Node* toDelete = temp->next;
        temp->next = toDelete->next;

        delete toDelete;

        size--;
    }
};

int main() {
    CircularLinkedList list;

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
            list.insertAtEnd(val);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtHead(val);
            break;

        case 3:
            cout << "Enter position and value: ";
            cin >> pos >> val;
            list.insertAtPosition(pos, val);
            break;

        case 4:
            list.deleteEnd();
            break;

        case 5:
            list.deleteHead();
            break;

        case 6:
            cout << "Enter position: ";
            cin >> pos;
            list.deleteAtPosition(pos);
            break;

        case 7:
            list.display();
            break;

        case 8:
            return 0;

        default:
            cout << "Invalid choice.\n";
        }
    }
}
