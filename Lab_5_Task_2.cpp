#include <iostream>
using namespace std;

#define SIZE 5

class CallCenter {
    int calls[SIZE];
    int front, rear;

public:
    CallCenter() {
        front = rear = -1;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    void receiveCall(int callID) {
        if (isFull()) {
            cout << "Call queue is full! Please wait." << endl;
            return;
        }

        if (front == -1)
            front = 0;

        calls[++rear] = callID;
        cout << "Received call ID: " << callID << endl;
    }

    void answerCall() {
        if (isEmpty()) {
            cout << "No calls waiting." << endl;
            return;
        }

        cout << "Answering call ID: " << calls[front] << endl;
        front++;

        if (front > rear)
            front = rear = -1; // reset when queue is empty
    }

    void pendingCalls() {
        if (isEmpty()) {
            cout << "No pending calls." << endl;
            return;
        }

        cout << "Pending calls: ";
        for (int i = front; i <= rear; i++) {
            cout << calls[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    CallCenter center;

    center.receiveCall(101);
    center.receiveCall(102);
    center.receiveCall(103);
    center.receiveCall(104);
    center.receiveCall(105);

    cout << endl;
    center.answerCall();
    center.answerCall();
    center.pendingCalls();

    return 0;
}
