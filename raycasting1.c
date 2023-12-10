#include "raycasting.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

/*Map configuration*/
int map[MAP_HEIGHT][MAP_WIDTH] = {
    {1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1},
    {1, 0, 1, 0, 1},
    {1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1},
};

/*Camera configuration*/
double cameraAngle = 0.0; /*Initial camera angle*/

/**
 * initSDL - Initializes SDL2 and creates a window for the game.
 *
 * Returns: 1 on success, 0 on failure.
 */
int initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 0;
    }

    window = SDL_CreateWindow("Raycasting Game", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (window == NULL) {
        SDL_Log("Unable to create window: %s", SDL_GetError());
        return 0;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        SDL_Log("Unable to create renderer: %s", SDL_GetError());
        return 0;
    }

    return 1;
}

/**
 * clearWindow - Sets the background color to white and clears the window.
 */
void clearWindow() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
}

/**
 * raycast - The main raycasting logic goes here.
 *           Draws walls based on the map and camera configuration.
 */
void raycast()
{
    /*Perform raycasting logic and draw walls*/
}

/**
 * updateWindow - Updates the window to display the rendered content.
 */
void updateWindow()
{
    SDL_RenderPresent(renderer);
}

/**
 * quitEvent - Polls for SDL events and returns 1 if the user wants to quit.
 *
 * Return: 1 if the user wants to quit, 0 otherwise.
 */
int quitEvent()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) 
{
        if (event.type == SDL_QUIT)
{
            return (1);
        }
    }
    return (0);
}

/**
 * cleanup - Destroys the SDL window and renderer, and quits SDL.
 */
void cleanup()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

