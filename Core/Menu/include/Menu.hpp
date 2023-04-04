/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Menu.hpp
*/

#pragma once
#include "IFactory.hpp"
#include "Event.hpp"
#include <vector>
#include <string>

namespace Core {
    class Menu {
        public:
            Menu(
                Display::IFactory &factory,
                std::vector<std::string> const &games,
                std::vector<std::string> const &graphics,
                std::string username
            );
            ~Menu();
            void setSelectedGame(int selectedGame);
            void setSelectedGraphic(int selectedGraphic);
            void setUsername(std::string const &username);
            Display::Event getEvent() const;
            void render();
            void stop();
            void updateFactory(Display::IFactory &factory);

        private:
            void init(Display::IFactory &factory);
            std::vector<std::string> games;
            std::vector<std::string> graphics;
            std::unique_ptr<Display::IWindow> window;
            std::unique_ptr<Display::IClock> renderClock;
            std::unique_ptr<Display::ITexture> backgroundTexture;
            std::unique_ptr<Display::ISprite> background;
            std::unique_ptr<Display::IFont> arialFont;
            std::unique_ptr<Display::IText> title;
            std::unique_ptr<Display::IText> gamesTitle;
            std::unique_ptr<Display::IText> graphicsTitle;
            std::vector<std::unique_ptr<Display::IText>> gamesTexts;
            std::vector<std::unique_ptr<Display::IText>> graphicsTexts;
            std::unique_ptr<Display::IText> keyInfos;
            std::string username;
            std::unique_ptr<Display::IText> usernameTitle;
            std::unique_ptr<Display::IText> usernameText;
    };
}
