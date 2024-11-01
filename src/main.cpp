#include <SFML/Graphics.hpp>
#include "./models/Card/Card.h"
#include "./constants/Card_Constants.h"
<<<<<<< Updated upstream
=======
#include "models/Deck/Deck.h"
#include "utils/UUID/UUID.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
>>>>>>> Stashed changes
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <string>
#include <vector>

struct displayCard {
	sf::Texture texture;
	SoftCardDeck::UUID id;
};

int main(){
<<<<<<< Updated upstream
	SoftCardDeck::Card myCard(SoftCardDeck::Rank::JACK, SoftCardDeck::Suit::HEARTS);
	myCard.flip();

	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Playing Cards");
	sf::Texture texture;

	if(!texture.loadFromFile(myCard.path())){
		return -1;
=======
	std::deque<SoftCardDeck::Card> cardDeck;
	cardDeck.push_back(SoftCardDeck::Card(SoftCardDeck::Rank::JACK, SoftCardDeck::Suit::HEARTS));
	cardDeck.push_back(SoftCardDeck::Card(SoftCardDeck::Rank::QUEEN, SoftCardDeck::Suit::HEARTS));
	cardDeck.push_back(SoftCardDeck::Card(SoftCardDeck::Rank::KING, SoftCardDeck::Suit::HEARTS));
	cardDeck.push_back(SoftCardDeck::Card(SoftCardDeck::Rank::ACE, SoftCardDeck::Suit::HEARTS));

	SoftCardDeck::Deck myDeck(cardDeck);

	std::vector<displayCard> cardTextures;
	for(int i = 0; i < myDeck.size(); ++i){
		sf::Texture texture;
		if(!texture.loadFromFile(myDeck.current_card().path())){
			return -1;
		}
		cardTextures.push_back({texture, myDeck.current_card().uuid()});
		myDeck.next_card();
>>>>>>> Stashed changes
	}
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Playing Cards");
	while(window.isOpen()){
		window.clear();
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}
<<<<<<< Updated upstream
			if(event.type == sf::Event::MouseButtonPressed){
				myCard.flip();
				texture.loadFromFile(myCard.path());
				sprite.setTexture(texture);
=======
			if(event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::Right){
					myDeck.next_card();
				}
				if(event.key.code == sf::Keyboard::Left){
					myDeck.previous_card();
				}
				// if(event.key.code == sf::Keyboard::Up){
				// 	myDeck.flip_current_card();
				// 	texture.loadFromFile(myDeck.current_card().path());
				// 	sprite.setTexture(texture);
				// }
				// if(event.key.code == sf::Keyboard::Down){
				// 	myDeck.shuffle();
				// 	texture.loadFromFile(myDeck.current_card().path());
				// 	sprite.setTexture(texture);
				// }
>>>>>>> Stashed changes
			}
		}
		window.clear(sf::Color(0, 125, 0));
		for(int i = 0; i < myDeck.size(); ++i){
			sf::Sprite sprite;
			int selected = 0;
			if(cardTextures[i].id == myDeck.current_card().uuid()){
				selected = 50;
			}
			sprite.setTexture(cardTextures[i].texture);
			sprite.setPosition(375+30*i, 275-selected);
			window.draw(sprite);
		}
		window.display();
	}
	return 0;
}
