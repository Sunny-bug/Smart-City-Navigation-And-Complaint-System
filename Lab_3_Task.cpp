#include <iostream>
#include <string>
using namespace std;

// Class representing a stack of dishes
class DishStak {
private:
    int top;           // Index of the top element in the stack
    int capacity;      // Maximum number of dishes that can be stored
    string* arr;       // Dynamic array to hold dish names

public:
    // Constructor to initialize stack with given size
    DishStak(int size) { 
        capacity = size;
        arr = new string[capacity]; // Allocate memory for 'size' dishes
        top = -1;                   // Empty stack (no elements yet)
    }

    // Function to push new dish into stack
    void pushDish(string dish) {
        if (top < capacity - 1) {         // Check if stack is not full
            arr[++top] = dish;            
            cout << "Order Placed " << dish << endl;
        } else {
            cout << "Kitchen full can not place " << dish << endl;
        }
    }

    // Function to remove the top dish
    void popDish() {
        if (top >= 0) {                    // Check if stack is not empty
            cout << "Order Removed " << arr[top] << endl;
            top--;                         // Decrease top index (removes dish)
        } else {
            cout << "There is no order to show" << endl;
        }
    }

    // Function to display all dishes currently in the stack
    void displayAllDishes() {
        if (top == -1) {                   // Empty stack check
            cout << "No dishes to display." << endl;
            return;                       // Exit early to avoid printing list
        }
        cout << "All dishes in stack:" << endl;
        for (int i = 0; i <= top; ++i) {  // Print all dishes one by one
            cout << i + 1 << ". " << arr[i] << endl;
        }
        cout << endl;
    }
};

int main() {
    DishStak stack(3);  // Create a stack with capacity of 5 dishes
    int choice;
    do {
        // Display menu options for user
        cout << "\n1. Push Dish\n2. Pop Dish\n3. Display All Dishes\n4. Exit\nEnter your choice: ";
        cin >> choice;
        cin.ignore();  // Ignore newline character left in input buffer

        switch (choice) {
            case 1: {
                string dish;
                cout << "Enter dish name to push: \n1. Biryani\n2. Karahi\n3. Saag\n4. Missi Roti\n  ";
                getline(cin, dish);       // Get full dish name (can include spaces)
                stack.pushDish(dish);     // Call push function
                break;
            }
            case 2:
                stack.popDish();           // Call pop function
                break;
            case 3:
                stack.displayAllDishes();  // Call display function
                break;
            case 4:
                cout << "Thank You for Your Visit" << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);   // Repeats menu until user chooses Exit

    return 0;
}
