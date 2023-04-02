/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Menu.cpp
*/

#include "Menu.hpp"

#define WINDOW_WIDTH 125
#define WINDOW_HEIGHT 15
#define FPS 60

Core::Menu::Menu(
    Display::IFactory &factory,
    std::vector<std::string> const &games,
    std::vector<std::string> const &graphics
)
{
    std::string const &titleStr = "Arcade";
    std::string const &gamesTitleStr = "Games";
    std::string const &graphicsTitleStr = "Graphics";
    std::string const &keyInfosStr = "Left/Right: Change game  |  Up/Down: Change graphic  |  Enter: Select game  |  Space: Select graphic  |  Escape: Quit";

    this->window = factory.createWindow("Menu", FPS, WINDOW_WIDTH, WINDOW_HEIGHT);
    this->renderClock = factory.createClock();
    this->arialFont = factory.createFont("assets/menu/arial.ttf");
    this->title = factory.createText(
        titleStr,
        *this->arialFont,
        Display::Color::BLUE,
        {(float)WINDOW_WIDTH / 2 - titleStr.size() / 2, 1}
    );
    this->gamesTitle = factory.createText(
        gamesTitleStr,
        *this->arialFont,
        Display::Color::WHITE,
        {(float)WINDOW_WIDTH / 2 - 30 - gamesTitleStr.size() / 2, 5}
    );
    this->graphicsTitle = factory.createText(
        graphicsTitleStr,
        *this->arialFont,
        Display::Color::WHITE,
        {(float)WINDOW_WIDTH / 2 + 30 + graphicsTitleStr.size() / 2, 5}
    );
    for (int i = 0; i < games.size(); i++) {
        this->gamesKeys.push_back(factory.createText(
            "[" + std::to_string(i + 1) + "]",
            *this->arialFont,
            i == 0 ? Display::Color::RED : Display::Color::WHITE,
            {(float)WINDOW_WIDTH / 2 - 30 - 10, (float)7 + 2 * i}
        ));
        this->gamesTexts.push_back(factory.createText(
            games[i],
            *this->arialFont,
            i == 0 ? Display::Color::RED : Display::Color::WHITE,
            {(float)WINDOW_WIDTH / 2 - 30 - 5, (float)7 + 2 * i}
        ));
    }
    for (int i = 0; i < graphics.size(); i++) {
        this->graphicsKeys.push_back(factory.createText(
            "[" + std::string(1, (char)('A' + i)) + "]",
            *this->arialFont,
            i == 0 ? Display::Color::RED : Display::Color::WHITE,
            {(float)WINDOW_WIDTH / 2 + 30 - 3, (float)7 + 2 * i}
        ));
        this->graphicsTexts.push_back(factory.createText(
            graphics[i],
            *this->arialFont,
            i == 0 ? Display::Color::RED : Display::Color::WHITE,
            {(float)WINDOW_WIDTH / 2 + 30 + 2, (float)7 + 2 * i}
        ));
    }
    this->keyInfos = factory.createText(
        keyInfosStr,
        *this->arialFont,
        Display::Color::WHITE,
        {(float)WINDOW_WIDTH / 2 - keyInfosStr.size() / 2, WINDOW_HEIGHT - 2}
    );
}

Core::Menu::~Menu()
{
}


void Core::Menu::setSelectedGame(int selectedGame)
{
    for (int i = 0; i < this->gamesKeys.size(); i++) {
        this->gamesKeys[i]->setColor(i == selectedGame ? Display::Color::RED : Display::Color::WHITE);
        this->gamesTexts[i]->setColor(i == selectedGame ? Display::Color::RED : Display::Color::WHITE);
    }
}

void Core::Menu::setSelectedGraphic(int selectedGraphic)
{
    for (int i = 0; i < this->graphicsKeys.size(); i++) {
        this->graphicsKeys[i]->setColor(i == selectedGraphic ? Display::Color::RED : Display::Color::WHITE);
        this->graphicsTexts[i]->setColor(i == selectedGraphic ? Display::Color::RED : Display::Color::WHITE);
    }
}

Display::Event Core::Menu::getEvent() const
{
    return this->window->getEvent();
}

void Core::Menu::render()
{
    if (this->renderClock->getElapsedTime() < 1000 / FPS)
        return;
    this->window->clear();
    this->window->draw(*this->title);
    this->window->draw(*this->gamesTitle);
    this->window->draw(*this->graphicsTitle);
    for (auto &gameKey : this->gamesKeys)
        this->window->draw(*gameKey);
    for (auto &gameText : this->gamesTexts)
        this->window->draw(*gameText);
    for (auto &graphicKey : this->graphicsKeys)
        this->window->draw(*graphicKey);
    for (auto &graphicText : this->graphicsTexts)
        this->window->draw(*graphicText);
    this->window->draw(*this->keyInfos);
    this->window->display();
    this->renderClock->restart();
}

void Core::Menu::stop()
{
    this->window->close();
}
