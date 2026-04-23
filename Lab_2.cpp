#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int *arr;
    int capacity;

public:
    
    Stack(int size) {
        arr = new int[size]; 
        capacity = size;
        top = -1;
    }


    void push(int x) {
        if (top < capacity - 1) {
            arr[++top] = x;
            cout << arr[top] << endl; 
        } else {
            cout << "Not pushed" << endl;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "empty" << endl;
        } else {
            cout << arr[top] << endl;  
            top--; 
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }
};

int main() {
    Stack s(5); 

    cout << s.isEmpty() << endl;

    s.push(10);
    s.push(20);
    s.pop();
    s.pop();
    s.pop();

    //cout << s.isFull() << endl;
    return 0;
}
