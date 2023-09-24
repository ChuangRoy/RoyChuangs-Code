// C_CPP/CppProjects/1.\ School/stack_in_list/
#define STACK_SIZE 100
#include <iostream>
using namespace std;

void push (int);
int pop();
void printStack();

struct Stack {
    int s[STACK_SIZE];
    int top;
    Stack () {top=-1;}
};
Stack st;
int main () {
    int a, n;
    while (1) {
        cout << "Choose a work to do:" << endl;
        cout << "1.push" << endl;
        cout << "2.delete" << endl;
        cout << "3.print" << endl;
        cout << "4.exit" << endl;
        cin >> a;
        switch (a) {
        case 1:
            cin >> n;
            push(n);
            break;
        case 2:
            cout << "Delete last element of stack: "
                    << pop() << endl;
            break;
        case 3:
            printStack();
            break;
        case 4:
            return 0;
    }
    return 0;
}

void push(int n) {
    if (st.top == 99) {
        cout << "Stack is full. " << endl;
    } else {
        st.s[++st.top] = n;
    }
}

int pop () {
    if (st.top == -1) {
        cout << "Stack is empty. " << endl;
    } else {
        return st.s[st.top--];
    }
}

void printStack () {
    for (int i = 0; i <= st.top; i++) {
        cout << st.s[i] << " " ;
    }
    cout << endl;
}