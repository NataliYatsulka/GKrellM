#include "Display.hpp"
#include "Graphical.hpp"
#include <iostream>


int     main(int ac, char **av)
{
	if (ac == 1) {
        std::cout << "Please use flag -g for graphical module" << std::endl;
        std::cout << "           flag -n for ncurses" << std::endl;
	}
	else if (strcmp(av[1], "-g") == 0) {
		Graphical	graphical;
		graphical.play();
    }
    else if (strcmp(av[1], "-n") == 0) {
        Display		display;
        display.play();
    }
    else {
        std::cout << "ERROR" << std::endl;
    }

    return 0;
}
