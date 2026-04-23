#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define MAX 100

/* ================= STRUCTS ================= */

struct Complaint {
    int id;
    string citizenName, description, status;
    Complaint* next;
};

struct Citizen {
    int id;
    string name, phone;
};

/* ================= GLOBAL DATA ================= */

Complaint* head = NULL;

// Stack (Undo)
Complaint undoStack[MAX];
int top = -1;

// Queue (Service)
Complaint serviceQueue[MAX];
int front = 0, rear = -1, qSize = 0;

/* ================= STACK ================= */

bool stackEmpty() { return top == -1; }
void push(Complaint c) { if (top < MAX - 1) undoStack[++top] = c; }
Complaint pop() { return undoStack[top--]; }

/* ================= QUEUE ================= */

bool queueEmpty() { return qSize == 0; }

void enqueue(Complaint c) {
    if (qSize == MAX) return;
    rear = (rear + 1) % MAX;
    serviceQueue[rear] = c;
    qSize++;
}

Complaint dequeue() {
    Complaint c = serviceQueue[front];
    front = (front + 1) % MAX;
    qSize--;
    return c;
}

/* ================= FILE HANDLING ================= */

void saveComplaint(Complaint c) {
    ofstream file("complaints.txt", ios::app);
    file << c.id << "|" << c.citizenName << "|"
         << c.description << "|" << c.status << endl;
}

void rewriteFile() {
    ofstream file("complaints.txt");
    for (Complaint* t = head; t; t = t->next)
        file << t->id << "|" << t->citizenName << "|"
             << t->description << "|" << t->status << endl;
}

/* ================= LINKED LIST ================= */

void addComplaint() {
    Complaint* n = new Complaint;
    cout << "ID: "; cin >> n->id; cin.ignore();
    cout << "Citizen Name: "; getline(cin, n->citizenName);
    cout << "Description: "; getline(cin, n->description);

    n->status = "Pending";
    n->next = head;
    head = n;

    enqueue(*n);
    saveComplaint(*n);

    cout << "Complaint Added.\n";
}

void displayComplaints() {
    if (!head) return cout << "No complaints.\n", void();

    for (Complaint* t = head; t; t = t->next) {
        cout << "ID: " << t->id
             << "\nCitizen: " << t->citizenName
             << "\nIssue: " << t->description
             << "\nStatus: " << t->status
             << "\n------------------\n";
    }
}

Complaint* findComplaint(int id) {
    for (Complaint* t = head; t; t = t->next)
        if (t->id == id) return t;
    return NULL;
}

void deleteComplaint() {
    int id; cout << "Enter ID: "; cin >> id;

    Complaint *t = head, *p = NULL;
    while (t && t->id != id) { p = t; t = t->next; }

    if (!t) return cout << "Not found.\n", void();

    push(*t);
    if (!p) head = t->next;
    else p->next = t->next;

    delete t;
    rewriteFile();
    cout << "Deleted.\n";
}

void undoDelete() {
    if (stackEmpty()) return cout << "Nothing to undo.\n", void();

    Complaint c = pop();
    Complaint* n = new Complaint(c);
    n->next = head;
    head = n;

    saveComplaint(c);
    enqueue(c);
    cout << "Undo successful.\n";
}

void updateStatus() {
    int id, ch;
    cout << "ID: "; cin >> id;

    Complaint* c = findComplaint(id);
    if (!c) return cout << "Not found.\n", void();

    cout << "1.Pending 2.In Process 3.Resolved: ";
    cin >> ch;

    if (ch == 1) c->status = "Pending";
    else if (ch == 2) c->status = "In Process";
    else if (ch == 3) c->status = "Resolved";
    else return cout << "Invalid.\n", void();

    rewriteFile();
    cout << "Updated.\n";
}

/* ================= SORTING ================= */

int toArray(Complaint arr[]) {
    int i = 0;
    for (Complaint* t = head; t && i < MAX; t = t->next)
        arr[i++] = *t;
    return i;
}

void bubbleSort(Complaint a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j].id > a[j + 1].id)
                swap(a[j], a[j + 1]);
}

void showSorted() {
    Complaint arr[MAX];
    int n = toArray(arr);
    bubbleSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i].id << " | "
             << arr[i].citizenName << " | "
             << arr[i].status << endl;
}

/* ================= CITIZENS ================= */

void addCitizen() {
    Citizen c;
    cout << "ID: "; cin >> c.id; cin.ignore();
    cout << "Name: "; getline(cin, c.name);
    cout << "Phone: "; getline(cin, c.phone);

    ofstream file("citizens.txt", ios::app);
    file << c.id << "|" << c.name << "|" << c.phone << endl;

    cout << "Citizen Added.\n";
}

void displayCitizens() {
    ifstream file("citizens.txt");
    Citizen c;

    while (file >> c.id) {
        file.ignore();
        getline(file, c.name, '|');
        getline(file, c.phone);
        cout << "ID: " << c.id
             << "\nName: " << c.name
             << "\nPhone: " << c.phone
             << "\n------------------\n";
    }
}

/* ================= QUEUE SERVICE ================= */

void serviceComplaint() {
    if (queueEmpty()) return cout << "Queue empty.\n", void();

    Complaint c = dequeue();
    cout << "Servicing ID: " << c.id
         << "\nCitizen: " << c.citizenName << endl;
}

/* ================= MENU ================= */

void menu() {
    cout << "\n1.Add Complaint\n2.View Complaints\n3.Delete\n4.Undo\n"
         << "5.Update Status\n6.Service\n7.Sort\n8.Add Citizen\n"
         << "9.View Citizens\n0.Exit\n";
}

int main() {
    int ch;
    do {
        menu();
        cin >> ch;
        switch (ch) {
            case 1: addComplaint(); break;
            case 2: displayComplaints(); break;
            case 3: deleteComplaint(); break;
            case 4: undoDelete(); break;
            case 5: updateStatus(); break;
            case 6: serviceComplaint(); break;
            case 7: showSorted(); break;
            case 8: addCitizen(); break;
            case 9: displayCitizens(); break;
        }
    } while (ch != 0);

    return 0;
}
