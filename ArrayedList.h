#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX_CELLS 5
using namespace std;

template<typename T> struct Cell 
{
    T info[MAX_CELLS];
    int filled_Subcells;
    Cell<T> *next, *prev;

};

template <typename T> class ArrayedList {
    private:
        Cell<T> *head, *tail;
        int cellCount; // Counter for added nodes;
        int total_Elems; // counter for each time inserting in table
        Cell<T>* createNode(T x);
        void removeFromCell(Cell<T> *node, int idxRemove);
       	void shiftAllNodes(Cell<T>* start);
    public:
    	void add(T x);
    	void remove(int i);
    	int isEmpty();
    	T getElement(int i);
    	void display();
    	void displayList();
    	ArrayedList();
};

template<typename T>
ArrayedList<T>::ArrayedList() 
{
	cellCount = 0;
	total_Elems = 0;
    head = tail = NULL;
}


template<typename T>
Cell<T>* ArrayedList<T>::createNode(T x)
{
    Cell<T> *newNode;
    newNode = new Cell<T>;
    newNode->filled_Subcells = 0;
    newNode->info[newNode->filled_Subcells++] = x;
    newNode->prev = NULL;
    newNode->next = NULL;

        return newNode;
}

template<typename T>
void ArrayedList<T>::add(T x) 
{
	cout<<"Added " << x << '.' << endl; 

    if (head == NULL)
    {
    	tail = head = createNode(x);
    	total_Elems++;
    	cellCount++;
    }
    else
    {
    	if(tail->filled_Subcells < 5)
    	{
    		tail->info[tail->filled_Subcells++] = x;

    		total_Elems++;
    	}

    	else
    	{
    		Cell<T>* aux;
    		aux = createNode(x);
    		tail->next = aux;
    		aux->prev = tail;
    		tail = aux;

    		cellCount++;
    		total_Elems++;
    	}
    }

}

template<typename T>
T ArrayedList<T>::getElement(int idx)
{
	Cell<T> *f;

	// cout<<"Total elems: " << total_Elems<<endl;
	// cout<<"idx to getElement = " << idx << endl;

	f = head;
	int j = 0;
	while (f != NULL)
	{
		for(int i = 0; i < f->filled_Subcells; i++)
		{
			if(j == idx)
			{
				return f->info[i]; 
			}

			j++;
			// cout <<"j = " << j <<", i = " << i << endl;
		}

		f = f->next;
	} 
	cout<<"Element at pos: "<< idx <<  " was not found."<<endl;
	T nil;
	return nil;
}


template<typename T>
void ArrayedList<T>::remove(int idx)
{ 

	Cell<T> *f, *saveItToFixIt;


	f = head;
	int j = 0;
	while (f != NULL)
	{
		saveItToFixIt = f->prev;

		int n = f->filled_Subcells;
		if(n < idx) 
		{
			cout<<"Error, element at [" <<idx<< "] doenst exist!" << endl;
			return;
		}  
		for(int i = 0; i < n; i++)
		{
			if(j == idx)
			{
				// cout<<"REMOVING "<<i;
				cout<<"Removed " << f->info[i]<<endl;
				for(int k = i; k < f->filled_Subcells; k++)
				{
					f->info[k] = f->info[k+1];
				}
				f->filled_Subcells = f->filled_Subcells - 1;
			}

			j++;

		}

		f = f->next;
	} 

	if(saveItToFixIt != NULL)
	{
		shiftAllNodes(saveItToFixIt);

		Cell<T>* Delete_if_empty;
		Delete_if_empty = saveItToFixIt->next;

			// cout<<"FILLED CELLS "<<saveItToFixIt->filled_Subcells<<endl;
		if (Delete_if_empty->filled_Subcells == 0) 
		{ 
			delete Delete_if_empty;
			Delete_if_empty = NULL;
			saveItToFixIt->next = NULL;
			cellCount--;
	    }
	}
}


template<typename T>
int ArrayedList<T>::isEmpty()
{
	return (head == NULL);
}



template<typename T>
void ArrayedList<T>::display()
{

	Cell<T> *p;

	p = head;
	while (p != NULL)
	{
		for(int i = 0; i < p->filled_Subcells; i++)
		{
			cout << p->info[i] << " ";
		}
		cout <<endl<<endl;
		p = p->next;
	}

}

template<typename T>
void ArrayedList<T>::displayList()
{
	Cell<T> *p;
	
	p = head;
	cout << "Head-->"; 
	while (p != NULL)
	{
		cout<<'|';
		for(int i = 0; i < p->filled_Subcells; i++)
		{
			cout <<" "<< p->info[i] << " ";
		}
		cout <<"|-->";
		p = p->next;
	}
	cout<<"NULL"<<endl<<endl;
 }

template<typename T>
void ArrayedList<T>::removeFromCell(Cell<T> *node, int idxRemove)
{

	if(node == NULL) return;

	for(int i = idxRemove; i < node->filled_Subcells; i++)
	{
		node->info[i] = node->info[i+1];
	}
	node->filled_Subcells = node->filled_Subcells - 1;
}


template<typename T>
void ArrayedList<T>::shiftAllNodes(Cell<T>* start)
{ 
	if(start == NULL) return;
	Cell<T>* auxTr, *auxCurrent, *auxNext;
	auxTr = auxCurrent = auxNext = start;
	while(auxTr->next != NULL)
	{
		auxCurrent = auxTr;
		auxNext = auxTr->next;
		auxCurrent->info[4] = auxNext->info[0]; 
		auxCurrent->filled_Subcells++;

		removeFromCell(auxNext, 0);

		auxTr = auxTr->next;
	}
}



