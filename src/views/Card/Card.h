#pragma once
#include <SFML/Graphics.hpp>
#include "../../utils/UUID/UUID.h"

namespace SoftCardDeck {
	class CardView {
		private:
			sf::Texture __texture;
			SoftCardDeck::UUID __id;
		public:
			CardView(const sf::Texture &texture_, const SoftCardDeck::UUID &id_);
			void display_card(float xCoordinate, float yCoordinate, sf::RenderWindow *window);
			SoftCardDeck::UUID id();

			// TODO: Add Card animations for inserting and deleting
	};
}
