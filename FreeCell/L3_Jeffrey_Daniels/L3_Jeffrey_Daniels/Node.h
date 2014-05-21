/************************************************************************
* Template Class: DoubleLinkedList
*
* Canonical functions:
*
*	Node();
*		default constructor
*	Node( T Data);
*		overloaded constructor
*	~Node();
*		destructor	
*	Node(const Node<T> & copy);
*		copy constructor
*	Node<T> & operator=(const Nodet<T> & right);
*		 overloaded = operator
*
* Mutators:
*	void setData( T data);
*	void setNext( Node<T> * newNext);
*	void setPrev( Node<T> * newPrev);
*
* Accessors:
*		 T  & getData();
*	Node<T> * getNext();
*	Node<T> * getPrev();
*************************************************************************/
#ifndef NODE_H
#define	NODE_H

template<typename T>
class DoubleLinkedList;

template<typename T>
class Node
{
	friend class DoubleLinkedList<T>;
public:
	//canonical functions
	Node();
	Node(T newData);
	Node(const Node<T> & copy);
	Node<T> & operator=( const Node<T> & right);
	~Node();

	//mutators
	void setData( T data);
	void setNext( Node<T> * newNext);
	void setPrev( Node<T> * newPrev);

	//Accessors
		 T  & getData();
	Node<T> * getNext();
	Node<T> * getPrev();


private:
	 T   m_data;
	 Node<T> * m_next;
	 Node<T> * m_prev;
};
/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  default contructor for an Node
*
***************************************************************/
template<typename T>
Node<T>::Node(): m_data(0), m_next(nullptr), m_prev(nullptr)
{}
/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  overloaded contructor for a Node
*
***************************************************************/
template<typename T>
Node<T>::Node(T newData): m_data(newData), m_next(nullptr), m_prev(nullptr)
{}
/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  default destructor for a Node
*
***************************************************************/
template<typename T>
Node<T>::~Node()
{}

/**************************************************************
*   Entry:  right Node access with equals operator
*
*    Exit:  right Node equal to left Node
*
* Purpose:  copy right node to left Node
*
***************************************************************/
template<typename T>
Node<T> & Node<T>::operator=(const Node<T> & right)
{
	m_data = right.m_data;
	m_next = right.m_next;
	m_prev = right.m_prev;

	return *this;
}

/**************************************************************
*   Entry:  copy Node
*
*    Exit:  copy Node equals current Node
*
* Purpose:  copy one Node to another, Uses overloaded equals operator
*
***************************************************************/
template<typename T>
Node<T>::Node( const Node<T> & copy)
{
	*this = copy;
}	
/**************************************************************
*   Entry:  pass in T data to set Data 
*
*    Exit:  after Data is set
*
* Purpose:  Not Used
*
***************************************************************/
template<typename T>
void Node<T>::setData( T data)
{
	m_data = data;
}
template<typename T>
/**************************************************************
*   Entry:  pass in Node<T> pointer to set m_next
*
*    Exit:  m_next is set
*
* Purpose:  Not Used
*
***************************************************************/
void Node<T>::setNext( Node<T> * newNext)
{
	m_next = newNext;
}
/**************************************************************
*   Entry:  pass in Node<T> pointer to set m_prev
*
*    Exit:  m_prev is set
*
* Purpose:  Not Used
*
***************************************************************/
template<typename T>
void Node<T>::setPrev( Node<T> * newPrev)
{
	m_prev = newPrev;
}
/**************************************************************
*   Entry:  none
*
*    Exit:  returning Nodes m_data
*
* Purpose:  Not Used
*
***************************************************************/
template<typename T>
T & Node<T>::getData()
{
	return m_data;
}
/**************************************************************
*   Entry:  none
*
*    Exit:  returning Node<T> * m_next
*
* Purpose:  Not Used
*
***************************************************************/
template<typename T>
Node<T> * Node<T>::getNext()
{
	return m_next;
}
/**************************************************************
*   Entry:  none
*
*    Exit:  returning Node<T> * m_prev
*
* Purpose:  Not Used
*
***************************************************************/
template <typename T>
Node<T> * Node<T>::getPrev()
{
	return m_prev;
}
#endif