#include <SFML/Graphics.hpp>
#include "./models/Card/Card.h"
#include "./constants/Card_Constants.h"
#include "models/Board/Board.h"
#include "models/Deck/Deck.h"
#include "utils/UUID/UUID.h"
#include "views/Card/Card.h"
#include "views/Deck/Deck.h"
#include "views/Board/Board.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>

int main(){
	std::deque<SoftCardDeck::CardModel> cardDeck, cardDeck2, cardDeck3;
	cardDeck.push_back(SoftCardDeck::CardModel(SoftCardDeck::Rank::JACK, SoftCardDeck::Suit::DIAMONDS));
	cardDeck.push_back(SoftCardDeck::CardModel(SoftCardDeck::Rank::QUEEN, SoftCardDeck::Suit::DIAMONDS));
	cardDeck.push_back(SoftCardDeck::CardModel(SoftCardDeck::Rank::KING, SoftCardDeck::Suit::DIAMONDS));
	cardDeck.push_back(SoftCardDeck::CardModel(SoftCardDeck::Rank::ACE, SoftCardDeck::Suit::DIAMONDS));

	cardDeck2.push_back(SoftCardDeck::CardModel(SoftCardDeck::Rank::TWO, SoftCardDeck::Suit::SPADES));
	cardDeck2.push_back(SoftCardDeck::CardModel(SoftCardDeck::Rank::THREE, SoftCardDeck::Suit::SPADES));
	cardDeck2.push_back(SoftCardDeck::CardModel(SoftCardDeck::Rank::FOUR, SoftCardDeck::Suit::SPADES));
	cardDeck2.push_back(SoftCardDeck::CardModel(SoftCardDeck::Rank::FIVE, SoftCardDeck::Suit::HEARTS));
	cardDeck2.push_back(SoftCardDeck::CardModel(SoftCardDeck::Rank::SIX, SoftCardDeck::Suit::HEARTS));

	cardDeck3.push_back(SoftCardDeck::CardModel(SoftCardDeck::Rank::SEVEN, SoftCardDeck::Suit::HEARTS));
	cardDeck3.push_back(SoftCardDeck::CardModel(SoftCardDeck::Rank::EIGHT, SoftCardDeck::Suit::CLUBS));
	cardDeck3.push_back(SoftCardDeck::CardModel(SoftCardDeck::Rank::NINE, SoftCardDeck::Suit::CLUBS));
	cardDeck3.push_back(SoftCardDeck::CardModel(SoftCardDeck::Rank::TEN, SoftCardDeck::Suit::CLUBS));

	std::vector<SoftCardDeck::DeckModel> deckModels;
	deckModels.push_back(SoftCardDeck::DeckModel(cardDeck));
	deckModels.push_back(SoftCardDeck::DeckModel(cardDeck2));
	deckModels.push_back(SoftCardDeck::DeckModel(cardDeck3));

	SoftCardDeck::BoardModel myBoard(&deckModels[0], &deckModels[1], &deckModels[2]);
	SoftCardDeck::BoardView boardView = myBoard;

	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Playing Cards");
	while(window.isOpen()){
		window.clear();
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}
			if(event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::Right){
					myBoard.faced_up_deck()->next_card();
				}
				if(event.key.code == sf::Keyboard::Left){
					myBoard.faced_up_deck()->previous_card();
				}
				if(event.key.code == sf::Keyboard::F){
					myBoard.faced_up_deck()->current_card().flip();
				}
				if(event.key.code == sf::Keyboard::O){
					myBoard.faced_up_deck()->flip_deck();
				}
				if(event.key.code == sf::Keyboard::Enter){
					myBoard.faced_down_deck()->current_card().flip();
					myBoard.faced_down_deck()->move_current_card_to(*myBoard.faced_up_deck());
				}
				if(event.key.code == sf::Keyboard::R){
					myBoard.faced_up_deck()->move_current_card_to(*myBoard.removed_deck());
				}
				if(event.key.code == sf::Keyboard::S){
					myBoard.faced_down_deck()->shuffle();
					myBoard.faced_up_deck()->shuffle();
				}
				if(event.key.code == sf::Keyboard::M){
					myBoard.faced_up_deck()->current_card().flip();
					myBoard.faced_up_deck()->move_current_card_to(*myBoard.faced_down_deck());
				}
				if(event.key.code == sf::Keyboard::X){
					while(myBoard.removed_deck()->size()){
						myBoard.removed_deck()->move_current_card_to(*myBoard.faced_up_deck());
					}
				}
			}
		}
		window.clear(sf::Color(0, 125, 0));
		boardView.display_board(100, 250, &window);
		window.display();
	}
	return 0;
}