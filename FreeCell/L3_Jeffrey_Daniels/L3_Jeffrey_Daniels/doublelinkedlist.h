/************************************************************************
* Template Class: DoubleLinkedList
*
* Canonical functions:
*
*	DoubleLinkedList();
*		default constructor
*	~DoubleLinkedList();
*		destructor	
*	DoubleLinkedList(const DoubleLinkedList<T> & copy);
*		copy constructor
*	DoubleLinkedList<T> & operator=(const DoubleLinkedList<T> & right);
*		 overloaded = operator
*
* Mutators:
*	void Append( T  data);
*	void Prepend(T data);
*	void Purge();
*	void InsertBefore( T inputData, T findData);
*	void InsertAfter( T inputData, T findData);
*	void Extract(T findData);
*
* Accessors:
*	T & First() const;
*	T & Last() const;
*	Node<T> * getHead();
*	Node<T> * getTail();
*	void PrintForwards();
*	void PrintBackwards();
*
*************************************************************************/
#ifndef DOUBLELINKEDLIST_H
#define	DOUBLELINKEDLIST_H

#include <iostream>


#include <iomanip>
#include "Node.h"

using std::cout;
using std::endl;
using std::setw;

template<typename T>
class DoubleLinkedList
{		friend class Node<T>; //DoubleLinkedList knows about Node Class
public:
	//canonical Functions
	DoubleLinkedList();
	~DoubleLinkedList();
	DoubleLinkedList(const DoubleLinkedList<T> & copy);
	DoubleLinkedList<T> & operator=(const DoubleLinkedList<T> & right);
	
	//Mutators
	void Append( T  data);
	void Prepend(T data);
	void Purge();
	void InsertBefore( T inputData, T findData);
	void InsertAfter( T inputData, T findData);
	void Extract(T findData);
	
	//Accessors
	Node<T> * getHead();
	Node<T> * getTail();
	T & First() const;
	T & Last() const;
	void PrintForwards() const;
	void PrintBackwards() const;
private: 
	//holds starting Node of DoubleLinkedList
	 Node<T> * m_head;
	 //holds ending Node of DoubleLinkedList
	 Node<T> * m_tail;
};
/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  default contructor for an DoubleLinkedList
*
***************************************************************/
template<typename T>
DoubleLinkedList<T>::DoubleLinkedList():m_head(nullptr), m_tail(nullptr)
{
}
/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  default destructor for an DoubleLinkedList, Uses Pugre Mutator
*
***************************************************************/
template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	Purge();
}

/**************************************************************
*   Entry:  When DoubleLinkedList are on opposite side of equals operator
*
*    Exit:  after right DoubleLinked list is copied to lefts DoubleLinkedList
*
* Purpose:  Allows DoubleLinkedList to use equals operator
*
***************************************************************/
template<typename T>
DoubleLinkedList<T> & DoubleLinkedList<T>::operator=(const DoubleLinkedList<T> & right)
{
	if(this != &right) //&& right.m_head != nullptr)
	{	Purge();

		Node<T> * travel = right.m_head;

		m_head = new Node<T>(travel->m_data);		

		while(travel != right.m_tail)
		{
			this->Append(travel->m_data);
			travel = travel->m_next;
		}
		//copy the m_tail data
		this->Append(travel->m_data);
	}
	return *this;
}
/**************************************************************
*   Entry:  When making a copy of DoubleLinkList
*
*    Exit:  Copied DoubleLinkedList is copied
*
* Purpose:  default copy contructor for an DoubleLinkedList,
*			uses Overloaded equals Operator
*
***************************************************************/
template<typename T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList<T> & copy): m_head(nullptr), m_tail(nullptr)
{
	*this = copy;
}
/**************************************************************
*   Entry: Passing in Data of DoubleLinkedList
*
*    Exit:  After Node is Added to the End of DoubleLinkedList
*
* Purpose: PlaceNode at the end of a list
*
***************************************************************/
template<typename T>
void DoubleLinkedList<T>::Append( T  data)
{
	Node<T> * newNode = new Node<T>( data);

	if( m_tail != nullptr)
	{
		newNode->m_prev = m_tail;
		m_tail->m_next = newNode;

	}
	else
	{
		m_head = newNode;
	}

	m_tail = newNode;
}
/**************************************************************
*   Entry: Passing in Data of DoubleLinkedList
*
*    Exit:  After Node is Added to the front of DoubleLinkedList
*
* Purpose: PlaceNode at the start of a list
*
***************************************************************/
template<typename T>
void DoubleLinkedList<T>::Prepend( T data)
{
	Node<T> * newNode = new Node<T>(data);

	if(m_head != nullptr)
	{
		m_head->m_prev = newNode;
		newNode->m_next = m_head;
	}
	else
	{
		m_tail= newNode;
	}
	m_head = newNode;

}
/**************************************************************
*   Entry: none
*
*    Exit:  After DoubleLinked List is deleted and private members
*			are set to null
*
* Purpose: destroy a list and clean up memory leaks
*
***************************************************************/
template<typename T>
void DoubleLinkedList<T>::Purge()
{

	if(m_head != nullptr)
	{
		{
			while(m_head->m_next && m_head->m_next != m_tail && m_head != m_tail)
			{
				m_head->m_next = m_head->m_next->m_next;
				delete m_head->m_next->m_prev;
				m_head->m_next->m_prev = m_head;
			}
		}
		
		if(m_head == m_tail)
		{
			delete m_head;
		}
		else
		{
			delete m_tail;
			delete m_head;
		}
	}
	
	m_head = nullptr;
	m_tail = nullptr;
}
/**************************************************************
*   Entry: none
*
*    Exit: returns pointer address to m_head data member
*
* Purpose: access address of m_head outside of function
*
***************************************************************/
template<typename T>
Node<T> * DoubleLinkedList<T>::getHead()
{
	return m_head;
}
/**************************************************************
*   Entry: none
*
*    Exit: returns pointer address to m_tail data member
*
* Purpose: access address of m_tail outside of function
*
***************************************************************/
template<typename T>
Node<T> * DoubleLinkedList<T>::getTail()
{
	return m_tail;
}
/**************************************************************
*   Entry: none
*
*    Exit: returns data at m_head 
*
* Purpose: access data held at m_head
*
***************************************************************/
template<typename T>
T & DoubleLinkedList<T>::First() const
{
	if(m_head != nullptr)
	{
		return m_head->m_data;
	}
	throw "List is EMPTY: No Data";

}
/**************************************************************
*   Entry: none
*
*    Exit: returns data at m_tail
*
* Purpose: access data held at m_tail
*
***************************************************************/
template<typename T>
T & DoubleLinkedList<T>::Last() const
{
	if(m_tail != nullptr)
	{
		return m_tail->m_data;
	}
	throw "List is EMPTY: No Data";
}

template<typename T>
/**************************************************************
*   Entry: input data, and data to input into list
*
*    Exit: after findData is found and input data is placed 
*
* Purpose: insert a node before a given data
*
***************************************************************/
void DoubleLinkedList<T>::InsertBefore( T inputData, T findData)
{
	if(m_head != nullptr)
	{
		Node<T> * travel = m_head;

		while(travel->m_data != findData)
		{
			if(travel->m_next != nullptr)
			{
				travel =  travel->m_next;
			}
			else
			{
				throw "Data Not found in list";
			}
		}

			Node<T> * newNode = new Node<T>(inputData);

			newNode->m_next = travel;
			newNode->m_prev = travel->m_prev;

			if(m_head == travel)
			{
				m_head = newNode;
			}
			else
			{
				travel->m_prev->m_next = newNode;
				
			}	
		travel->m_prev = newNode;		
	}
	else
	{
		throw "List is Empty, no Data to find";
	}

}
/**************************************************************
*   Entry: input data, and data to input into list
*
*    Exit: after findData is found and input data is placed 
*
* Purpose: insert a node after a given data
*
***************************************************************/
template<typename T>
void DoubleLinkedList<T>::InsertAfter( T inputData, T findData)
{
	if(m_head!= nullptr)
	{
		Node<T> * travel = m_head;

		while(travel->m_data != findData)
		{
			if(travel->m_next != nullptr)
			{
				travel = travel->m_next;
			}
			else
			{
				throw"Data not found in list";
			}
		}

			Node<T> * newNode = new Node<T>(inputData);

			newNode->m_next = travel->m_next;
			newNode->m_prev = travel;

		
			if(travel->m_next == nullptr)
			{
				m_tail = newNode;
			}
			else
			{
				travel->m_next->m_prev = newNode;
			}
			travel->m_next = newNode;

		
	}
	else
	{
		throw"List is Empty, No Data to find";
	}
}
/**************************************************************
*   Entry: input data
*
*    Exit: after findData is found  node at first instance of Data
*			is deleted
*
* Purpose: delete first instance of data in list
*
***************************************************************/
template<typename T>
void DoubleLinkedList<T>::Extract(T findData)
{
	if(m_head != nullptr)
	{
		Node<T> * travel = new Node<T>(m_head->m_data);
		travel = m_head;


		while(travel->m_data != findData)
		{
			if(travel->m_next != nullptr)
			{
				travel = travel->m_next;
			}
			else
			{
				throw "Data not found in list";
			}
		}
			if(travel->m_next)
			{
				travel->m_next->m_prev = travel->m_prev;
			}
			else
			{
				m_tail = travel->m_prev;
			}
			if(travel->m_prev)
			{
				travel->m_prev->m_next = travel->m_next;
			}
			else
				m_head = travel->m_next;

				delete travel;
	}


	else
	{
		throw"List is Empty, Nothing to Extract";
	}



}
/**************************************************************
*   Entry: none
*
*    Exit: none
*
* Purpose: display list from m_head to m_tail in order of list
*
***************************************************************/
template<typename T>
void DoubleLinkedList<T>::PrintForwards() const
{
	Node<T> * travel = m_head;

	while(travel)
	{
		cout << setw(2) << travel->m_data << ' ' ;
		travel = travel->m_next;
	}
	cout << endl;

}
/**************************************************************
*   Entry: none
*
*    Exit: none
*
* Purpose: display list from m_tail to m_head in order of list
*
***************************************************************/
template<typename T>
void DoubleLinkedList<T>::PrintBackwards() const
{
	Node<T> * travel = m_tail;

	while(travel)
	{
		cout << setw(2) << travel->m_data<<  ' ' ;
		travel = travel->m_prev;
	}
	cout << endl;
}
#endif