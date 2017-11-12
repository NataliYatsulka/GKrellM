#include "Graphical.hpp"

Graphical::Graphical() {}
Graphical::Graphical(Graphical const &src) {
    *this = src;
}
Graphical & Graphical::operator=(Graphical const &src) {
    (void)src;
    return *this;
}
Graphical::~Graphical() {}

/*void    Graphical::draw(sf::RenderWindow *window, int i) {


//    text.setPosition(x, y);

    switch (i) {
        case 1 : text.setString(this->_cpu.getCpu());
            break;
        case 2 : text.setString(this->_module.getTimeModule());
            break;
        case 3 : text.setString(this->_raw.getRaw());
            break;
        case 4 : text.setString(this->_host.getUserName());
            break;
        case 5 : text.setString(this->_host.getHostName2());
            break;
        case 6 : text.setString(this->_os.getOsModuleKernel());
            break;
        case 7 : text.setString(this->_os.getOsModuleBootVolume());
            break;
        case 8 : text.setString(this->_os.getOsModuleSysVersion());
            break;
        default:
            break;
    }

    text.setCharacterSize(24);

    text.setFillColor(sf::Color::Black);

    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    *(window).draw(text);
}*/

void    Graphical::play() {
    sf::RenderWindow window(sf::VideoMode(3000, 2000), "ft_gkrellm");
    sf::Text text;
    sf::Font font;

    font.loadFromFile("Roboto-Bold.ttf");
    text.setFont(font);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        text.setPosition(100, 50);
        text.setString(this->_cpu.getCpu());
        text.setCharacterSize(24);
//        text.setFillColor(sf::Color::Black);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        window.draw(text);
        text.setPosition(1900, 300);
        text.setString(this->_module.getTimeModule());
        text.setCharacterSize(24);
//        text.setFillColor(sf::Color::Black);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        window.draw(text);
        text.setPosition(1900, 200);
        text.setString(this->_raw.getRaw());
        text.setCharacterSize(24);
//        text.setFillColor(sf::Color::Black);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        window.draw(text);
        text.setPosition(1400, 50);
        text.setString(this->_host.getUserName());
        text.setCharacterSize(24);
//        text.setFillColor(sf::Color::Black);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        window.draw(text);
        text.setPosition(1400, 80);
        text.setString(this->_host.getHostName2());
        text.setCharacterSize(24);
//        text.setFillColor(sf::Color::Black);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        window.draw(text);
        text.setPosition(1900, 50);
        text.setString(this->_os.getOsModuleKernel());
        text.setCharacterSize(24);
//        text.setFillColor(sf::Color::Black);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        window.draw(text);
        text.setPosition(1900, 80);
        text.setString(this->_os.getOsModuleBootVolume());
        text.setCharacterSize(24);
//        text.setFillColor(sf::Color::Black);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        window.draw(text);
        text.setPosition(1900, 110);
        text.setString(this->_os.getOsModuleSysVersion());
        text.setCharacterSize(24);
//        text.setFillColor(sf::Color::Black);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        window.draw(text);
        window.display();
    }
}


/*
 * sf::Text text;

// select the font
text.setFont(font); // font is a sf::Font

// set the string to display
text.setString("Hello world");

// set the character size
text.setCharacterSize(24); // in pixels, not points!

// set the color
text.setFillColor(sf::Color::Red);

// set the text style
text.setStyle(sf::Text::Bold | sf::Text::Underlined);

...

// inside the main loop, between window.clear() and window.display()
window.draw(text);
 */