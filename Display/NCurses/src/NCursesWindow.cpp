/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** NCursesWindow
*/

#include "NCursesWindow.hpp"
#include "NCursesTexture.hpp"
#include "NCursesSprite.hpp"
#include "NCursesText.hpp"

void init_colors()
{
    start_color();
    init_pair(0, COLOR_BLACK, COLOR_BLACK);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

Display::NCursesWindow::NCursesWindow(
    const std::string &title,
    int framerateLimit,
    int width,
    int height
)
{
    initscr();
    raw();
    noecho();
    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    init_colors();
    this->window = newwin(height, width, 0, 0);
    wattron(this->window, COLOR_PAIR(7));
}

Display::NCursesWindow::~NCursesWindow()
{
    this->close();
}

Display::Event Display::NCursesWindow::getEvent()
{
    int key = getch();

    switch (key) {
        case 'a':
        case 'A':
            return Display::Event::A;
        case 'b':
        case 'B':
            return Display::Event::B;
        case 'c':
        case 'C':
            return Display::Event::C;
        case 'd':
        case 'D':
            return Display::Event::D;
        case 'e':
        case 'E':
            return Display::Event::E;
        case 'f':
        case 'F':
            return Display::Event::F;
        case 'g':
        case 'G':
            return Display::Event::G;
        case 'h':
        case 'H':
            return Display::Event::H;
        case 'i':
        case 'I':
            return Display::Event::I;
        case 'j':
        case 'J':
            return Display::Event::J;
        case 'k':
        case 'K':
            return Display::Event::K;
        case 'l':
        case 'L':
            return Display::Event::L;
        case 'm':
        case 'M':
            return Display::Event::M;
        case 'n':
        case 'N':
            return Display::Event::N;
        case 'o':
        case 'O':
            return Display::Event::O;
        case 'p':
        case 'P':
            return Display::Event::P;
        case 'q':
        case 'Q':
            return Display::Event::Q;
        case 'r':
        case 'R':
            return Display::Event::R;
        case 's':
        case 'S':
            return Display::Event::S;
        case 't':
        case 'T':
            return Display::Event::T;
        case 'u':
        case 'U':
            return Display::Event::U;
        case 'v':
        case 'V':
            return Display::Event::V;
        case 'w':
        case 'W':
            return Display::Event::W;
        case 'x':
        case 'X':
            return Display::Event::X;
        case 'y':
        case 'Y':
            return Display::Event::Y;
        case 'z':
        case 'Z':
            return Display::Event::Z;
        case '0':
        case KEY_F(10):
            return Display::Event::Num0;
        case '1':
        case KEY_F(1):
            return Display::Event::Num1;
        case '2':
        case KEY_F(2):
            return Display::Event::Num2;
        case '3':
        case KEY_F(3):
            return Display::Event::Num3;
        case '4':
        case KEY_F(4):
            return Display::Event::Num4;
        case '5':
        case KEY_F(5):
            return Display::Event::Num5;
        case '6':
        case KEY_F(6):
            return Display::Event::Num6;
        case '7':
        case KEY_F(7):
            return Display::Event::Num7;
        case '8':
        case KEY_F(8):
            return Display::Event::Num8;
        case '9':
        case KEY_F(9):
            return Display::Event::Num9;
        case KEY_LEFT:
            return Display::Event::Left;
        case KEY_RIGHT:
            return Display::Event::Right;
        case KEY_UP:
            return Display::Event::Up;
        case KEY_DOWN:
            return Display::Event::Down;
        case 27:
            return Display::Event::Escape;
        case 10:
        case 13:
        case KEY_ENTER:
            return Display::Event::Enter;
        case 32:
            return Display::Event::Space;
        case 127:
            return Display::Event::Backspace;
        case KEY_BACKSPACE:
            return Display::Event::Backspace;
        default:
            break;
    }
    return Display::Event::Unknown;
}

void Display::NCursesWindow::setTitle(const std::string &title)
{
    (void)title;
}

bool Display::NCursesWindow::isOpen()
{
    return this->window != nullptr;
}

void Display::NCursesWindow::clear()
{
    if (!this->window)
        return;
    wclear(this->window);
}

void Display::NCursesWindow::draw(Display::ISprite &sprite)
{
    if (!this->window)
        return;

    Display::NCursesSprite &ncursesSprite = dynamic_cast<Display::NCursesSprite &>(sprite);
    char c = ncursesSprite.getChar();
    Vector2f pos = sprite.getPosition();

    mvwprintw(this->window, pos.y, pos.x, "%c", c);
}

void Display::NCursesWindow::draw(Display::IText &text)
{
    if (!this->window)
        return;

    Display::NCursesText &ncursesText = dynamic_cast<Display::NCursesText &>(text);
    std::string str = ncursesText.getText();
    Display::Color color = ncursesText.getColor();
    Vector2f pos = text.getPosition();

    switch (color) {
        case Display::Color::BLACK:
            wattron(this->window, COLOR_PAIR(0));
            break;
        case Display::Color::WHITE:
            wattron(this->window, COLOR_PAIR(7));
            break;
        case Display::Color::RED:
            wattron(this->window, COLOR_PAIR(1));
            break;
        case Display::Color::GREEN:
            wattron(this->window, COLOR_PAIR(2));
            break;
        case Display::Color::YELLOW:
            wattron(this->window, COLOR_PAIR(3));
            break;
        case Display::Color::BLUE:
            wattron(this->window, COLOR_PAIR(4));
            break;
        case Display::Color::MAGENTA:
            wattron(this->window, COLOR_PAIR(5));
            break;
        case Display::Color::CYAN:
            wattron(this->window, COLOR_PAIR(6));
            break;
        default:
            break;
    }

    mvwprintw(this->window, pos.y, pos.x, "%s", str.c_str());

    wattr_off(this->window, A_COLOR, NULL);
}

void Display::NCursesWindow::display()
{
    if (!this->window)
        return;
    wrefresh(this->window);
}

void Display::NCursesWindow::close()
{
    if (!this->window)
        return;
    delwin(this->window);
}
