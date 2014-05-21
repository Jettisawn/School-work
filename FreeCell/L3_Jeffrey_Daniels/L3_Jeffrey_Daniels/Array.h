/************************************************************************
* Template Class: Array
*
* Canonical functions:
*	Array();
*		default constructor
*	Array(int length, int start = 0);
*		overloaded contructor
*	Array(const Array<T>& copy);
*		copy constructor
*	Array<T> & operator=(const Array<T> & array);
*		 overloaded = operator
*	T& operator[](int index);
*		overloaded [] operator
*	~Array();
*		destructor
*
* Mutators:
*	int getStart() const;
*		This mutator is used to get the starting index
*	int getLength() const;
*		This mutator is used to get the Array length
*	void setStart(int newStart);
*		This mutator is used to set a new starting index
*	void setLength(int newLength);
*		This mutator is used to set a new length
*
*************************************************************************/
#ifndef ARRAYS_H
#define ARRAYS_H

#include "Exception.h"

template <typename T>
class Array
{
public:
	//canonical functions
	Array();
	Array(int length, int start = 0);
	Array(const Array<T>& copy);
	Array<T> & operator=(const Array<T> & array);
	T& operator[](int index);
	~Array();

	 //mutators
	int getStart() const;
	int getLength() const;
	void setStart(int newStart);
	void setLength(int newLength);
	
private:
	T * m_data;  // templated data membter
	int m_length;	// use to set array Lenght, must be zero or greater
	int m_start;	// use to set the staring element of Array
	
};

/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  default contructor for an Array
*
***************************************************************/
template <typename T>
Array<T>::Array():m_length(0) , m_start(0),  m_data(nullptr)
{}

/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  destructor for an Array
*
***************************************************************/
template <typename T>
Array<T>::~Array()
{
	delete [] m_data;
}

/**************************************************************
*   Entry:  array length and starting index set to 0
*
*    Exit:  After Array is Created, or exception is thrown
*			for negative length
*
* Purpose:  overloaded contructor for an Array,
*
***************************************************************/
template <typename T>
Array<T>::Array( int length, int start = 0):m_data(nullptr) , m_start(start),m_length(length)
{
	if( length >= 0 )
	{
		m_data = new T[length];
	}
	else
	{
		throw Exception("EXCEPTION THROWN: Length is less than zero");
	}
}

/**************************************************************
*   Entry:  When a copy constructor is called
*
*    Exit:  After array passed in is Equal to current Array
*
* Purpose: copy contents of one array to another
*
***************************************************************/
template<typename T>
Array<T>::Array(const Array<T>& copy):m_data(0)
{
	*this = copy;
}

/**************************************************************
*   Entry:  Array1 = Array2;
*
*    Exit:  After contents of  right Array is copied to *this Array 
*
* Purpose:  Make Left Array Equal to RIght Array
*
***************************************************************/
template <typename T>
Array<T> & Array<T>::operator=(const Array <T> & right)
{

	if(this != & right)
	{
		delete []m_data;
		m_data = new T[right.m_length];
		m_start = right.m_start;
		m_length = right.m_length;

		

		for(int i = 0; i < m_length; ++i)
			m_data[i] = right.m_data[i];
	}
	return * this;
}
/**************************************************************
*   Entry:  array[ A element Number ]
*
*    Exit:  After element is determined valid, or exception is thrown
*			for going out of bounds.
*
* Purpose: To determine and access valid elements.
*
***************************************************************/
template <typename T>
T& Array<T>::operator[](int index)
{
	if (index < m_start )
		throw Exception("EXCEPTION THROWN: Error index is smaller than lower Bounds");
	else if(index >= (m_length + m_start))
		throw Exception("EXCEPTION THROWN: Error index is Larger than upper Bounds");
	else
		return m_data[index - m_start];
}

/**************************************************************
*   Entry:  Array.getStart();
*
*    Exit:  return starting index
*
* Purpose:  return starting index
*
***************************************************************/
template <typename T>
int Array<T>::getStart() const
{
	return m_start;
}

/**************************************************************
*   Entry:  Array.getLength();
*
*    Exit:  return array length
*
* Purpose:  return array length
*
***************************************************************/
template <typename T>
int Array<T>::getLength() const
{
	return m_length;
}

/**************************************************************
*   Entry:  Array.setStart();
*
*    Exit:  change starting index
*
* Purpose:  Change starting index of array
*
***************************************************************/
template <typename T>
void Array<T>::setStart(int newStart)
{
	m_start = newStart;
}

/**************************************************************
*   Entry:  Array.setLength();
*
*    Exit:  After changing Array length
*
* Purpose:  To change the current length of an array index
*
***************************************************************/
template <typename T>
void Array<T>::setLength(int newLength)
{
	T* newData = new T [newLength];
	int min = (m_length < newLength ? m_length : newLength);
	for (int i = 0; i < min; ++i)
	{
		newData[i] = m_data[i];
	}
	delete [] m_data;
	m_data = newData;
	m_length = newLength;
}
#endif