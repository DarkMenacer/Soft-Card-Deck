#include "Card.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

SoftCardDeck::CardView::CardView(SoftCardDeck::CardModel &cardModel){
	this->__cardController = &cardModel;
}

void SoftCardDeck::CardView::display_card(float xCoordinate, float yCoordinate, sf::RenderWindow *window){
	sf::Texture texture;
	if(!texture.loadFromFile(this->__cardController->path())){return;}
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(xCoordinate, yCoordinate);
	window->draw(sprite);
}