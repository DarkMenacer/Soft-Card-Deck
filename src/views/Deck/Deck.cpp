#include "Deck.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <deque>

SoftCardDeck::DeckView::DeckView(SoftCardDeck::DeckModel &deck_){
	this->__deckController = &deck_;
}

void SoftCardDeck::DeckView::display_deck_fan(float xCoordinate, float yCoordinate, sf::RenderWindow *window){
	std::deque<SoftCardDeck::CardModel> deckCards = *this->__deckController->deckCards();
	int cardCounter = 0;
	for(auto card: deckCards){
		SoftCardDeck::CardView cardView = card;
		int selected = 0;
		if(card.uuid() == this->__deckController->current_card().uuid()){
			selected = 50;
		}
		cardView.display_card(xCoordinate+30*cardCounter, yCoordinate-selected, window);
		++cardCounter;
	}
}

void SoftCardDeck::DeckView::display_deck_compact(float xCoordinate, float yCoordinate, sf::RenderWindow *window){
	std::deque<SoftCardDeck::CardModel> deckCards = *this->__deckController->deckCards();
	for(auto card: deckCards){
		if(card.uuid() == this->__deckController->current_card().uuid()){
			SoftCardDeck::CardView cardView = card;
			cardView.display_card(xCoordinate, yCoordinate, window);
		}
	}
}