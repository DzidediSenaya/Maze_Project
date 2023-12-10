#include "raycasting.h"

/*Define constants for camera directions*/
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

/*Global variable for camera direction*/
int cameraDirection = NORTH;

/**
 * raycast - Perform raycasting to render the scene.
 */
void raycast(void)
{

    /*Inside your drawing loop*/
    SDL_Color wallColor;

    /*Check the orientation of the current wall*/
    if (cameraDirection == NORTH || cameraDirection == SOUTH)
    {
        wallColor = (cameraDirection == NORTH) ? northColor : southColor;
    }
    else
    {
        wallColor = (cameraDirection == EAST) ? eastColor : westColor;
    }

    /*Draw the walls with the chosen color*/
    drawVerticalLine(x, wallStart, wallEnd, wallColor);
}


/**
 * rotateCamera - Rotate the camera in the specified direction.
 * @direction: Direction to rotate the camera (LEFT or RIGHT).
 */
void rotateCamera(int direction)
{
    /*Update the camera direction based on the rotation*/
    if (direction == LEFT)
    {
        cameraDirection = (cameraDirection - 1 + 4) % 4;
    }
    else if (direction == RIGHT)
    {
        cameraDirection = (cameraDirection + 1) % 4;
    }
}

