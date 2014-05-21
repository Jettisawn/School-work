/************************************************************************
* Class: Exception
*
* Constructors:	
*	Exception
*		char * m_msg intilalized to nullptr
*
* Canonical functions:
*	Exception();
*		default constructor
*	Exception(char * msg);
*		overloaded contructor
*	Exception(const Exception & copy);
*		copy constructor
*	~Exception();
*		desctuctor
*
* Mutators:
*	const char * getMessage();
*			This mutator gets the message from the exception class
*	void setMessage( char * msg);
*			This mutator sets the message for exception class
*
* Methods:
*	outside of data memebers:
*
*	friend ostream & operator <<(ostream & ErrorCode, const Exception & msg);
*			overloaded ostream operator for display exception error code
*	
*************************************************************************/
#ifndef EXCEPTION
#define EXCEPTION

#include <iostream>
using std::ostream;

class Exception
{
	friend ostream & operator <<(ostream & ErrorCode, const Exception & msg);

public:
	//default constructor
	Exception();
	//overloaded constructor
	Exception(char * msg);
	//copy constructor
	Exception(const Exception & copy);
	//destructor
	~Exception();
	//overloaded = opertor
	Exception & operator=(const Exception& right);

	//mutator to get message
	const char * getMessage();
	//mutator to set message
	void setMessage( char * msg);

private:
	char * m_msg;   // Hold message of exception thrown
};
#endif