#pragma once

#include <vector>

class Card {
private:
    const char *rank;
    const char *suit;

    static int cardCount;
public:
    Card(const char *rank, const char *suit): rank(rank), suit(suit) {}
    Card(): rank(nullptr), suit(nullptr) { cardCount++; }
    ~Card() {}

    [[nodiscard]] const char *getRank() const { return rank; }
    [[nodiscard]] const char *getSuit() const { return suit; }

    void setRank(const char *rank) { this->rank = rank; }
    void setSuit(const char *suit) { this->suit = suit; }

    static void setDeck(std::vector<Card>& deck);
};

