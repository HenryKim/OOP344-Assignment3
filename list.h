/*
	OOP344 Winter 2014 Assignment 3
	list .h
	Hyungi Kim
	025 741 125
	To Prof. Kamal-Al-Deen, Hasan 
*/
#include <iostream>
using namespace std;


template <class T>
class ListNode {
	template <class U>
	friend class List;
	T _val;
	ListNode<T>* _next;

protected:
	void next(ListNode<T>* next) { _next = next;}

public:
	ListNode(const T& val = T(), ListNode<T>* next = NULL) : _val(val), _next(next) {}  //ctor

	ListNode(const ListNode<T>& src) : _val(src.val()), _next(NULL) {} //cc

	ListNode& operator=(const ListNode<T>& src)  {
		/* assignment op */
		if (this != &src)
		{
			_val = src.val();
			_next = NULL;
		}
		return *this;
	}

	
	~ListNode() { } //dtor

	T val() const {return _val;}    

	void val(const T& val) {_val = val; }

	ListNode<T>* next() const {return _next;}
};




template <class T>
class List  {
private:
	ListNode<T>* _head;
	int _size;

public:
	List() : _head(NULL), _size(0) {} //ctor

	
	List(const List<T>& src) { //cc
		_size = 0;
		*this = src;
	}
	~List(){
		this->clear();
	}

	List<T>& operator=(const List<T>& src) {
		/*assign op*/
		if (this != &src)
		{
			ListNode<T>* n = src.head();		
			clear();
			int srcsize = src.size();

			while (srcsize--)
			{
				push(n->val());
				n = n->next();
			}
		}

		return *this;
	}

	int size() const {return _size;}

	ListNode<T>* head() const {return _head;}

	void push(const T& val) {
		ListNode<T>* h = new (nothrow) ListNode<T> (val, NULL);

		if (h)
		{	
			ListNode<T>* tmp = _head;

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

	void pop() {

		if (_head)
		{
			ListNode<T>* prev = _head;
			ListNode<T>* h = _head;

			while(h->next())
			{
				prev = h;
				h = h->next();			
			}		

			if (prev)
				prev->next(NULL);

			delete h;
			_size--;
		}

		if (_size == 0)
			_head = NULL;
	}

	void clear() {
		while(size()){
			this->pop();
		}
	}

};
