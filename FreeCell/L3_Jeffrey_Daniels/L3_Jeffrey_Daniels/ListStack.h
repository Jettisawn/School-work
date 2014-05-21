/************************************************************************
* Template Class: ListStack
*
* Canonical functions:
*	ListStack();
*		default constructor
*	ListStack(int size);
*		overloaded contructor
*	ListStack(const ListStack<T>& copy);
*		copy constructor
*	ListStack<T> & operator=(const ListStack<T> & copy);
*		 overloaded = operator
*	~ListStack();
*		destructor
*
* Mutators:
*	void Push( T data);
*	void Pop();
*	T & Peek();
* Accessor:
*	int Size();
*	bool isEmpty();
*
*************************************************************************/
#ifndef LISTSTACK_H
#define LISTSTACK_H

#include"doublelinkedlist.h"
#include"Exception.h"
#include"Node.h"


template<typename T>
class ListStack
{
public:
	//canonical function
	ListStack();
	~ListStack();
	ListStack(const ListStack<T> & copy);
	ListStack<T> & operator=(const ListStack<T> & right);
	//Mutators
	void Push( T data);
	void Pop();
	T & Peek();
	//accessor
	int Size();
	bool isEmpty();
private:
	DoubleLinkedList<T> * m_stack;
	int m_size;
	int m_stackPointer;
};

/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  default contructor for an ListStack
*
***************************************************************/
template<typename T>
ListStack<T>::ListStack():m_stackPointer(-1),m_size(0)
{
	m_stack = new DoubleLinkedList<T>;
}

/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  default destructor for an ListStack
*
***************************************************************/
template<typename T>
ListStack<T>::~ListStack()
{
	delete m_stack;
}
/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  copy contructor for an ListStack
*
***************************************************************/
template<typename T>
ListStack<T>::ListStack( const ListStack<T> & copy)
{
	*this = copy;
}
/**************************************************************
*   Entry:  = operator on two stacks
*
*    Exit:  after left array = right stack
*
* Purpose:  overloaded copy constructor for an ListStack
*
***************************************************************/
template<typename T>
ListStack<T> & ListStack<T>::operator=(const ListStack<T> & right)
{
	if(m_stackPointer >= -1 && right.m_stackPointer >=-1)
	{
		m_size = right.m_size;
		m_stackPointer = right.m_stackPointer;
		(*m_stack) = (*right.m_stack);
	}
	else
	{
		throw Exception("\nSegmentation Fault");
	}
	return *this;
}
/**************************************************************
*   Entry:  when pushing data onto stack
*
*    Exit:  after data is set in element or throws exception
*
* Purpose: Simulate pushing onto a stack
*
***************************************************************/
template<typename T>
void ListStack<T>::Push(T data)
{
	 if(m_stackPointer+1 >= 0)
	{
		m_size++;
		m_stackPointer++;
		m_stack->Append(data);
	}
	else
	{
		throw Exception("\nSegmentation Fault");
	}
}
/**************************************************************
*   Entry:  when popping data off the stack
*
*    Exit:  after stack pointer is incremented or throws exception
*
* Purpose: Simulate popping a stack
*
***************************************************************/
template<typename T>
void ListStack<T>::Pop()
{
	if(m_stackPointer >= 0)
	{
		Node<T> * travel = m_stack->getHead();

		while(travel != m_stack->getTail())
		{
			travel = travel->getNext();
		}
		m_stack->Extract(travel->getData());
		m_stackPointer--;
		m_size--;
	}
	else
	{
		throw Exception("\nSegmentation Fault");
	}
}
/**************************************************************
*   Entry:  None
*
*    Exit:  returns int
*
* Purpose: returns StackPointer position +1 for stack size
*
***************************************************************/
template<typename T>
int ListStack<T>::Size()
{
	return m_stackPointer+1;
}
/**************************************************************
*   Entry:  None
*
*    Exit:  returns T data
*
* Purpose: returns Data ontop of stack
*
***************************************************************/
template<typename T>
T & ListStack<T>::Peek()
{
	if(m_stackPointer >= 0)
	{
		Node<T> * travel = m_stack->getTail();
		
		return travel->getData();
	}
	else
	{
		throw Exception("\nSegmentation Fault");
	}
}
/**************************************************************
*   Entry:  None
*
*    Exit:  None
*
* Purpose: returns bool if stack is empty or full stack
*
***************************************************************/
template<typename T>
bool ListStack<T>::isEmpty()
{
	bool returnBool(false);

	if(m_stackPointer == -1)
	{
		returnBool = true;
	}
	return returnBool;
}
#endif