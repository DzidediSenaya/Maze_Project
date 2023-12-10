/* raycasting.c */

#include "raycasting.h"

/**
 * drawMap - Draw the map on the window.
 * @map: 2D array representing the map.
 * @width: Width of the map.
 * @height: Height of the map.
 */
void drawMap(int **map, int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            SDL_Color color = (map[i][j] == 1) ? wallColor : floorColor;
            drawSquare(j * squareSize, i * squareSize, squareSize, color);
        }
    }
}

