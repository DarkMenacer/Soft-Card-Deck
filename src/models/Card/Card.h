#pragma once
#include "../../constants/Card_Constants.h"
#include "../../utils/UUID/UUID.h"
#include <string>

namespace SoftCardDeck {
	class Card {
		private:
			SoftCardDeck::Rank __cardRank;
			SoftCardDeck::Suit __cardSuit;
			bool __cardFaceUp;
			std::string __cardPath;
			SoftCardDeck::UUID __cardUUID;
		public:
			void flip();
			SoftCardDeck::Rank rank();
			SoftCardDeck::Suit suit();
<<<<<<< Updated upstream
			bool faceup();
=======
			SoftCardDeck::UUID uuid();
			bool facedup();
>>>>>>> Stashed changes
			Card(Rank, Suit);
			std::string path();
	};
}
