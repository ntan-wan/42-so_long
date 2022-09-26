#include "../includes/so_long.h"

void    sl_content_free(t_game *game)
{
    mlx_destroy_display(game->mlx_ptr);
}