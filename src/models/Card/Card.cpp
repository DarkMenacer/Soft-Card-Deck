#include "Card.h"
#include "../../constants/Card_Constants.h"
#include <string>

SoftCardDeck::Card::Card(SoftCardDeck::Rank _rank, SoftCardDeck::Suit _suit)
<<<<<<< Updated upstream
	: __cardRank(_rank), __cardSuit(_suit), __cardFaceUp(true){
=======
	: __cardRank(_rank), __cardSuit(_suit), __cardFacedUp(true), __cardUUID(SoftCardDeck::UUID()){
>>>>>>> Stashed changes
	this->__cardPath = "../assets/"+SoftCardDeck::suitMapper[_suit];
	this->__cardPath.push_back('_');
	this->__cardPath.append(SoftCardDeck::rankMapper[_rank]+".png");
}

void SoftCardDeck::Card::flip(){this->__cardFaceUp = !this->__cardFaceUp;}

SoftCardDeck::Rank SoftCardDeck::Card::rank(){return this->__cardRank;}

SoftCardDeck::Suit SoftCardDeck::Card::suit(){return this->__cardSuit;}

bool SoftCardDeck::Card::faceup(){return this->__cardFaceUp;}

std::string SoftCardDeck::Card::path(){
	return this->__cardFaceUp? this->__cardPath : "../assets/abstract.png";
}
<<<<<<< Updated upstream
=======

void SoftCardDeck::Card::set_face_up(){this->__cardFacedUp = true;}

void SoftCardDeck::Card::set_face_down(){this->__cardFacedUp = false;}

SoftCardDeck::UUID SoftCardDeck::Card::uuid(){return this->__cardUUID;}
>>>>>>> Stashed changes
