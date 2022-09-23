#include "../includes/so_long.h"
#define P_FRAME_INTERVAL 200

void anim_setup(t_game *game)
{
	game->player.frame_count = -1;
	game->player.idle_frames = 10;
}

void	animate_player(t_player *player)
{
	player->frame_count += 1;	
	if (player->frame_count == 0)
		player->current_img = player->idle_img_0;
	else if (player->frame_count == P_FRAME_INTERVAL)
		player->current_img = player->idle_img_1;
	else if (player->frame_count == P_FRAME_INTERVAL * 2)
		player->current_img = player->idle_img_2;
	else if (player->frame_count == P_FRAME_INTERVAL * 3)
		player->current_img = player->idle_img_3;
	else if (player->frame_count == P_FRAME_INTERVAL * 4)
		player->current_img = player->idle_img_4;
	else if (player->frame_count == P_FRAME_INTERVAL * 5)
		player->current_img = player->idle_img_5;
	else if (player->frame_count == P_FRAME_INTERVAL * 6)
		player->current_img = player->idle_img_6;
	else if (player->frame_count == P_FRAME_INTERVAL * 7)
		player->current_img = player->idle_img_7;
	else if (player->frame_count == P_FRAME_INTERVAL * 8)
		player->current_img = player->idle_img_8;
	else if (player->frame_count == P_FRAME_INTERVAL * 9)
		player->current_img = player->idle_img_9;
	else if (player->frame_count == P_FRAME_INTERVAL * 10)
		player->frame_count = -1;
}
