#include "Deck.h"
#include <deque>

SoftCardDeck::DeckView::DeckView(SoftCardDeck::DeckModel &deck_){
	this->deckController = &deck_;
}

void SoftCardDeck::DeckView::display_deck(float xCoordinate, float yCoordinate, sf::RenderWindow *window){
	std::deque<SoftCardDeck::CardModel> deckCards = this->deckController->get_cards_copy();
	int cardCounter = 0;
	for(auto card: deckCards){
		sf::Texture texture;
		if(!texture.loadFromFile(card.path())){return;}
		SoftCardDeck::CardView cardView = SoftCardDeck::CardView(texture, card.uuid());
		int selected = 0;
		if(cardView.id() == this->deckController->current_card().uuid()){
			selected = 50;
		}
		cardView.display_card(xCoordinate+30*cardCounter, yCoordinate-selected, window);
		++cardCounter;
	}
}