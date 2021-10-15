#include <SDL.h>
#undef main
#include <SDL_ttf.h>
#include <iostream>
#include <stdexcept>
#include <string.h>
#include <utility>
#include <ctime>
#include <iomanip>
#include "visual.h"




#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 600


int main(int argc, char* argv[])
{
   try
    {
          
        Visual* visual = new Visual("Sorting visualizer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false);
        while (visual->running())
        {
            visual->handleEvents();
            visual->update();
            visual->render();
        }
        delete visual;
        
           
    }
    catch (std::runtime_error& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    
    return 0;
}
