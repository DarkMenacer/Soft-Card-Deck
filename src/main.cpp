#include <SFML/Graphics.hpp>
#include "./models/Card/Card.h"
#include "./constants/Card_Constants.h"
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <string>

int main(){
	SoftCardDeck::Card myCard(SoftCardDeck::Rank::JACK, SoftCardDeck::Suit::HEARTS);
	myCard.flip();

	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Playing Cards");
	sf::Texture texture;

	if(!texture.loadFromFile(myCard.path())){
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
			if(event.type == sf::Event::MouseButtonPressed){
				myCard.flip();
				texture.loadFromFile(myCard.path());
				sprite.setTexture(texture);
			}
		}
		window.clear();
		window.draw(sprite);
		window.display();
	}
	return 0;
}
