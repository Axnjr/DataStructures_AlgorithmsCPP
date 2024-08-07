// Stack follows LIFO approch: `Last in First Out`
#include <iostream> 
#include "ll_node.h"
#include <stack>
using namespace std;

template <typename T> class Stack {

    private:
        int size;
        int top;
        T* arr;

    public:

        Stack(int s) {
            size = s;
            arr = new T[s];
            top = -1;
            cout << "Stack of length: " << size << " intialized !!" << endl;
        }

        void push(T x){
            if(top == size - 1) {
                cout << "Error: Stack Overflow" << endl;
                return;
            }
            arr[++top] = x; // if top = -1; then it will be arr[0] and top will be 0 before only
        }

        T pop() {
            if(top == -1) {
                cout << "Error: Stack Underflow" << endl;
                return -1;
            }
            return arr[top--];
        }

        T peek() {
            return arr[top];
        }

        bool isEmpty() {
            return (top == -1);
        }

        void showStack() {
            cout << "Stack elements:" << endl;
           for(int i = size; i > 0; i--){
                cout << arr[i] << endl;
           }
        }
};

template <typename T> class StackAsLinkedList {
    private:
        Node<T>* head;

    public:
        int test;
        StackAsLinkedList() : head(NULL) {
            cout << "Stack as a linked list, initialized !!" << endl;
        }
    
        void push(T value){
            if(head == NULL){
                head->data = value;
            }
            else{
                Node<T>* tempNode = head;
                head->data = value;
                head->next = tempNode;
            }
        }

        void pop(){
            Node<T>* tempNode = head;
            head = head->next;
            delete tempNode;
        }

}

int main() {
    Stack<int> s(10);        
    for(int i = 10; i <= 100; i = i + 10){
        s.push(i);
    }
    while (!s.isEmpty()) {
        cout << s.peek() << endl;
        s.pop();
    }
    cout << "Your Stack: " << s.isEmpty() << endl;
    s.showStack();

    StackAsLinkedList<int> s();
    
    

	// stack<int> intStack;
    // stack<char> strStack;
	// for(int i = 0; i < 5; i++) {
	// 	intStack.push(i);
    //     strStack.push('a' + i);
	// }
    // cout << "Stack in int form: ";
    // while(!intStack.empty()) {
    //     cout << intStack.top() << " ";
    //     intStack.pop();
    // }
    // cout << endl;
    // cout << "Stack in char form: ";
    // while(!strStack.empty()) {
    //     cout << strStack.top() << " ";
    //     strStack.pop();
    // }
    return 0;
}
