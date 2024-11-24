#include "Board.h"
#include "../Deck/Deck.h"

SoftCardDeck::BoardView::BoardView(SoftCardDeck::BoardModel &board_){
	this->__boardController = &board_;
}

void SoftCardDeck::BoardView::display_board(float xCoordinate, float yCoordinate, sf::RenderWindow *window){
	this->__boardController->faced_down_deck()->face_down_deck();
	SoftCardDeck::DeckView facedDownDeckView = *this->__boardController->faced_down_deck();
	facedDownDeckView.display_deck_compact(xCoordinate, yCoordinate, window);

	SoftCardDeck::DeckView facedUpDeckView = *this->__boardController->faced_up_deck();
	facedUpDeckView.display_deck_fan(xCoordinate+250, yCoordinate, window);
}