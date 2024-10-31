#pragma once
#include "../../constants/Card_Constants.h"
#include <string>

namespace SoftCardDeck {
	class Card {
		private:
			SoftCardDeck::Rank __cardRank;
			SoftCardDeck::Suit __cardSuit;
			bool __cardFacedUp;
			std::string __cardPath;
		public:
			void flip();
			SoftCardDeck::Rank rank();
			SoftCardDeck::Suit suit();
			bool facedup();
			Card(Rank, Suit);
			std::string path();
			void set_face_up();
			void set_face_down();
	};
}
