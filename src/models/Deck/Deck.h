#pragma once
#include <deque>
#include <memory>
#include "../Card/Card.h"

namespace SoftCardDeck {
	class Deck {
		private:
			std::deque<SoftCardDeck::Card> __deckCards;
			std::deque<SoftCardDeck::Card>::iterator __currentCard;

		public:
			explicit Deck(std::deque<Card>);
			SoftCardDeck::Card top_card();
			SoftCardDeck::Card bottom_card();
			SoftCardDeck::Card current_card();
			void next_card();
			void previous_card();
			void flip_current_card();
			void face_up_deck();
			void face_down_deck();
			void shuffle();
			void sort();
	};

}
