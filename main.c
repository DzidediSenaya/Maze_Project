#include "raycasting.h"

/**
 * main - Entry point of the Raycasting Game.
 * Return: 0 on successful execution.
 */
int main(void)
{
    /*Initialize SDL and check for errors*/
    if (!initSDL())
    {
        fprintf(stderr, "Error: SDL initialization failed\n");
        return (1);
    }

    /*Main game loop*/
    while (!quitEvent())
    {
        /*Clear the window before rendering a new frame*/
        clearWindow();

        /*Perform raycasting to render the scene*/
        raycast();

        /*Update the window to display the rendered frame*/
        updateWindow();

        /*Handle user input for camera rotation*/
        handleRotationInput();
    }

    /*Cleanup resources and exit*/
    cleanup();
    return (0);
}

/**
 * handleRotationInput - Handle user input for camera rotation.
 */
void handleRotationInput(void)
{
    /*Check for keyboard input to rotate the camera*/
    if (keyIsPressed(SDL_SCANCODE_LEFT))
    {
        rotateCamera(LEFT);
    }
    else if (keyIsPressed(SDL_SCANCODE_RIGHT))
    {
        rotateCamera(RIGHT);
    }
}

