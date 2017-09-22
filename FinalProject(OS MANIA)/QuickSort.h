
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <stdio.h>

using namespace std;

class Link{
public:
	string data;
	Link* pNext;
	Link* pPrevious;
public:
	Link(){
		data = "";
		pNext = NULL;
		pPrevious = NULL;
	}
	Link(string k){
		data = k;
		pNext = NULL;
		pPrevious = NULL;
	}

};

class DoublyLinkedList{
private:
	Link* pFirst;
	Link* pLast;
public:
	DoublyLinkedList() : pFirst(NULL), pLast(NULL){}
	//======================================================================
	~DoublyLinkedList(){
		Link* pCurrent = pFirst;
		while (pCurrent != NULL){
			Link* pOldCur = pCurrent;
			pCurrent = pCurrent->pNext;
			delete pOldCur;
		}
	}
	//======================================================================
	bool isEmpty(){
		return pFirst == NULL;
	}
	//======================================================================
	void insertFirst(string k){
		Link* pNewLink = new Link(k);

		if (isEmpty())
			pLast = pNewLink;
		else
			pFirst->pPrevious = pNewLink;
		pNewLink->pNext = pFirst;
		pFirst = pNewLink;
	}
	//======================================================================
	void swap(string* a, string* b)
	{
		string t = *a;      *a = *b;       *b = t;
	}

	//======================================================================
	Link *lastNode(Link *root)
	{
		while (root && root->pNext)
			root = root->pNext;
		return root;
	}
	//======================================================================
	Link* partition(Link *l, Link *h)
	{
		// set pivot as h element
		string x = h->data;

		// similar to i = l-1 for array implementation
		Link *i = l->pPrevious;

		// Similar to "for (int j = l; j <= h- 1; j++)"
		for (Link *j = l; j != h; j = j->pNext)
		{
			if (j->data <= x)
			{
				// Similar to i++ for array
				i = (i == NULL) ? l : i->pNext;

				swap(&(i->data), &(j->data));
			}
		}
		i = (i == NULL) ? l : i->pNext; // Similar to i++
		swap(&(i->data), &(h->data));

		return i;
	}
	//======================================================================
	void _quickSort(Link* l, Link *h)
	{
		if (h != NULL && l != h && l != h->pNext)
		{
			Link *p = partition(l, h);
			_quickSort(l, p->pPrevious);
			_quickSort(p->pNext, h);
		}
	}
	//======================================================================
	void quickSort()
	{
		// Find last node
		Link *h = lastNode(pFirst);

		// Call the recursive QuickSort
		_quickSort(pFirst, h);
	}
	//======================================================================
	void printToFile(ofstream &out){
		Link* temp = pFirst;

		while (temp != NULL){
			out << temp->data << endl;

			temp = temp->pNext;
		}
	}
};