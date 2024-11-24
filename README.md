# Soft-Card-Deck
## Deck of playing cards available at your disposal digitally

#### Technologies used:
    1. C++
    2. SFML
    3. Conan

---

### Purpose

Having a deck of playing cards with you is never a bad idea. It is a game universally loved across the age spectrum. I myself have fond memories of playing various card games with my grandparents. This is my love letter to those moments.

Along with that, this software also served the purpose of breaking the ice of me developing video games of sorts, a passion project I've been putting off for too long.

The purpose of this software is to make a deck of playing cards always accessible. In this Tabletop simulator-esque sandbox of playing cards, the only limit is your imagination.


### To Build:

##### MacOS
	conan install . --output-folder=build --build=missing
	cd build
	cmake -S .. -B . -DCMAKE_BUILD_TYPE=RELEASE -DCMAKE_EXPORT_COMPILE_COMMANDS=1
	make
	./SoftCardDeck

##### Windows/Linux
	- currently untested

---

### Game Docs

You can refer to the Wiki of this repository for the guide
	- [User inputs to trigger supported actions](https://github.com/DarkMenacer/Soft-Card-Deck/wiki/Available-Actions-and-Corresponding-Keys).

---

### Logs

    Created: 27 October 2024
    Last Edit: 24 November 2024

---
