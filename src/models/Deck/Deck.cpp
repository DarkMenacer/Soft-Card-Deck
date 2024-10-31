#include "Deck.h"
#include "../Card/Card.h"
#include <algorithm>
#include <deque>
#include <memory>
#include <random>

SoftCardDeck::Deck::Deck(std::deque<Card> _cards) : __deckCards(_cards){
	this->__currentCard = this->__deckCards.begin();
}

SoftCardDeck::Card SoftCardDeck::Deck::top_card(){
	return this->__deckCards[this->__deckCards.size()-1];
}

SoftCardDeck::Card SoftCardDeck::Deck::bottom_card(){
	return this->__deckCards[0];
}

SoftCardDeck::Card SoftCardDeck::Deck::current_card(){
	return *this->__currentCard;
}

void SoftCardDeck::Deck::next_card(){
	++this->__currentCard;
	if(this->__currentCard == this->__deckCards.end()){
		this->__currentCard = this->__deckCards.begin();
	}
}

void SoftCardDeck::Deck::previous_card(){
	if(this->__currentCard == this->__deckCards.begin()){
		this->__currentCard = std::prev(this->__deckCards.end());
	}
	else{
		--this->__currentCard;
	}
}

void SoftCardDeck::Deck::flip_current_card(){
	this->__currentCard->flip();
}

void SoftCardDeck::Deck::face_up_deck(){
	for(auto &card: this->__deckCards){
		card.set_face_up();
	}
}

void SoftCardDeck::Deck::face_down_deck(){
	for(auto &card: this->__deckCards){
		card.set_face_down();
	}
}

void SoftCardDeck::Deck::shuffle(){
	std::shuffle(this->__deckCards.begin(), this->__deckCards.end(), std::default_random_engine {});
	this->__currentCard = this->__deckCards.begin();
}

void SoftCardDeck::Deck::sort(){
	//TODO: Need to come up with a clever way
}