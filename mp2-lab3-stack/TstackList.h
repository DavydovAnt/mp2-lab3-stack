#pragma once
#include <iostream> 
template <class T>
struct TNode {
	T val;				
	TNode<T> *pNext;	
};
template <class T>
class Tstack {
	TNode<T> *pFirst;
public:
	Tstack() {
		pFirst = NULL;
	}
	~Tstack() {
		TNode<T> *tmp = pFirst;
		while (pFirst != NULL) {
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;
		}
	}

	Tstack(const Tstack<T>& a) {
		if (p.pFirst == NULL)
			pFirst = NULL;
		else {
			TNode<T> *a = p.pFirst;
			TNode<T> *t = new TNode<T>;
			t->val = a->val;
			pFirst = t;
			while (a->pNext != NULL) {
				TNode<T> *tmp = new TNode<T>;
				t->pNext = tmp;
				a = a->pNext;
				tmp->val = a->val;
				t = tmp;
			}
			t->pNext = 0;
		}
	}

	bool IsEmpty()const {
		if (pFirst == NULL) return true;
		return false;
	}

	void push(const T& a) {
		if (isfull()) throw 1;
		TNode<T> *tmp = new TNode<T>;
		tmp->pNext = pFirst;
		tmp->val = a;
		pFirst = tmp;
	}

	T pop() {
		if (isempty()) throw 1;
		T res = pFirst->val;
		TNode<T> *tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
		return res;
	}
	T top() {
		if (isempty()) throw 1;
		return pFirst->val;
	}
	void clear() {
		TNode<T> *tmp = pFirst;
		while (pFirst != NULL) {
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;
		}
	}
	bool IsFull() {
		TNode<T> *p = new TNode<T>;
		if (p) {
			delete p;
			return false;
		}
		return true;
	}
};

