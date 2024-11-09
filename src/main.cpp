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

	std::vector<SoftCardDeck::DeckModel> myDeckVector;
	myDeckVector.push_back(SoftCardDeck::DeckModel(cardDeck));
	myDeckVector.push_back(SoftCardDeck::DeckModel(cardDeck2));
	myDeckVector.push_back(SoftCardDeck::DeckModel(cardDeck3));

	// SoftCardDeck::BoardModel myBoard(myDeckVector[0], myDeckVector[1], myDeckVector[2]);
	int currentDeck = 0;

	std::vector<SoftCardDeck::DeckView> cardTexturesVector;
	for(int j = 0; j < myDeckVector.size(); ++j){
		cardTexturesVector.push_back(myDeckVector[j]);
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
					myDeckVector[currentDeck].next_card();
				}
				if(event.key.code == sf::Keyboard::Left){
					myDeckVector[currentDeck].previous_card();
				}
				if(event.key.code == sf::Keyboard::C){
					currentDeck = !currentDeck;
				}
				if(event.key.code == sf::Keyboard::Enter){
					// myDeckVector[currentDeck].move_current_card_to(myDeckVector[!currentDeck]);
					// cardTexturesVector[currentDeck].clear();
					// std::vector<SoftCardDeck::CardView> cardTextures;
					// for(int j = 0; j < myDeckVector.size(); ++j){
					// 	std::vector<SoftCardDeck::CardView> cardTextures;
					// 	for(int i = 0; i < myDeckVector[j].size(); ++i){
					// 		sf::Texture texture;
					// 		if(!texture.loadFromFile(myDeckVector[j].current_card().path())){
					// 			return -1;
					// 		}
					// 		SoftCardDeck::CardView cv = SoftCardDeck::CardView(texture, myDeckVector[j].current_card().uuid());
					// 		cardTextures.push_back(cv);
					// 		myDeckVector[j].next_card();
					// 	}
					// 	cardTexturesVector[j] = cardTextures;
					// }
				}
			}
		}
		window.clear(sf::Color(0, 125, 0));
		for(int j = 0; j < std::min(2, (int)cardTexturesVector.size()); ++j){
			cardTexturesVector[j].display_deck(500-j*400, 275, &window);
		}
		window.display();
	}
	return 0;
}
