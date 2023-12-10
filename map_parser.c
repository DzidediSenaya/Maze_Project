#include "raycasting.h"

/**
 * parseMapFromFile - Parse the map from a file.
 * @filePath: Path to the map file.
 * @map: 2D array to store the parsed map.
 * @width: Pointer to store the width of the parsed map.
 * @height: Pointer to store the height of the parsed map.
 * Return: 1 on success, 0 on failure.
 */
int parseMapFromFile(const char *filePath, int ***map, int *width, int *height)
{
    FILE *file = fopen(filePath, "r");
    if (!file)
    {
        fprintf(stderr, "Error: Could not open file %s\n", filePath);
        return 0; // Failure
    }

    // Read the width and height from the file (you need to define your file format)
    fscanf(file, "%d %d", width, height);

    // Allocate memory for the map
    *map = malloc(*height * sizeof(int *));
    if (!*map)
    {
        fprintf(stderr, "Error: Failed to allocate memory for the map\n");
        fclose(file);
        return 0; // Failure
    }

    for (int i = 0; i < *height; i++)
    {
        (*map)[i] = malloc(*width * sizeof(int));
        if (!(*map)[i])
        {
            fprintf(stderr, "Error: Failed to allocate memory for map row\n");
            // Free previously allocated memory
            for (int j = 0; j < i; j++)
            {
                free((*map)[j]);
            }
            free(*map);
            fclose(file);
            return 0; // Failure
        }

        for (int j = 0; j < *width; j++)
        {
            // Read the map values from the file (you need to define your file format)
            fscanf(file, "%d", &((*map)[i][j]));
        }
    }

    fclose(file);
    return 1; // Success
}

