#pragma once

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <vector>
#include "blackjack.h"

struct item {
    const char name;
    std::optional<sf::Sprite> sprite;
    std::optional<sf::Text> text;
};

class BlackjackRenderer {
private:
    std::vector<item> buf_items;
public:
    void addItem(const item *item) {
        buf_items.push_back(*item);
    }
    void removeItem(const item *item) {
        auto ne = remove(buf_items.begin(), buf_items.end(), *item);
        buf_items.erase(ne, buf_items.end());
    }
    void render(sf::RenderWindow *window) {
        for (const auto &item : buf_items) {
            if (item.sprite.has_value()) {
                window->draw(item.sprite.value());
            }
            if (item.text.has_value()) {
                window->draw(item.text.value());
            }
        }
        window->display();
    }
};
