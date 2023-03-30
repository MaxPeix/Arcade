/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** NCursesWindow
*/

#pragma once
#include "IWindow.hpp"
#include <ncurses.h>

namespace Display {
    class NCursesWindow : public IWindow {
        public:
            NCursesWindow(
                const std::string &title,
                int framerateLimit,
                int width,
                int height);
            ~NCursesWindow();
            Display::Event getEvent() override;
            void setTitle(const std::string &title) override;
            bool isOpen() override;
            void clear() override;
            void draw(Display::ISprite &sprite) override;
            void display() override;
            void close() override;

        private:
            WINDOW *window;
    };
};
