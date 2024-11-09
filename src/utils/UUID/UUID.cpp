#include "UUID.h"
#include <cstdlib>

// TODO: Move to boost::UUID implementation

SoftCardDeck::UUID::UUID(){this->__id = rand();}

int SoftCardDeck::UUID::id() const {return this->__id;}

bool SoftCardDeck::UUID::operator==(const UUID &u) const {return u.id() == this->__id;}