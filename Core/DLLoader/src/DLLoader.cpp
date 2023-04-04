/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** DLLoader.cpp
*/

#include "DLLoader.hpp"
#include <exception>
#include <iostream>
#include <sstream>

Core::DLLoader::DLLoader(std::string const &path)
    : _handle(nullptr)
{
    this->_handle = dlopen(path.c_str(), RTLD_LAZY);
    std::cout << "Loading library: " << path;
    std::cout << (void *)this->_handle << std::endl << std::endl;
    if (this->_handle == nullptr) {
        std::ostringstream err_stream;
        err_stream << "Failed to load library: " << dlerror();
        throw std::runtime_error(err_stream.str());
    }
}

Core::DLLoader::~DLLoader()
{
    std::cout << "Closing library" << std::endl;
    std::cout << (void *)this->_handle << std::endl << std::endl;
    dlclose(this->_handle);
}

void Core::DLLoader::changeLib(std::string const &path)
{
    if (this->_handle != nullptr) {
        dlclose(this->_handle);
        std::cout << "Closing library toto";
        std::cout << (void *)this->_handle << std::endl << std::endl;
    }
    this->_handle = dlopen(path.c_str(), RTLD_LAZY);
    std::cout << "Loading library toto: " << path;
    std::cout << (void *)this->_handle << std::endl << std::endl;
    if (this->_handle == nullptr) {
        std::ostringstream err_stream;
        err_stream << "Failed to load library: " << dlerror();
        throw std::runtime_error(err_stream.str());
    }
}
