#include "../includes/so_long.h"

int end_program(t_game *game)
{
	//mlx_destroy_image();
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
    exit(EXIT_SUCCESS);
}