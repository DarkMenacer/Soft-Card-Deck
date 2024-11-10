#pragma once
#include "../Card/Card.h"
#include "../../models/Deck/Deck.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>

namespace SoftCardDeck {
	class DeckView {
		private:
			SoftCardDeck::DeckModel *deckController;
		public:
			DeckView(SoftCardDeck::DeckModel &deck_);
			void display_deck(float xCoordinate, float yCoordinate, sf::RenderWindow *window);
	};
}
