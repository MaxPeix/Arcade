/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFMLFactory.hpp
*/

#pragma once
#include "IFactory.hpp"
#include "SFMLWindow.hpp"
#include "SFMLSprite.hpp"
#include "SFMLTexture.hpp"
#include <memory>

namespace Display {
    class SFMLFactory : public IFactory {
        public:
            SFMLFactory();
            ~SFMLFactory() override;
            std::unique_ptr<Display::IWindow> createWindow(
                std::string const &title,
                int framerate,
                int width,
                int height
            ) override;
            std::unique_ptr<Display::ISprite> createSprite(
                Display::ITexture &src_texture,
                const Display::IntRect &src_rect,
                const Display::Vector2f &src_position
            ) override;
            std::unique_ptr<Display::ITexture> createTexture(
                char c,
                std::string const &fpath
            ) override;
    };
}
