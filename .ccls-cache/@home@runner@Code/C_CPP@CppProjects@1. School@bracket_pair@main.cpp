// C_CPP/CppProjects/1.\ School/bracket_pair
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
    string s;
    int n = 0;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i]=='{') {
            push(1);
        }else if (s[i]=='}'){
            if (st.top == -1) {
                n = -1;
                break;
            }else{
                pop();
                n++;
            }
        }
    }
    if (st.top == -1 && n >= 0) {
        cout << n << " pairs of brackets. " << endl;
    } else {
        cout << "Paired fail" << endl;
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