/************************************************************************
* Class: Card
*
*Canonical functions:
*	Card();
*	~Card();
*	Card(const Card & copy);
*	Card & operator=(const Card & right);
*	Card(int rank, char suit); //Overloaded Contructor;
*
*Mutators:
*	void setRank( int rank);
*	void setSuit( int suit);
*	void setColor(int color);
*
*Accessors:
*	int getRank();
*	char getSuit();
*	int getColor();
*	Card & getCard();
*
*Methods:
*	bool operator ==(const Card & right);
*	bool operator !=(const Card & right);
*	void display();
*
*************************************************************************/
#ifndef	CARD_H
#define	CARD_H

class Card
{
public:
	//Canonical functions
	Card();
	~Card();
	Card(const Card & copy);
	Card & operator=(const Card & right);
	Card(int rank, char suit); //Overloaded Contructor;


	//Mutators
	void setRank( int rank);
	void setSuit( int suit);
	void setColor(int color);

	//Accessors
	int getRank();
	char getSuit();
	int getColor();
	Card & getCard();

	//Methods
	bool operator ==(const Card & right);
	bool operator !=(const Card & right);
	void display();
private:
	int m_colorCode;
	int m_rank;
	char m_suit;
};
#endif