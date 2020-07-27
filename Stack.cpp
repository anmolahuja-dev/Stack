#include <iostream>
#include "Stack.h"
using namespace std;

bool Stack::isFull() {
	if ( top == size-1) {
		return true;
	}
	else {
		return false;
	}
}

bool Stack::isEmpty() {
	if (top == -1) {
		return true;
	}
	else {
		return false;
	}
}

int Stack::stackTop() {
	if (top != -1) {
		return S[top];
	}
	else {
		return -1;
	}
}

void Stack::push(int x) {
	if (isFull()) {
		cout << "\nStack Overflow" << endl;
	}
	else {
		top++;
		S[top] = x;
	}
}

int Stack::pop() {
	int x = -1;
	if (isEmpty()) {
		cout << "\nStack Underflow" << endl;
	}
	else {
		x = S[top];
		top--;
	}
	return x;
}

int Stack::peek(int index) {
	int x = -1;
	if (top - index + 1 < 0) {
		cout << "\n Invalid position" << endl;
	}
	else {
		x = S[top - index + 1];
	}
	return x;
}

Stack::Stack(int size, int elem) {
	this->size = size;
	S = new int[size];
	top = -1;
	if (size < elem) {
		cout << "\nYou cannot Enter Elements greater than the size of the Stack "<<endl;
		int x = elem-size;
		elem = elem - x;
		cout << "Reduced the number of elements to the size of the Stack" << endl;
	}
	cout << "\nEnter" << elem << " Elements : "<<endl;
	
	for (int i = 0; i < elem; i++) {
		cout << "Enter " << i + 1 << " Element : ";
		top = i;
		cin >> S[i];
	}
	
}

void Stack::display() {
	for (int i = top; i >= 0; i--) {
		cout << S[i] << endl;
	}
	cout << endl;
}

Stack::~Stack() {
	delete[] S;
}

int main() {
	cout << "######### STACK (USING ARRAYS) #############" << endl;
	cout << "\nLet's Create a Stack of integers" << endl;
	cout << "Enter the size of the Stack : ";
	int size{ 0 };
	cin >> size;
	cout << "\nAnd How many elements , do you want to add in this Stack : ";
	int elem;
	cin >> elem;
	Stack St(size, elem);
	cout << "\The Stack is " << endl;
	St.display();

	int ch{ 0 };
	do {
		cout << "\nEnter the operation, you want to perform on the Stack" << endl;
		cout << "[1] - Push an Element into the stack" << endl;
		cout << "[2] - Pop an Element from the stack" << endl;
		cout << "[3] - Peek an Element from the stack" << endl;
		cout << "[4] - Get the Top Element from the stack" << endl;
		cout << "[5] - Check if the stack is Empty ? " << endl;
		cout << "[6] - Check if the stack is Full ? " << endl;
		cout << "[7] - Display the Stack! " << endl;
		cout << "[0] - Quit " << endl;
		cout << "\nEnter your choice : ";
		cin >> ch;

		if (ch == 1) {
			int x{ 0 };
			cout << "\nEnter the element, you want to push to the Stack : ";
			cin >> x;
			St.push(x);
			St.display();
		}
		else if (ch == 2) {
			if (St.pop() != -1) {
				cout << "\nRemoved the top element successfully" << endl;
			}
			else {
				cout << "\nUnable to remove element" << endl;
			}
			St.display();
		}
		else if (ch == 3) {
			int index{ 0 };
			cout << "Enter the Index, you want to peek from the stack : ";
			cin >> index;
			int x = St.peek(index);
			if (x != -1) {
				cout << "\n The element is : " << x << endl;
			}
			else {
				cout << "\nCould not get the element" << endl;
			}

		}
		else if (ch == 4) {
			int x = St.stackTop();
			if (x != -1) {
				cout << "\nThe Top element in the Stack is : " << x << endl;
			}
			else {
				cout << "\nStack is empty!" << endl;
			}
		}
		else if (ch == 5) {
			
			if (St.isEmpty()) {
				cout << "\nThe Stack is Empty! " << endl;
			}
			else {
				cout << "\nStack is not empty!" << endl;
			}
		}
		else if (ch == 6) {

			if (St.isFull()) {
				cout << "\nThe Stack is Full! " << endl;
			}
			else {
				cout << "\nStack is not Full!" << endl;
			}
		}
		else if (ch == 7) {
			St.display();
		}
	} while (ch != 0);
}