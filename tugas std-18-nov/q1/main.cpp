#include <iostream>
using namespace std;

const int MAX = 5;
int stackArr[MAX];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX - 1;
}
void push(int value) {
    if (isFull()) {
        cout << "Stack Overflow! Stack is full, " << value << " cannot be inserted." << endl;
        return;
    }
    top++;
    stackArr[top] = value;
    cout << value << " inserted successfully." << endl;
}
void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! Stack is empty." << endl;
        return;
    }
    int removed = stackArr[top];
    top--;
    cout << removed << " removed successfully." << endl;
}
void peek() {
    if (isEmpty()) {
        cout << "Stack is empty. Nothing to peek." << endl;
        return;
    }
    cout << "Top element: " << stackArr[top] << endl;
}
void display() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack (top -> bottom): ";
    for (int i = top; i >= 0; i--) {
        cout << stackArr[i] << " ";
    }
    cout << endl;
}
int readInt(const char* prompt) {
    int x;
    cout << prompt;
    while (!(cin >> x)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Input must be a number. Try again: ";
    }
    return x;
}
int main() {
    int choice;
    do {
        cout << "\n===== STACK MENU =====" << endl;
        cout << "1. Push  2. Pop  3. Peek" << endl;
        cout << "4. Display  5. Exit" << endl;
        choice = readInt("\nChoose operation: ");

        switch (choice) {
            case 1: {
                int value = readInt("Enter value: ");
                push(value);
                break;
            }
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: cout << "Program finished." << endl; break;
            default: cout << "Invalid choice, pick 1-5." << endl;
        }
    } while (choice != 5);

    return 0;
}
