#include <stdio.h>
#include <stdlib.h>
/**
 * alloc_grid - nested loop to make grid
 * @width: width input
 * @height: height input
 * Return: pointer to 2 dim. array
 */
int **alloc_grid(int width, int height)
{
	int **matrix;
	int *elements;
	int i;

	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}
	matrix = (int **)malloc(height * sizeof(int *));
	if (matrix == NULL)
	{
		return (NULL);
	}
	elements = (int *)malloc(width * height * sizeof(int));
	if (elements == NULL)
	{
		free(matrix);
		return (NULL);
	}
	for (i = 0; i < height; i++)
	{
		matrix[i] = elements + (i * width);
	}
	return (matrix);
}
