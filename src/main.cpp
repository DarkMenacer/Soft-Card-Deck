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
	cardDeck.push_back(SoftCardDeck::CardModel(SoftCardDeck::Rank::JACK, SoftCardDeck::Suit::HEARTS));
	cardDeck.push_back(SoftCardDeck::CardModel(SoftCardDeck::Rank::QUEEN, SoftCardDeck::Suit::HEARTS));
	cardDeck.push_back(SoftCardDeck::CardModel(SoftCardDeck::Rank::KING, SoftCardDeck::Suit::HEARTS));
	cardDeck.push_back(SoftCardDeck::CardModel(SoftCardDeck::Rank::ACE, SoftCardDeck::Suit::HEARTS));

	cardDeck2.push_back(SoftCardDeck::CardModel(SoftCardDeck::Rank::JACK, SoftCardDeck::Suit::CLUBS));
	cardDeck2.push_back(SoftCardDeck::CardModel(SoftCardDeck::Rank::QUEEN, SoftCardDeck::Suit::CLUBS));
	cardDeck2.push_back(SoftCardDeck::CardModel(SoftCardDeck::Rank::KING, SoftCardDeck::Suit::CLUBS));
	cardDeck2.push_back(SoftCardDeck::CardModel(SoftCardDeck::Rank::ACE, SoftCardDeck::Suit::CLUBS));

	cardDeck3.push_back(SoftCardDeck::CardModel(SoftCardDeck::Rank::JACK, SoftCardDeck::Suit::DIAMONDS));
	cardDeck3.push_back(SoftCardDeck::CardModel(SoftCardDeck::Rank::QUEEN, SoftCardDeck::Suit::DIAMONDS));
	cardDeck3.push_back(SoftCardDeck::CardModel(SoftCardDeck::Rank::KING, SoftCardDeck::Suit::DIAMONDS));
	cardDeck3.push_back(SoftCardDeck::CardModel(SoftCardDeck::Rank::ACE, SoftCardDeck::Suit::DIAMONDS));

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
				if(event.key.code == sf::Keyboard::C){}
				if(event.key.code == sf::Keyboard::F){}
				if(event.key.code == sf::Keyboard::Enter){}
			}
		}
		window.clear(sf::Color(0, 125, 0));
		boardView.display_board(250, 250, &window);
		window.display();
	}
	return 0;
}