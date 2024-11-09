#include "Board.h"

SoftCardDeck::BoardModel::BoardModel(SoftCardDeck::DeckModel _facedUpDeck, SoftCardDeck::DeckModel _facedDownDeck, SoftCardDeck::DeckModel _removedDeck)
	: __facedUpDeck(_facedUpDeck), __facedDownDeck(_facedDownDeck), __removedDeck(_removedDeck){}

SoftCardDeck::DeckModel *SoftCardDeck::BoardModel::faced_up_deck(){return &this->__facedUpDeck;}

SoftCardDeck::DeckModel *SoftCardDeck::BoardModel::faced_down_deck(){return &this->__facedDownDeck;}

SoftCardDeck::DeckModel *SoftCardDeck::BoardModel::removed_deck(){return &this->__removedDeck;}