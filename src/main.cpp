#include <SFML/Graphics.hpp>
#include "./models/Card/Card.h"
#include "./constants/Card_Constants.h"
#include "models/Deck/Deck.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <deque>
#include <iostream>
#include <ostream>
#include <string>

int main(){
	std::deque<SoftCardDeck::Card> cardDeck;
	cardDeck.push_back(SoftCardDeck::Card(SoftCardDeck::Rank::JACK, SoftCardDeck::Suit::HEARTS));
	cardDeck.push_back(SoftCardDeck::Card(SoftCardDeck::Rank::QUEEN, SoftCardDeck::Suit::HEARTS));
	cardDeck.push_back(SoftCardDeck::Card(SoftCardDeck::Rank::KING, SoftCardDeck::Suit::HEARTS));
	cardDeck.push_back(SoftCardDeck::Card(SoftCardDeck::Rank::ACE, SoftCardDeck::Suit::HEARTS));

	SoftCardDeck::Deck myDeck(cardDeck);
	// SoftCardDeck::Card myCard(SoftCardDeck::Rank::JACK, SoftCardDeck::Suit::HEARTS);
	// myCard.flip();

	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Playing Cards");
	sf::Texture texture;

	if(!texture.loadFromFile(myDeck.current_card().path())){
		return -1;
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(375, 275);
	while(window.isOpen()){
		window.clear(sf::Color::Green);
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}
			if(event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::Right){
					myDeck.next_card();
					texture.loadFromFile(myDeck.current_card().path());
					sprite.setTexture(texture);
				}
				if(event.key.code == sf::Keyboard::Left){
					myDeck.previous_card();
					texture.loadFromFile(myDeck.current_card().path());
					sprite.setTexture(texture);
				}
				if(event.key.code == sf::Keyboard::Up){
					myDeck.flip_current_card();
					texture.loadFromFile(myDeck.current_card().path());
					sprite.setTexture(texture);
				}
				if(event.key.code == sf::Keyboard::Down){
					myDeck.shuffle();
					texture.loadFromFile(myDeck.current_card().path());
					sprite.setTexture(texture);
				}
			}
		}
		window.clear();
		window.draw(sprite);
		window.display();
	}
	return 0;
}
