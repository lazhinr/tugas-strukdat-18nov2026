#include <iostream>
using namespace std;

const int MAX = 50;
char stackArr[MAX];
int top = -1;

bool isEmpty() {
    return top == -1;
}
bool isFull() {
    return top == MAX - 1;
}
void push(char c) {
    if (isFull()) {
        cout << "Stack Overflow! Word is too long." << endl;
        return;
    }
    top++;
    stackArr[top] = c;
}
char pop() {
    if (isEmpty()) {
        cout << "Stack Underflow!" << endl;
        return '\0';
    }
    char c = stackArr[top];
    top--;
    return c;
}

int main() {
    char word[MAX];
    char reversed[MAX];
    cout << "Enter a word: ";
    cin.getline(word, MAX);
    int length = 0;
    while (word[length] != '\0') {
        length++;
    }
    if (length == 0) {
        cout << "\nNo word entered." << endl;
        return 0;
    }
    for (int i = 0; i < length; i++) {
        push(word[i]);
    }
    int index = 0;
    while (!isEmpty()) {
        reversed[index] = pop();
        index++;
    }
    reversed[index] = '\0';

    cout << "\nOriginal word: " << word << endl;
    cout << "Reversed word: " << reversed << endl;

    return 0;
}
