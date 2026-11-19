#include "blackjack.h"
#include "../includes.h"

int Card::cardCount = 0;
std::vector<Card> drawnCards;
std::vector<Card> deck;

void Card::setDeck(std::vector<Card>& deck) {
    constexpr const char* ranks[] = {
        "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"
    };
    constexpr const char* suits[] = { "spades", "clubs", "hearts", "diamonds" };

    deck.clear();
    for (const char* suit : suits) {
        for (const char* rank : ranks) {
            deck.emplace_back(rank, suit);
        }
    }
}
