/*
	OOP344 Winter 2014 Assignment 3
	intlist .h
	Hyungi Kim
	025 741 125
	To Prof. Kamal-Al-Deen, Hasan 
*/
#include <iostream>
using namespace std;


class IntListNode {
	friend class IntList;
	int _val;
	IntListNode* _next;

protected:
	void next(IntListNode*);

public:

	IntListNode(int v = int(), IntListNode* n = NULL);     
	IntListNode(const IntListNode& src);    
	IntListNode& operator=(const IntListNode& src);
	~IntListNode();
	int val() const;    
	void val(int);
	IntListNode* next() const;
};



class IntList  {
	IntListNode* _head;
	int _size;

public:
	IntList();
	IntList(const IntList& src);
	IntList& operator=(const IntList& src);
	~IntList();
	int size() const;
	IntListNode* head() const;
	void push(int v);
	void pop();
	void clear();
};