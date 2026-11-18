#include <iostream>
using namespace std;

const int MAX = 5;
int queueArr[MAX];
int frontIdx = 0;
int rearIdx = -1;

bool isEmpty() {
    return frontIdx > rearIdx;
}

bool isFull() {
    return rearIdx == MAX - 1;
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow! Queue is full, " << value << " cannot be inserted." << endl;
        return;
    }
    rearIdx++;
    queueArr[rearIdx] = value;
    cout << value << " inserted successfully." << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow! Queue is empty." << endl;
        return;
    }
    int removed = queueArr[frontIdx];
    frontIdx++;
    cout << removed << " removed successfully." << endl;
    if (isEmpty()) {
        frontIdx = 0;
        rearIdx = -1;
    }
}
void front() {
    if (isEmpty()) {
        cout << "Queue is empty. Nothing at the front." << endl;
        return;
    }
    cout << "Front element: " << queueArr[frontIdx] << endl;
}
void display() {
    cout << "Queue: ";
    if (isEmpty()) {
        cout << "(empty)";
    } else {
        for (int i = frontIdx; i <= rearIdx; i++) {
            cout << queueArr[i] << " ";
        }
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
        cout << "\n===== QUEUE MENU =====" << endl;
        cout << "1. Enqueue  2. Dequeue" << endl;
        cout << "3. Front  4. Display  5. Exit" << endl;
        cout << endl;
        display();
        choice = readInt("Choose operation: ");

        switch (choice) {
            case 1: {
                int value = readInt("Enter value: ");
                enqueue(value);
                break;
            }
            case 2: dequeue(); break;
            case 3: front(); break;
            case 4: display(); break;
            case 5: cout << "Program finished." << endl; break;
            default: cout << "Invalid choice, pick 1-5." << endl;
        }
    } while (choice != 5);

    return 0;
}
