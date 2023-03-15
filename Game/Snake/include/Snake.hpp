/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Snake.hpp
*/

#pragma once
#include "IGameModule.hpp"

namespace Game {

    class Snake : public IGameModule {
    public:
        Snake();

        ~Snake() override;

        void init() override;

        void stop() override;

        [[nodiscard]] const std::string &getName() const override;

        [[nodiscard]] const std::vector<IGameObject> &
        getObjects() const override;
    private:
        std::string name;
    };
}
