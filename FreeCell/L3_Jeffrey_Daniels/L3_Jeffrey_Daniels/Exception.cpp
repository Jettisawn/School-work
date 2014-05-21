#include <iostream>
#include "Exception.h"

using std::cout;
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE

/**************************************************************
*   Entry:  using the << operator for a Cout
*
*    Exit:  after Exception message has been place into Errorcode
*
* Purpose:  Used for display
*
***************************************************************/
ostream & operator <<(ostream & ErrorCode, const Exception & msg)
{

	ErrorCode << msg.m_msg;

	return ErrorCode;
}


/**************************************************************
*   Entry:  none
*
*    Exit:  after intilaztion
*
* Purpose:  default copy constructor
*
***************************************************************/
Exception::Exception() : m_msg(nullptr){}


/**************************************************************
*   Entry:  Exception operator filled with char *
*
*    Exit:  after msg is copy to private data member
*
* Purpose:  overloaded constructor
*
***************************************************************/
Exception::Exception(char * msg)
{

	m_msg = new char[strlen(msg)+1];

	strcpy(m_msg , msg);
}

/**************************************************************
*   Entry:  none
*
*    Exit:  after memory is cleared
*
* Purpose: destructor
*
***************************************************************/
Exception::~Exception()
{
	delete [] m_msg;
}

/**************************************************************
*   Entry:  when exception needs copied
*
*    Exit:  after copy is copied to Exception
*
* Purpose:  copy constructor
*
***************************************************************/
Exception::Exception(const Exception & copy) : m_msg(nullptr)
{
	*this = copy;
}

/**************************************************************
*   Entry:  When overloaed = is filled with exception
*
*    Exit:  after copy is coppied to Exception
*
* Purpose:  Overloaded = operator
*
***************************************************************/
Exception & Exception::operator=(const Exception& right)
{
	delete[] m_msg;
	m_msg = new char[strlen(right.m_msg)+1];

	strcpy(m_msg , right.m_msg);

	return *this;
}

/**************************************************************
*   Entry:  When getting message is called
*
*    Exit:  message is returned
*
* Purpose:  get message of exception
*
***************************************************************/
const char * Exception::getMessage()
{
	return m_msg;
}

/**************************************************************
*   Entry:  mutator to change message
*
*    Exit:  after message is changed
*
* Purpose:  set new message for exception
*
***************************************************************/
void Exception::setMessage(char * msg) 
{
	delete [] m_msg;

	m_msg = new char[strlen(msg)+1];

	strcpy(m_msg , msg);
}