#include "Card.h"
#include "../../constants/Card_Constants.h"
#include <string>

SoftCardDeck::CardModel::CardModel(SoftCardDeck::Rank _rank, SoftCardDeck::Suit _suit)
	: __cardRank(_rank), __cardSuit(_suit), __cardFacedUp(true), __cardUUID(SoftCardDeck::UUID()){
	this->__cardPath = "../assets/"+SoftCardDeck::suitMapper[_suit];
	this->__cardPath.push_back('_');
	this->__cardPath.append(SoftCardDeck::rankMapper[_rank]+".png");
}

void SoftCardDeck::CardModel::flip(){this->__cardFacedUp = !this->__cardFacedUp;}

SoftCardDeck::Rank SoftCardDeck::CardModel::rank(){return this->__cardRank;}

SoftCardDeck::Suit SoftCardDeck::CardModel::suit(){return this->__cardSuit;}

bool SoftCardDeck::CardModel::facedup(){return this->__cardFacedUp;}

std::string SoftCardDeck::CardModel::path(){
	return this->__cardFacedUp? this->__cardPath : "../assets/abstract.png";
}

void SoftCardDeck::CardModel::set_face_up(){this->__cardFacedUp = true;}

void SoftCardDeck::CardModel::set_face_down(){this->__cardFacedUp = false;}

SoftCardDeck::UUID SoftCardDeck::CardModel::uuid(){return this->__cardUUID;}

bool SoftCardDeck::CardModel::operator==(const CardModel &card) const {
	return card.__cardUUID == this->__cardUUID;
}
