#pragma once
#include <map>
#include <string>

namespace SoftCardDeck {
	enum class Rank {
		ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
	};

	enum class Suit {
		HEARTS, SPADES, CLUBS, DIAMONDS
	};

	extern std::map<Rank, std::string> rankMapper;
	extern std::map<Suit, std::string> suitMapper;
}
