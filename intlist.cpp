/*
	OOP344 Winter 2014 Assignment 3
	intlist .cpp
	Hyungi Kim
	025 741 125
	To Prof. Kamal-Al-Deen, Hasan 
*/
#include "intlist.h"



IntListNode::IntListNode(int v, IntListNode* n) //ctor
{
	_val = v;
	_next = n;
}

IntListNode::IntListNode(const IntListNode& src)  //cc
{

	_val = src.val();
	_next = NULL;
}

IntListNode& IntListNode::operator=(const IntListNode& src) //assign op
{
	if (this != &src)
	{
		_val = src.val();
		_next = NULL;
	}
	return *this;
}


IntListNode::~IntListNode() {} //dtor


void IntListNode::next(IntListNode* next)
{
	_next = next;
}


int IntListNode::val() const 
{
	return _val;
}

void IntListNode::val(int val)
{
	_val = val;
}


IntListNode* IntListNode::next() const
{
	return _next;
}



IntList::IntList() //ctor
{
	_size = 0;
	_head = NULL;
}


IntList::IntList(const IntList& src) //cc
{
	_size = 0;
	*this = src;
}


IntList& IntList::operator=(const IntList& src) //assign op
{
	if (this != &src)
	{
		IntListNode* h = src.head();		
		clear();
		int srcsize = src.size();

		while (srcsize--)
		{
			push(h->val());
			h = h->next();
		}
	}

	return *this;
}
IntList::~IntList(){
	clear();
}

int IntList::size() const
{
	return _size;
}

IntListNode* IntList::head() const
{
	return _head;
}

void IntList::push(int val)
{
	IntListNode* h = new (nothrow) IntListNode(val, NULL);

	if (h)
	{	
		IntListNode* tmp = _head;

		if (_size)
		{
			while(tmp)
			{
				if (!tmp->next())
				{					
					tmp->next(h);
					_size++;
					break;
				}
				tmp = tmp->next();
			}
		}
		else
		{
			_head = h;
			_size++;
		}
	}
}


void IntList::pop() 
{
	if (_head)
	{
		IntListNode* prev = _head;
		IntListNode* h = _head;

		while(h->next())
		{
			prev = h;
			h = h->next();			
		}		

		if (prev)
			prev->next(NULL);

		_size--;

	}

	if (_size == 0)
		_head = NULL;
}



void IntList::clear()
{
	while (this->size()){
		this->pop();
	}
}
