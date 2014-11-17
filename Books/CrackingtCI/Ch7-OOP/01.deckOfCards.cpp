#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;

class spanishCard{
	enum Suit(OROS, COPAS, ESPADAS, BASTOS)
	spanishCard(int n, Suit palo){
		if( n==8 || n==9 || n>12)
		{
			cout<< "Spanish cards take values between 1-7 and 10-12"
			return NULL;
		}
		number = n;
		suit = palo;
	}
	Suit suit(){return suit}
	int number(){return number}

private:
	int number;
	Suit suit;
};

//ForVersion with replacement and mixing after each replacement
class sevenAndAHalf{
	sevenAndAHalf(){
		sum = 0;
	}
	
	spanishCard draw(){
		float n = ((float)(rand()%14))/ ((float)(rand()%2));
		spanishCard card = new spanishCard( n, Suit)
		drawn.push(card);
		return card;
	}

	void addPoints( int card){
		sum+= (card>7)? 0.5:card;
	} 

	void run(){
		char option = "n";
		spanishCard card;
		cout<<"Starting a game of seven and a half..."<<endl;
		while(option!="y"){
			card = draw()
			cout<<"Card drawn: "<< card.number()<<" of "<< card.suit() <<endl;
			cout<<"Your cards sum "<<sum<<". Do you want to stop? [y/n]";
			cin >> option;
		}
		if(sum>7.5) cout<<"You lose!"<<endl;
		else cout<<"You win!"<<endl;
	}

private:
	stack<spanishCard> drawn;
	float sum;
};
