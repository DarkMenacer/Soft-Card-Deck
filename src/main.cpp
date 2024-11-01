#include <SFML/Graphics.hpp>
#include "./models/Card/Card.h"
#include "./constants/Card_Constants.h"
#include "models/Deck/Deck.h"
#include "utils/UUID/UUID.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <deque>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

struct displayCard {
	sf::Texture texture;
	SoftCardDeck::UUID id;
};

int main(){
	std::deque<SoftCardDeck::Card> cardDeck, cardDeck2;
	cardDeck.push_back(SoftCardDeck::Card(SoftCardDeck::Rank::JACK, SoftCardDeck::Suit::HEARTS));
	cardDeck.push_back(SoftCardDeck::Card(SoftCardDeck::Rank::QUEEN, SoftCardDeck::Suit::HEARTS));
	cardDeck.push_back(SoftCardDeck::Card(SoftCardDeck::Rank::KING, SoftCardDeck::Suit::HEARTS));
	cardDeck.push_back(SoftCardDeck::Card(SoftCardDeck::Rank::ACE, SoftCardDeck::Suit::HEARTS));

	cardDeck2.push_back(SoftCardDeck::Card(SoftCardDeck::Rank::JACK, SoftCardDeck::Suit::CLUBS));
	cardDeck2.push_back(SoftCardDeck::Card(SoftCardDeck::Rank::QUEEN, SoftCardDeck::Suit::CLUBS));
	cardDeck2.push_back(SoftCardDeck::Card(SoftCardDeck::Rank::KING, SoftCardDeck::Suit::CLUBS));
	cardDeck2.push_back(SoftCardDeck::Card(SoftCardDeck::Rank::ACE, SoftCardDeck::Suit::CLUBS));

	std::vector<SoftCardDeck::Deck> myDeckVector;
	myDeckVector.push_back(SoftCardDeck::Deck(cardDeck));
	myDeckVector.push_back(SoftCardDeck::Deck(cardDeck2));
	int currentDeck = 0;

	std::vector<std::vector<displayCard> > cardTexturesVector;
	for(int j = 0; j < myDeckVector.size(); ++j){
		std::vector<displayCard> cardTextures;
		for(int i = 0; i < myDeckVector[j].size(); ++i){
			sf::Texture texture;
			if(!texture.loadFromFile(myDeckVector[j].current_card().path())){
				return -1;
			}
			cardTextures.push_back({texture, myDeckVector[j].current_card().uuid()});
			myDeckVector[j].next_card();
		}
		cardTexturesVector.push_back(cardTextures);
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
					myDeckVector[currentDeck].move_current_card_to(myDeckVector[!currentDeck]);
					cardTexturesVector[currentDeck].clear();
					std::vector<displayCard> cardTextures;
					for(int j = 0; j < myDeckVector.size(); ++j){
						std::vector<displayCard> cardTextures;
						for(int i = 0; i < myDeckVector[j].size(); ++i){
							sf::Texture texture;
							if(!texture.loadFromFile(myDeckVector[j].current_card().path())){
								return -1;
							}
							cardTextures.push_back({texture, myDeckVector[j].current_card().uuid()});
							myDeckVector[j].next_card();
						}
						cardTexturesVector[j] = cardTextures;
					}
				}
			}
		}
		window.clear(sf::Color(0, 125, 0));
		for(int j = 0; j < myDeckVector.size(); ++j){
			for(int i = 0; i < myDeckVector[j].size(); ++i){
				sf::Sprite sprite;
				int selected = 0;
				if(cardTexturesVector[j][i].id == myDeckVector[j].current_card().uuid()){
					selected = 50;
				}
				sprite.setTexture(cardTexturesVector[j][i].texture);
				sprite.setPosition(375+30*i+200-j*400, 275-selected);
				window.draw(sprite);
			}
		}
		window.display();
	}
	return 0;
}
