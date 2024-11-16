#pragma once
#include "../../models/Board/Board.h"
#include <SFML/Graphics/RenderWindow.hpp>

namespace SoftCardDeck {
	class BoardView {
		private:
			SoftCardDeck::BoardModel *__boardController;
		public:
			BoardView(SoftCardDeck::BoardModel &board_);
			void display_board(float xCoordinate, float yCoordinate, sf::RenderWindow *window);
	};
}
