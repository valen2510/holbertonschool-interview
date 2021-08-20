#include "sandpiles.h"

/**
 * print_grid2 - prints the grid
 * @grid: grid to print
 */
void print_grid2(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - Check if the grid is stable,
 * @grid: 3x3 grid
 * Return: 1 if is stable, otherwise return 0
 *
 */
int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);
	return (1);
}

/**
 * sum_grid - sum two sandpiles
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 *
 */
void sum_grid(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
}

/**
 * topple - Distribute grains of sand of each cell
 * @grid1: grid
 */
void topple(int grid[3][3])
{
	int x, y;
	int tmp_grid[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{

			if (grid[x][y] >= 4)
			{
				tmp_grid[x][y] -= 4;
				/* down */
				if ((x + 1) < 3)
					tmp_grid[x + 1][y]++;
				/* up */
				if ((x - 1) >= 0)
					tmp_grid[x - 1][y]++;
				/* Right */
				if ((y + 1) < 3)
					tmp_grid[x][y + 1]++;
				/* left */
				if ((y - 1) >= 0)
					tmp_grid[x][y - 1]++;
			}
		}
	}

	sum_grid(grid, tmp_grid);
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: grid
 * @grid2: grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum_grid(grid1, grid2);
	while (!is_stable(grid1))
	{
		printf("=\n");
		print_grid2(grid1);
		topple(grid1);
	}
}