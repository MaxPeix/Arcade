/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLIntRect
*/

#include "SFMLIntRect.hpp"

sf::IntRect Display::toSfIntRect(const IntRect &IIntrect)
{
    sf::IntRect dest{};

    dest.top = IIntrect.top;
    dest.left = IIntrect.left;
    dest.width = IIntrect.width;
    dest.height = IIntrect.height;
    return dest;
}

Display::IntRect Display::toIIntRect(const sf::IntRect &sfIntRect)
{
    IntRect dest{};

    dest.top = sfIntRect.top;
    dest.left = sfIntRect.left;
    dest.height = sfIntRect.height;
    dest.width = sfIntRect.width;
    return dest;
}
