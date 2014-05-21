/************************************************************************
* Template Class: ArrayStack
*
* Canonical functions:
*	ArrayStack();
*		default constructor
*	ArrayStack(int size);
*		overloaded contructor
*	ArrayStack(const ArrayStack<T>& copy);
*		copy constructor
*	ArrayStack<T> & operator=(const ArrayStack<T> & copy);
*		 overloaded = operator
*	~ArrayStack();
*		destructor
*
* Mutators:
*	void Push( T data);
*	void Pop();
*	T & Peek();
* Accessor:
*	int Size();
*	bool isEmpty();
*	bool isFull();
*
*************************************************************************/
#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include"Array.h"
#include"Exception.h"

template<typename T/*, const int Size*/>
class ArrayStack
{
public:
	//canonical function
	ArrayStack();
	ArrayStack( int size);
	~ArrayStack();
	ArrayStack(const ArrayStack<T> & copy);
	ArrayStack<T> & operator=(const ArrayStack<T> & right);
	//Mutators
	void Push( T data);
	void Pop();
	T & Peek();
	//accessor
	int Size();
	bool isEmpty();
	bool isFull();
private:
	Array<T> * m_stack;
	int m_size;
	int m_stackPointer;
};

/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  default contructor for an ArrayStack
*
***************************************************************/
template<typename T>
ArrayStack<T>::ArrayStack():m_stackPointer(0),m_size(0)
{
	m_stack = new Array<T>(m_size);
}

/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  overloaded contructor for an ArrayStack
*			used for a initialized stack
*
***************************************************************/
template<typename T>
ArrayStack<T>::ArrayStack(int size): m_stackPointer(0), m_size(size)
{
	m_stack = new Array<T>(size);

}

/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  default destructor for an ArrayStack
*
***************************************************************/
template<typename T>
ArrayStack<T>::~ArrayStack()
{
	delete m_stack;
}
/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  copy contructor for an ArrayStack
*
***************************************************************/
template<typename T>
ArrayStack<T>::ArrayStack( const ArrayStack<T> & copy)
{
	*this = copy;
}
/**************************************************************
*   Entry:  = operator on two stacks
*
*    Exit:  after left array = right stack
*
* Purpose:  overloaded copy constructor for an ArrayStack
*
***************************************************************/
template<typename T>
ArrayStack<T> & ArrayStack<T>::operator=(const ArrayStack<T> & right)
{
	if(m_stackPointer >= 0 && right.m_stackPointer >=0)
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
void ArrayStack<T>::Push(T data)
{
	if(m_stackPointer >= 0 && m_stackPointer < m_size)
	{
		(*m_stack)[m_stackPointer] = data;
		m_stackPointer++;
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
void ArrayStack<T>::Pop()
{
	if(m_stackPointer >= 0)
	{
		m_stackPointer--;
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
int ArrayStack<T>::Size()
{
	return m_stackPointer;
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
T & ArrayStack<T>::Peek()
{
	if(m_stackPointer-1 >= -1)
	{
		return (*m_stack)[m_stackPointer-1];
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
* Purpose: returns bool if stack is empty
*
***************************************************************/
template<typename T>
bool ArrayStack<T>::isEmpty()
{
	bool returnBool(false);

	if(m_stackPointer == -1)
	{
		returnBool = true;
	}
	return returnBool;
}

/**************************************************************
*   Entry:  None
*
*    Exit:  None
*
* Purpose: returns bool if stack is full 
*
***************************************************************/
template<typename T>
bool ArrayStack<T>::isFull()
{
	bool returnBool(false);

	if(m_stackPointer == m_size)
	{
		returnBool = true;
	}
	return returnBool;
}

#endif