#include <map>
#include <string>
#include "Card_Constants.h"

std::map<SoftCardDeck::Rank, std::string> SoftCardDeck::rankMapper = {
	{SoftCardDeck::Rank::ACE, "ace"}, {SoftCardDeck::Rank::TWO, "2"}, {SoftCardDeck::Rank::THREE, "3"}, {SoftCardDeck::Rank::FOUR, "4"}, {SoftCardDeck::Rank::FIVE, "5"}, {SoftCardDeck::Rank::SIX, "6"}, {SoftCardDeck::Rank::SEVEN, "7"}, {SoftCardDeck::Rank::EIGHT, "8"}, {SoftCardDeck::Rank::NINE, "9"}, {SoftCardDeck::Rank::TEN, "10"}, {SoftCardDeck::Rank::JACK, "jack"}, {SoftCardDeck::Rank::QUEEN, "queen"}, {SoftCardDeck::Rank::KING, "king"}
};

std::map<SoftCardDeck::Suit, std::string> SoftCardDeck::suitMapper = {
	{SoftCardDeck::Suit::CLUBS, "clubs"}, {SoftCardDeck::Suit::DIAMONDS, "diamonds"}, {SoftCardDeck::Suit::HEARTS, "hearts"}, {SoftCardDeck::Suit::SPADES, "spades"}
};