#include <iostream>
#include "ConsoleColor.h"

std::cout << green << "This text is written in green" 
          << white << std::endl;
std::cout << color(FOREGROUND_RED|FOREGROUND_GREEN) 
          << "This text has a really exiting color !" 
          << white << std::endl;
