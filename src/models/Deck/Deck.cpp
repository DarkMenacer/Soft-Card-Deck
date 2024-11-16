#include "Deck.h"
#include "../Card/Card.h"
#include <algorithm>
#include <deque>
#include <iterator>
#include <memory>
#include <random>

SoftCardDeck::DeckModel::DeckModel(std::deque<CardModel> _cards) : __deckCards(_cards), __deckSize(_cards.size()){
	this->__currentCard = this->__deckCards.begin();
}

SoftCardDeck::CardModel SoftCardDeck::DeckModel::top_card(){
	return this->__deckCards[this->__deckCards.size()-1];
}

SoftCardDeck::CardModel SoftCardDeck::DeckModel::bottom_card(){
	return this->__deckCards[0];
}

SoftCardDeck::CardModel &SoftCardDeck::DeckModel::current_card(){
	return *this->__currentCard;
}

void SoftCardDeck::DeckModel::next_card(){
	++this->__currentCard;
	if(this->__currentCard == this->__deckCards.end()){
		this->__currentCard = this->__deckCards.begin();
	}
}

void SoftCardDeck::DeckModel::previous_card(){
	if(this->__currentCard == this->__deckCards.begin()){
		this->__currentCard = std::prev(this->__deckCards.end());
	}
	else{
		--this->__currentCard;
	}
}

void SoftCardDeck::DeckModel::flip_current_card(){
	this->__currentCard->flip();
}

void SoftCardDeck::DeckModel::face_up_deck(){
	for(auto &card: this->__deckCards){
		card.set_face_up();
	}
}

void SoftCardDeck::DeckModel::face_down_deck(){
	for(auto &card: this->__deckCards){
		card.set_face_down();
	}
}

void SoftCardDeck::DeckModel::shuffle(){
	std::shuffle(this->__deckCards.begin(), this->__deckCards.end(), std::default_random_engine {});
	this->__currentCard = this->__deckCards.begin();
}

void SoftCardDeck::DeckModel::sort(){
	// TODO: Need to come up with a clever way
}

int SoftCardDeck::DeckModel::size(){return this->__deckSize;}

void SoftCardDeck::DeckModel::add_card(SoftCardDeck::CardModel card){
	this->__deckCards.push_back(card);
	this->__deckSize = this->__deckCards.size();
}

void SoftCardDeck::DeckModel::delete_current_card(){
	if(!this->__deckSize){return;}
	this->__deckCards.erase(std::remove(this->__deckCards.begin(), this->__deckCards.end(), *this->__currentCard));
	this->__currentCard = this->__deckCards.begin();
	this->__deckSize = this->__deckCards.size();
}

void SoftCardDeck::DeckModel::move_current_card_to(SoftCardDeck::DeckModel &d){
	if(!this->__deckSize){return;}
	d.add_card(this->current_card());
	this->delete_current_card();
}

std::deque<SoftCardDeck::CardModel> *SoftCardDeck::DeckModel::deckCards(){
	return &this->__deckCards;
}