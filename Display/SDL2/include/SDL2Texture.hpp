/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDL2Texture
*/

#pragma once
#include "ITexture.hpp"
#include "SDL2/SDL.h"

namespace Display {
    class SDL2Texture : public ITexture {
        public:
            SDL2Texture() = default;
            ~SDL2Texture();
            void load(char c, std::string const &fpath) override;
            std::unique_ptr<ITexture> clone() const override;
            SDL_Texture *getSDLTexture() const;

        private:
            SDL_Texture *_texture;
            SDL_Renderer *_renderer;
    };
}