#pragma once
#include <SFML/Graphics.hpp>
#include "../../utils/UUID/UUID.h"
#include "../../models/Card/Card.h"

namespace SoftCardDeck {
	class CardView {
		private:
			SoftCardDeck::CardModel *__cardController;
		public:
			CardView(SoftCardDeck::CardModel &cardModel);
			void display_card(float xCoordinate, float yCoordinate, sf::RenderWindow *window);

			// TODO: Add Card animations for inserting and deleting
	};
}
