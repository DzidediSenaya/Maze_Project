/*#include raycasting.h*/

/**
 * drawWall - Draw a wall segment with orientation-dependent color.
 * @x: X-coordinate of the wall.
 * @startY: Starting Y-coordinate of the wall segment.
 * @endY: Ending Y-coordinate of the wall segment.
 */
void drawWall(int x, int startY, int endY) {
    SDL_Color wallColor;

    // Check the orientation of the current wall
    if (cameraDirection == NORTH || cameraDirection == SOUTH) {
        wallColor = (cameraDirection == NORTH) ? northColor : southColor;
    } else {
        wallColor = (cameraDirection == EAST) ? eastColor : westColor;
    }

    // Draw the walls with the chosen color
    drawVerticalLine(x, startY, endY, wallColor);
}


/**
 * handleRotationInput - Handle user input for camera rotation.
 */
void handleRotationInput(void) {
    // Check for keyboard input to rotate the camera
    if (keyIsPressed(SDL_SCANCODE_LEFT)) {
        rotateCamera(LEFT);
    } else if (keyIsPressed(SDL_SCANCODE_RIGHT)) {
        rotateCamera(RIGHT);
    }
}


/**
 * handleMovementInput - Handle user input for camera movement.
 */
void handleMovementInput(void) {
    // Check for keyboard input to move the camera
    if (keyIsPressed(SDL_SCANCODE_W)) {
        moveCamera(FORWARD);
    } else if (keyIsPressed(SDL_SCANCODE_A)) {
        moveCamera(LEFT);
    } else if (keyIsPressed(SDL_SCANCODE_S)) {
        moveCamera(BACKWARD);
    } else if (keyIsPressed(SDL_SCANCODE_D)) {
        moveCamera(RIGHT);
    }
}


/**
 * handleCollisions - Handle collisions with walls.
 */
void handleCollisions(void)
{
    // Check the position of the player (camera)
    int playerX = getPlayerX();  // Replace with your actual player position function
    int playerY = getPlayerY();  // Replace with your actual player position function

    // Check if the player is inside a wall
    if (map[playerX][playerY] == 1)
    {
        // Handle the collision by stopping the player
        setPlayerVelocity(0, 0);  // Replace with your actual function to set player velocity to zero
    }
}

/**
 * setPlayerVelocity - Sets the velocity of the player (camera) in the x and y directions.
 * @vx: Velocity in the x-direction.
 * @vy: Velocity in the y-direction.
 */
void setPlayerVelocity(float vx, float vy) {
    player.velocityX = vx;
    player.velocityY = vy;
}

