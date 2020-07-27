#pragma once
class Stack
{
private:
	int size;
	int top;
	int* S;
public:
	Stack(int s,int elem);
	void push(int x);
	int pop();
	int peek(int index);
	int stackTop();
	bool isEmpty();
	bool isFull();
	void display();
	~Stack();
};


