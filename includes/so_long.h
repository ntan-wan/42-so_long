/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:13:13 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/26 14:05:50 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define WINDOW_W 800
# define WINDOW_H 800

# define ON_DESTROY 17
# define ON_KEY_PRESS 2
# define ON_KEY_RELEASE 3

# define IMG_GAP_X 32
# define IMG_GAP_Y 16

/* 
	STEP_SIZE = next number must be divisible by 8 & lesser than SPRITE_SIZE
 */
# define P_STEP_SIZE 4
# define E_STEP_SIZE 4
# define SPRITE_SIZE 64

/* 
	The amont of "time" each frame last.
	Smaller the value, faster the animation.
 */
# define ITEM_ANIM_SPEED 10
# define DOOR_ANIM_SPEED 10
# define PLAYER_ANIM_SPEED 10

# define CHEST_ANIM_DELAY 6

# define IDLE_RIGHT 0
# define IDLE_LEFT 1
# define MOVE_LEFT 2
# define MOVE_RIGHT 3
# define MOVE_UP 4
# define MOVE_DOWN 5

# ifdef __APPLE__
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_W 13
#  define ESC 53
#  define SPACE_BAR 49
# else
#  define KEY_A 97
#  define KEY_D 100
#  define SPACE_BAR 32
#  define KEY_S 115
#  define KEY_W 119
#  define ESC 65307
# endif

typedef struct s_img
{
	int				width;
	int				height;
	char			*key;
	void			*img;
	struct s_img	*next;
}	t_img;

/* 
	addr = address of img, array of pixels
	pixel = specific pixel
	bpp = bits_per_pixel
	size_line = amount of bytes taken by one row of our image
*/
typedef struct s_img_addr
{
	char	*addr;
	char	*pixel;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img_addr;

typedef struct s_anim
{
	t_list	*frames;
	int		frame_count;
}	t_anim;

typedef struct s_chest
{
	int				x;
	int				y;
	t_anim			*close;
	t_anim			*shine;
	t_anim			*open;
	int				interacted;
	int				collected;
}	t_chest;

typedef struct s_door
{
	int		x;
	int		y;
	t_anim	*open;
	t_anim	*opened;
	t_anim	*closed;
}	t_door;

typedef struct s_enemy
{
	int		x;
	int		y;
	int		dir;
	int		action;
	t_anim	*idle_right;
	t_anim	*idle_left;
	t_anim	*move_right;
	t_anim	*move_left;
}	t_enemy;

typedef struct s_player
{
	int		x;
	int		y;
	int		dir;
	int		action;
	int		collected;
	int		move_count;
	t_anim	*idle_right;
	t_anim	*idle_left;
	t_anim	*move_right;
	t_anim	*move_left;
}	t_player;

typedef struct s_grid
{
	char	content;
	int		visited;
}	t_grid;

typedef struct s_map
{
	t_list	*data;
	int		width;
	int		height;
	t_img	*wall;
	t_img	*floor;
	t_img	*outline;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		*imgs;
	t_player	*player;
	t_list		*enemies;
	t_list		*chests;
	t_door		*door;
	t_map		*map;
}	t_game;

/* game_uitls */
void	sl_game_init(t_game *game);
void	sl_game_init_all(t_game *g);
void	sl_game_load_imgs(t_game *game);
void	sl_game_load_anims(t_game *game);

/* img_utils */
void	sl_img_add(t_img **head, t_img *new);
t_img	*sl_img_search(char *key, t_img *imgs);
char	*sl_img_get_key(int index, t_anim *anim);
t_img	*sl_img_init(void *mlx, char *key, char *path);

/* img_utils2 */
t_img	*sl_img_new(void *mlx, int width, int height);
void	sl_img_load(void *mlx, t_img **head, char *key, char *path);

/* copy_utils */
void	sl_copy_img(t_img *dst, t_img *src, int x, int y);

/* anim_utils */
t_anim	*sl_anim_init(void);
int		sl_anim_is_last_frame(char *key, t_anim *anim);
void	sl_anim_add_frame(t_anim *anim, t_img *new);
t_img	*sl_anim_get_frame(t_anim *anim, int frame_index);
int		sl_anim_get_duration(int anim_speed, int frame_count);

/* move_utils */
int		sl_move_is_blocked(t_game *g);
void	sl_move_enemy_step(t_game *g);
void	sl_move_player_step(t_game *g);

/* interact */
void	sl_interact(t_game *game);

/* check_coord_utils */
int		sl_coord_is_overlapped(int coord, int o_coord, int reduced_range);

/* check_blocked_utils */
int		sl_is_blocked(t_player *p, int o_x, int o_y);
int		sl_is_wall(t_map *map, int x, int y);
int		sl_is_blocked_by_chest(t_player *p, t_chest *c);
int		sl_is_blocked_by_door(t_player *p, t_door *d, t_list *c);

/* check_blocked_utils2 */
int		sl_is_blocked_up(int p_y, int o_y);
int		sl_is_blocked_left(int p_x, int o_x);
int		sl_is_blocked_down(int p_y, int o_y);
int		sl_is_blocked_right(int p_x, int o_x);
int		sl_is_blocked_range(int p_coord, int o_coord, int reduced_range);

/* gui_utils */
void	sl_gui_update_movecount(t_game *g);
void	sl_gui_copy_imgs(t_img *buffer, t_game *g);

/* gui_utils2 */
t_img	*sl_gui_get_gold_num(int n, t_img *imgs);
void	sl_gui_load_num_imgs(void *mlx, t_img **imgs);
void	sl_gui_load_char_imgs(void *mlx, t_img **imgs);

/* item_utils */
t_chest	*sl_item_chest_init(int x, int y);
t_img	*sl_item_chest_get_anim(t_chest *chest);
void	sl_item_chest_check_collected(t_game *g);
void	sl_item_chest_copy_img(t_img *buffer, t_game *g);

/* item_load_utils */
void	sl_item_load_imgs_chest(void *mlx, t_img **imgs);
void	sl_item_load_anim_chests(t_list *chests, t_img *imgs);

/* door */
void	sl_door_init(t_door **door);
void	sl_door_set_coord(t_door *door, int x, int y);
void	sl_door_copy_img(t_img *buffer, t_game *g);

/* door_load*/
void	sl_door_check_exit(t_game *g);
void	sl_door_load_imgs(void *mlx, t_img **imgs);
void	sl_door_load_anims(t_door *door, t_img *imgs);

/* enemy_utils */
t_enemy	*sl_enemy_init(int x, int y);
void	sl_enemies_check_player(t_game *g);
void	sl_enemy_copy_img(t_img *buffer, t_game *g);

/* enemy_load_utils */
void	sl_enemy_load_img_idle(void *mlx, t_img **imgs);
void	sl_enemy_load_imgs_move(void *mlx, t_img **imgs);
void	sl_enemies_load_anim(t_list *enemies, t_img *imgs);

/* player_utils */
void	sl_player_init(t_player **player);
void	sl_player_check_collected(t_game *g);
t_img	*sl_player_get_anim(t_player *player);
void	sl_player_set_coord(t_player *player, int x, int y);
void	sl_player_copy_img(t_img *buffer, t_player *player);

/* player_load_utils */
void	sl_player_load_imgs_idle(void *mlx, t_img **imgs);
void	sl_player_load_imgs_move(void *mlx, t_img **imgs);
void	sl_player_load_anim_idle(t_player *player, t_img *imgs);
void	sl_player_load_anim_move(t_player *player, t_img *imgs);

/* map_utils */
void	sl_map_init(t_map **map);
void	sl_map_setup(t_game *g, char *path);

/* map_utils2 */
void	sl_map_copy_img(t_img *buffer, t_game *g);
void	sl_map_parse_image(t_game *g, char c, int x, int y);
void	sl_map_load_imgs(void *mlx, t_img **imgs, t_map *map);
void	sl_map_parse_character(t_game *g, char c, int x, int y);
void	sl_map_parse_data(t_game *g, void (*f)(t_game *, char, int, int));

/* map_utils3 */
int		sl_map_is_rect(t_map *map);
int		sl_map_is_dup_char(t_map *map);
int		sl_map_is_surrounded(t_map *map);
void	sl_map_check_missing_char(t_game *g);

/* free_utils */
void	sl_free_map(void *mlx, t_map **map);
void	sl_free_door(t_door **door);
void	sl_free_player(t_player **player);
void	sl_free_item_chest(t_chest **chest);

/* free_utils2 */
void	sl_free_anim(t_anim **anim);
void	sl_free_content(t_game *game);
void	sl_free_imgs(void *mlx, t_img **head);

/* exit_utils */
int		sl_exit_free_success(t_game *game);
int		sl_exit_msg(char *msg, int exit_status);
int		sl_exit_free_msg(t_game *game, char *msg, int exit_status);

typedef struct s_map_data
{
	int		x;
	int		y;
	char	content;
}	t_map_data;

t_grid	**sl_map_data_to_grid(t_map *map);
void	sl_print_grid(t_grid **grid, int map_width, int map_height);
void	sl_free_map_data_grid(t_grid **grid);
void	sl_check_exit_path(t_map *map, t_player *p, t_door *d);
#endif