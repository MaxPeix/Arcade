/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** NCursesRenderer
*/

#include "NCursesRenderer.hpp"
#include <memory>

Display::NCursesRenderer::~NCursesRenderer()
{
}

void Display::NCursesRenderer::create(Display::IWindow &window)
{
    (void)window;
}

extern "C" std::unique_ptr<Display::IRenderer> createRenderer()
{
    return std::make_unique<Display::NCursesRenderer>();
}
