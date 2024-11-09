#include "Card.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

SoftCardDeck::CardView::CardView(const sf::Texture &texture_, const SoftCardDeck::UUID &id_) : __texture(texture_), __id(id_){}

void SoftCardDeck::CardView::display_card(float xCoordinate, float yCoordinate, sf::RenderWindow *window){
	sf::Sprite sprite;
	sprite.setTexture(this->__texture);
	sprite.setPosition(xCoordinate, yCoordinate);
	window->draw(sprite);
}

SoftCardDeck::UUID SoftCardDeck::CardView::id() {return this->__id;}

