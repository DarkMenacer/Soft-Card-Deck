#pragma once
#include <vector>
#include "../Deck/Deck.h"

namespace SoftCardDeck {
	class BoardModel {
		private:
			SoftCardDeck::DeckModel *__facedUpDeck, *__facedDownDeck, *__removedDeck;
		public:
			BoardModel(SoftCardDeck::DeckModel *_facedUpDeck, SoftCardDeck::DeckModel *_facedDownDeck, SoftCardDeck::DeckModel *_removedDeck);
			SoftCardDeck::DeckModel *faced_up_deck();
			SoftCardDeck::DeckModel *faced_down_deck();
			SoftCardDeck::DeckModel *removed_deck();
	};
}
