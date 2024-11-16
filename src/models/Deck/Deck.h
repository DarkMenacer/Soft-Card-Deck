#pragma once
#include <deque>
#include <memory>
#include "../Card/Card.h"

namespace SoftCardDeck {
	class DeckModel {
		private:
			std::deque<SoftCardDeck::CardModel> __deckCards;
			std::deque<SoftCardDeck::CardModel>::iterator __currentCard;
			int __deckSize;
			void add_card(SoftCardDeck::CardModel card);
			void delete_current_card();
		public:
			explicit DeckModel(std::deque<CardModel>);
			SoftCardDeck::CardModel top_card();
			SoftCardDeck::CardModel bottom_card();
			SoftCardDeck::CardModel &current_card();
			void next_card();
			void previous_card();
			void flip_current_card();
			void face_up_deck();
			void face_down_deck();
			void shuffle();
			void sort();
			int size();
			void move_current_card_to(DeckModel &d);
			std::deque<SoftCardDeck::CardModel> *deckCards();
	};
}
