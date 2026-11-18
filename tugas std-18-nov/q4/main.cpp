#include <iostream>
using namespace std;

const int MAX = 5;
int queueArr[MAX];
int frontIdx = 0;
int rearIdx = -1;
int itemCount = 0;
bool isEmpty() {
    return itemCount == 0;
}

bool isFull() {
    return itemCount == MAX;
}
void enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow! Queue is full, " << value << " cannot be inserted." << endl;
        return;
    }
    rearIdx = (rearIdx + 1) % MAX;
    queueArr[rearIdx] = value;
    itemCount++;
    cout << value << " inserted successfully." << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow! Queue is empty." << endl;
        return;
    }
    int removed = queueArr[frontIdx];
    frontIdx = (frontIdx + 1) % MAX;
    itemCount--;
    cout << removed << " removed successfully." << endl;
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
        for (int i = 0; i < itemCount; i++) {
            int idx = (frontIdx + i) % MAX;
            cout << queueArr[idx] << " ";
        }
    }
    cout << endl;
}
void showArray() {
    cout << "Array : ";
    for (int i = 0; i < MAX; i++) {
        cout << "[" << i << "]";
    }
    cout << endl << "Isi   : ";
    for (int i = 0; i < MAX; i++) {
        bool terisi = false;
        for (int k = 0; k < itemCount; k++) {
            if ((frontIdx + k) % MAX == i) terisi = true;
        }
        if (terisi) cout << " " << queueArr[i] << " ";
        else cout << " - ";
    }
    cout << endl << "front = " << frontIdx << ", rear = " << rearIdx
         << ", itemCount = " << itemCount << endl;
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

void mandatoryTest() {
    cout << "===== MANDATORY TEST (10 STEPS) =====" << endl;
    cout << "Steps 1-5: Enqueue 10, 20, 30, 40, 50" << endl;
    enqueue(10); enqueue(20); enqueue(30); enqueue(40); enqueue(50);

    cout << "\nSteps 6-7: Dequeue twice" << endl;
    dequeue(); dequeue();

    cout << "\nSteps 8-9: Enqueue 60, 70 (wraps around)" << endl;
    enqueue(60); enqueue(70);

    cout << "\nStep 10: Display queue" << endl;
    display();
    showArray();
    cout << endl;
}

int main() {
    mandatoryTest();
    int choice;
    do {
        cout << "\n===== CIRCULAR QUEUE MENU =====" << endl;
        cout << "1. Enqueue  2. Dequeue" << endl;
        cout << "3. Front  4. Display  5. Exit" << endl;
        cout << endl;
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
        if (choice >= 1 && choice <= 4) showArray();
    } while (choice != 5);

    return 0;
}
