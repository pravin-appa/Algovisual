#ifndef VISUAL_H
#define VISUAL_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <vector>
#include <stack>
#include "button.h"



#define DELAY 150

#define BUTTON_HEIGHT 100
#define AMOUNT_OF_BARS 100

enum algorithm { NONE, BUBBLE, INSERTION, SELECTION, MERGE, QUICK, BUCKET };

class Visual
{
public:
    Visual();
    Visual(const char* title, int xpos, int ypos, int w, int h, bool fullscreen);
    ~Visual();

    void handleEvents();
    void render();
    void update();

    void renderVectorBars() const;
    void setCurrentAlgorihtm(algorithm algorithm) { this->currentAlgorithm = algorithm; }
    void sortingHelper(int delay, std::vector<int> toHighlight);
    
    bool running() const { return isRunning; }
    void reset();
private:
    bool isRunning;
    algorithm currentAlgorithm = NONE;
    SDL_Window* window;
    SDL_Renderer* renderer;

    Button* bubbleSortButton;
    Button* insertionSortButton;
    Button* selectionSortButton;
    Button* mergeSortButton;
    Button* quickSortButton;


    std::vector<std::pair<int, int>> currVec;
   
    
    int w, h;
    void generateNewValues();
};

#endif
