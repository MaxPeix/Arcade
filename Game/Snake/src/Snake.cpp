/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Snake.cpp
*/

#include "Snake.hpp"
#include <iostream>
#include "SDL2Window.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <unistd.h>

#define WINDOW_WIDTH 100
#define WINDOW_HEIGHT 50

Game::Snake::Snake(Display::IFactory &factory)
{
    this->window = factory.createWindow("Snake", 60, WINDOW_WIDTH, WINDOW_HEIGHT);
    this->snakeTexture = factory.createTexture('#', "assets/snake/body.png");
    this->foodTexture = factory.createTexture('o', "assets/snake/food.png");
    this->arialFont = factory.createFont("assets/snake/arial.ttf");

    this->food = factory.createSprite(
        *this->foodTexture,
        {0, 0, 1, 1},
        {(float)(rand() % WINDOW_WIDTH) * 1,
        (float)(rand() % WINDOW_HEIGHT) * 1}
    );

    for (size_t i = 0; i < 4; i++) {
        this->snake.push_back(factory.createSprite(
            *this->snakeTexture,
            {0, 0, 1, 1},
            {(float)WINDOW_WIDTH / 2 + i, WINDOW_HEIGHT / 2}
        ));
    }

    this->scoreText = factory.createText(
        "Score: 0",
        *this->arialFont,
        Display::Color::WHITE,
        {0, 0}
    );

    this->direction = Game::Direction::RIGHT;
    this->setState(Game::State::GAME);
    this->score = 0;
}

Game::Snake::~Snake()
{
}

void Game::Snake::handleEvents()
{
    Display::Event event = this->window->getEvent();

    switch (event) {
        case Display::Event::Close:
            this->setState(Game::State::END);
            break;
        case Display::Event::Escape:
            this->setState(Game::State::MENU);
            break;
        case Display::Event::Q:
        case Display::Event::Left:
            if (this->direction == Game::Direction::RIGHT)
                this->setState(Game::State::END);
            this->direction = Game::Direction::LEFT;
            break;
        case Display::Event::D:
        case Display::Event::Right:
            if (this->direction == Game::Direction::LEFT)
                this->setState(Game::State::END);
            this->direction = Game::Direction::RIGHT;
            break;
        case Display::Event::Z:
        case Display::Event::Up:
            if (this->direction == Game::Direction::DOWN)
                this->setState(Game::State::END);
            this->direction = Game::Direction::UP;
            break;
        case Display::Event::S:
        case Display::Event::Down:
            if (this->direction == Game::Direction::UP)
                this->setState(Game::State::END);
            this->direction = Game::Direction::DOWN;
            break;
        default:
            break;
    }
}

void Game::Snake::moveSnake()
{
    switch (this->direction) {
        case Game::Direction::LEFT:
            this->snake[0]->move({-1, 0});
            break;
        case Game::Direction::RIGHT:
            this->snake[0]->move({1, 0});
            break;
        case Game::Direction::UP:
            this->snake[0]->move({0, -1});
            break;
        case Game::Direction::DOWN:
            this->snake[0]->move({0, 1});
            break;
        default:
            break;
    }

    for (size_t i = this->snake.size() - 1; i > 0; i--)
        this->snake[i]->setPosition(this->snake[i - 1]->getPosition());
}

void Game::Snake::handleEat(Display::IFactory &factory)
{
    if (this->snake[0]->getPosition().x == this->food->getPosition().x &&
        this->snake[0]->getPosition().y == this->food->getPosition().y) {
        this->snake.push_back(factory.createSprite(
            *this->snakeTexture,
            {0, 0, 1, 1},
            this->snake[this->snake.size() - 2]->getPosition()
        ));
        this->food->setPosition({
            (float)(rand() % WINDOW_WIDTH) * 1,
            (float)(rand() % WINDOW_HEIGHT) * 1
        });
        this->score++;
        this->scoreText->setText("Score: " + std::to_string(this->score));
    }
}

void Game::Snake::handleCollision()
{
    Display::Vector2f headPos;
    Display::Vector2f bodyPos;

    if (this->snake.size() > 4) {
        for (size_t i = 2; i < this->snake.size(); i++) {
            headPos = this->snake[0]->getPosition();
            bodyPos = this->snake[i]->getPosition();
            if (headPos.x == bodyPos.x && headPos.y == bodyPos.y)
                this->setState(Game::State::END);
        }
    }
    if (this->snake.size() >= WINDOW_WIDTH * WINDOW_HEIGHT)
        this->setState(Game::State::END);
    headPos = this->snake[0]->getPosition();
    if (headPos.x < 0)
        this->snake[0]->setPosition({(float)WINDOW_WIDTH - 1, headPos.y});
    if (headPos.x >= WINDOW_WIDTH)
        this->snake[0]->setPosition({0, headPos.y});
    if (headPos.y < 0)
        this->snake[0]->setPosition({headPos.x, (float)WINDOW_HEIGHT - 1});
    if (headPos.y >= WINDOW_HEIGHT)
        this->snake[0]->setPosition({headPos.x, 0});
}

void Game::Snake::updateWindow()
{
    this->window->clear();

    for (auto &sprite : this->snake)
        this->window->draw(*sprite);
    this->window->draw(*this->food);
    this->window->draw(*this->scoreText);

    this->window->display();
}

void Game::Snake::update(Display::IFactory &factory)
{
    this->handleEvents();
    switch (this->state) {
        case Game::State::MENU:
            this->window->close();
        case Game::State::GAME:
            this->moveSnake();
            this->handleEat(factory);
            this->handleCollision();
            this->updateWindow();
            break;
        case Game::State::END:
            this->stop();
            break;
        default:
            break;
    }
}

void Game::Snake::setState(Game::State state)
{
    this->state = state;
}

Game::State Game::Snake::getState() const
{
    return this->state;
}

void Game::Snake::run(Display::IFactory &factory)
{
    while (this->getState() != Game::State::END) {
        this->update(factory);
        usleep(100000);
    }
    this->stop();
}

void Game::Snake::stop()
{
    this->window->close();
}

const std::string &Game::Snake::getName() const
{
    return this->name;
}

extern "C" std::unique_ptr<Game::IGameModule> createGame(Display::IFactory &factory)
{
    return std::make_unique<Game::Snake>(factory);
}
