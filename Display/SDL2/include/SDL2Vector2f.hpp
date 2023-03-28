/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDLVector2f
*/

#pragma once
#include "IVector2f.hpp"
#include "SDL2/SDL_rect.h"

namespace Display {
    SDL_Point toSdlVector2f(const IVector2f &IVector2f)
    {
        SDL_Point dest{};

        dest.x = IVector2f.x;
        dest.y = IVector2f.y;
        return dest;
    }

    IVector2f toIVector2f(const SDL_Point &sdlVector2f)
    {
        IVector2f dest{};

        dest.x = sdlVector2f.x;
        dest.y = sdlVector2f.y;
        return dest;
    }
}