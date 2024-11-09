#include "Deck.h"

SoftCardDeck::DeckView::DeckView(SoftCardDeck::DeckModel &deck_){
	// TODO: Consider moving below logic to controllers/
	for(int i = 0; i < deck_.size(); ++i){
		sf::Texture texture;
		if(!texture.loadFromFile(deck_.current_card().path())){return;}
		SoftCardDeck::CardView cv = SoftCardDeck::CardView(texture, deck_.current_card().uuid());
		this->__deckView.push_back(cv);
		deck_.next_card();
	}
}

void SoftCardDeck::DeckView::display_deck(float xCoordinate, float yCoordinate, sf::RenderWindow *window){
	int cardCounter = 0;
	for(auto &cardView: this->__deckView){
		int selected = 0;
		// TODO: Logic for popping out of selected card
		// if(cardView.id() == myDeckVector[j].current_card().uuid()){
		// 	selected = 50;
		// }
		cardView.display_card(xCoordinate+30*cardCounter, yCoordinate-selected, window);
		++cardCounter;
	}
}
