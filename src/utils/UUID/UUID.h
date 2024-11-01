#pragma once

namespace SoftCardDeck {
	class UUID {
		private:
			unsigned long int __id;
		public:
			UUID();
			int id() const;
			bool operator==(const UUID &u) const;
	};
}
