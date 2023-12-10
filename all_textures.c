#include "raycasting.h"

// Define SDL_Texture for wall texture
SDL_Texture *wallTexture;

/**
 * loadTextures - Load textures from files.
 * Return: 1 on success, 0 on failure.
 */
int loadTextures(void)
{
    // Load wall texture
    wallTexture = loadImageTexture("path/to/your/wall_texture.png");
    if (!wallTexture)
    {
        fprintf(stderr, "Error: Failed to load wall texture\n");
        return 0; // Failure
    }

    // Add more textures loading as needed

    return 1; // Success
}

/**
 * drawTexturedWall - Draw textured walls on the window.
 * @x: Screen column where the wall will be drawn.
 * @startY: Starting screen coordinate of the wall segment.
 * @endY: Ending screen coordinate of the wall segment.
 * @texture: Texture to apply to the wall.
 */
void drawTexturedWall(int x, int startY, int endY, SDL_Texture *texture)
{
    int texWidth, texHeight;
    SDL_QueryTexture(texture, NULL, NULL, &texWidth, &texHeight);

    // Calculate the height of the wall segment
    int wallHeight = endY - startY;

    // Calculate the texture coordinate step
    float texStep = (float)texHeight / wallHeight;

    // Initial texture coordinate
    float texCoord = 0;

    // Draw the wall segment vertically
    for (int y = startY; y < endY; y++)
    {
        // Calculate the texture coordinate for the current pixel
        int texY = (int)texCoord;

        // Set the source and destination rectangles for rendering
        SDL_Rect srcRect = {0, texY, texWidth, 1};
        SDL_Rect destRect = {x, y, 1, 1}; // Draw one pixel at a time

        // Render the texture to the screen
        SDL_RenderCopy(renderer, texture, &srcRect, &destRect);

        // Move to the next texture coordinate
        texCoord += texStep;
    }
}

// Define SDL_Texture for ground texture
SDL_Texture *groundTexture;

/**
 * loadGroundTexture - Load texture for the ground.
 * Return: 1 on success, 0 on failure.
 */
int loadGroundTexture(void)
{
    // Load ground texture
    groundTexture = loadImageTexture("path/to/your/ground_texture.png");
    if (!groundTexture)
    {
        fprintf(stderr, "Error: Failed to load ground texture\n");
        return 0; // Failure
    }

    return 1; // Success
}


/**
 * drawTexturedGround - Draw textured ground on the window.
 */
void drawTexturedGround(void)
{
    int texWidth, texHeight;
    SDL_QueryTexture(groundTexture, NULL, NULL, &texWidth, &texHeight);

    // Assume your screen resolution is 800x600
    int screenWidth = 800;
    int screenHeight = 600;

    // Calculate the texture coordinate step
    float texStepX = (float)texWidth / screenWidth;
    float texStepY = (float)texHeight / screenHeight;

    // Initial texture coordinates
    float texCoordX = 0;
    float texCoordY = 0;

    // Draw the textured ground
    for (int y = screenHeight / 2; y < screenHeight; y++)
    {
        for (int x = 0; x < screenWidth; x++)
        {
            // Calculate the texture coordinates for the current pixel
            int texX = (int)texCoordX;
            int texY = (int)texCoordY;

            // Set the source and destination rectangles for rendering
            SDL_Rect srcRect = {texX, texY, 1, 1};
            SDL_Rect destRect = {x, y, 1, 1}; // Draw one pixel at a time

            // Render the texture to the screen
            SDL_RenderCopy(renderer, groundTexture, &srcRect, &destRect);

            // Move to the next texture coordinates
            texCoordX += texStepX;
        }

        // Move to the next row of texture coordinates
        texCoordX = 0;
        texCoordY += texStepY;
    }
}
