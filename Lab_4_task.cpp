#include <iostream>
#include <string>
using namespace std;

class Printer {
private:
    int front, rear, size, capacity;
    string* arr;  

public:
    Printer(int capacity) {
        this->capacity = capacity;
        this->front = this->rear = -1;
        this->size = 0;
        this->arr = new string[capacity]; 
    }

    void enqueue(string job) {
        if (isfull()) {
            cout << "Printer queue is full" << endl;
            return;
        }
        if (isEmpty()) {
            rear = front = 0;
            arr[rear] = job;
        } else {
            rear = (rear + 1) % capacity;
            arr[rear] = job;
        }
        size++;
        cout << job << " added to printer queue" << endl;
    }

    string dequeue() {
        if (isEmpty()) {
            cout << "Printer queue is empty" << endl;
            return "";
        }

        string job = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        size--;
        cout << job << " dequeued from print queue" << endl;
        return job;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isfull() {
        return size == capacity;
    }
    string peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return "";
        }
        return arr[front];
    }
    int getSize() {
        return size;
    }

    void display() {
        if (isEmpty()) {
            cout << "Printer queue is empty" << endl;
            return;
        }
        cout << "Jobs in printer queue: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    Printer p(5);
    
    p.enqueue("Document1");
    p.enqueue("Document2");
    p.enqueue("Document3"); 
    p.enqueue("Document4");
    p.enqueue("Document5");
    p.display();
    p.dequeue();
    p.display();
    cout<<"Queue size: "<<p.getSize()<<endl;

    return 0;
}
