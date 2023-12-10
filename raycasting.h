#ifndef RAYCASTING_H
#define RAYCASTING_H
#include <SDL.h>

typedef struct {
    int x;            // Player's x-coordinate
    int y;            // Player's y-coordinate
    float velocityX;  // Player's velocity in the x-direction
    float velocityY;  // Player's velocity in the y-direction
} Player;

// Constants for camera directions
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

// Function prototypes
int initSDL(void);
void cleanup(void);
void clearWindow(void);
void updateWindow(void);
int quitEvent(void);
void drawVerticalLine(int x, int startY, int endY, SDL_Color color);

// Raycasting functions
void raycast(void);
void rotateCamera(int direction);
void moveCamera(int direction);
void handleRotationInput(void);
void handleMovementInput(void);

#endif /* RAYCASTING_H */

