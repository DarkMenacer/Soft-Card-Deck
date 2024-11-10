#include <SFML/Graphics.hpp>
#include "./models/Card/Card.h"
#include "./constants/Card_Constants.h"
#include "models/Board/Board.h"
#include "models/Deck/Deck.h"
#include "utils/UUID/UUID.h"
#include "views/Card/Card.h"
#include "views/Deck/Deck.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <algorithm>
#include <deque>
#include <iostream>
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

	// SoftCardDeck::BoardModel myBoard(deckModels[0], deckModels[1], deckModels[2]);
	int currentDeck = 0;

	std::vector<SoftCardDeck::DeckView> deckViews;
	for(int j = 0; j < deckModels.size(); ++j){
		deckViews.push_back(deckModels[j]);
	}
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
					deckModels[currentDeck].next_card();
				}
				if(event.key.code == sf::Keyboard::Left){
					deckModels[currentDeck].previous_card();
				}
				if(event.key.code == sf::Keyboard::C){
					currentDeck = !currentDeck;
				}
				if(event.key.code == sf::Keyboard::Enter){
					deckModels[currentDeck].move_current_card_to(deckModels[!currentDeck]);
					for(int j = 0; j < std::min(2, (int)deckViews.size()); ++j){
						deckViews[j].display_deck(500-j*400, 275, &window);
					}
				}
			}
		}
		window.clear(sf::Color(0, 125, 0));
		for(int j = 0; j < std::min(2, (int)deckViews.size()); ++j){
			deckViews[j].display_deck(500-j*400, 275, &window);
		}
		window.display();
	}
	return 0;
}