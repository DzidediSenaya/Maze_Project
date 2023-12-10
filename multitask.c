#include "raycasting.h"

/**
 * handleMultiTask - Handle multiple events on the same frame.
 */
void handleMultiTask(void)
{
    // Check for keyboard input to move and rotate the camera simultaneously
    int moveDirection = 0;
    int rotateDirection = 0;

    if (keyIsPressed(SDL_SCANCODE_W))
        moveDirection |= MOVE_FORWARD;
    if (keyIsPressed(SDL_SCANCODE_S))
        moveDirection |= MOVE_BACKWARD;
    if (keyIsPressed(SDL_SCANCODE_A))
        rotateDirection |= ROTATE_LEFT;
    if (keyIsPressed(SDL_SCANCODE_D))
        rotateDirection |= ROTATE_RIGHT;

    moveAndRotateCamera(moveDirection, rotateDirection);
}
