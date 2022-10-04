/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:13:13 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/04 19:52:42 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

# define STEP_SIZE 4
# define SPRITE_SIZE 64

/* 
	my laptop's full screen = 1920 x 1080 
 */
# define WINDOW_W 800
# define WINDOW_H 800

/*
	events
*/
# define ON_DESTROY 17
# define ON_KEY_PRESS 2
# define ON_KEY_RELEASE 3

/* 
	The amont of "time" each frame last.
	Smaller the value, faster the animation.
 */
# define INTERVAL 10

/* 
	player's action;
 */
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
# else
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_E 101
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
	t_anim			*open;
	int				interacted;
	struct s_chest	*next;
}	t_chest;

typedef struct s_player
{
	int		x;
	int		y;
	int		dir;
	int		action;
	t_anim	*idle_right;
	t_anim	*idle_left;
	t_anim	*move_right;
	t_anim	*move_left;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		*imgs;
	t_player	*player;
	t_chest		*chest;
}	t_game;

/* game_uitls */
void	sl_game_init(t_game *game);
void	sl_game_load_imgs(t_game *game);
void	sl_game_load_anims(t_game *game);
void	sl_game_buffer_init(void *mlx, t_img *buffer);

/* img_utils */
void	sl_img_add(t_img **head, t_img *new);
t_img	*sl_img_search(char *key, t_img *imgs);
t_img	*sl_img_init(void *mlx, char *key, char *path);

/* load_utils */
void	sl_load_anim_chest(t_img *imgs, t_chest *chest);
void	sl_load_img(void *mlx, t_img **head, char *key, char *path);

/* copy_utils */
void	sl_copy_img(t_img *dst, t_img *src, int x, int y);

/* anim_utils */
t_anim	*sl_anim_init(void);
void	sl_anim_add_frame(t_anim *anim, t_img *new);
t_img	*sl_anim_get_frame(t_anim *anim, int frame_index);

/* item_utils */
t_chest	*sl_item_chest_new(int x, int y);
t_img	*sl_item_chest_get_anim(t_chest *chest);
void	sl_item_chest_add(t_chest **head, t_chest *new);
void	sl_item_chest_copy_all(t_img *buffer, t_chest *chest, int p_x, int p_y);

/* item_load_utils */
void	sl_item_load_imgs_chest_close(void *mlx, t_img **imgs);
void	sl_item_load_imgs_chest_open(void *mlx, t_img **imgs);
void	sl_item_load_anim_chest_close(t_chest *chest, t_img *imgs);
void	sl_item_load_anim_chest_open(t_chest *chest, t_img *imgs);

/* move_utils */
void	sl_move_player_step(t_player *player);

/* interact */
void	sl_interact(t_game *game);

/* player_utils */
void	sl_player_init(t_player **player);
t_img	*sl_player_get_anim(t_player *player);
void	sl_player_set_dir(t_player *player);
void	sl_player_copy_img(t_img *buffer, t_player *player, int x, int y);

/* player_load_utils */
void	sl_player_load_imgs_idle(void *mlx, t_img **imgs);
void	sl_player_load_imgs_move(void *mlx, t_img **imgs);
void	sl_player_set_coord(t_player *player, int x, int y);
void	sl_player_load_anim_idle(t_player *player, t_img *imgs);
void	sl_player_load_anim_move(t_player *player, t_img *imgs);

/* free_utils */
void	sl_free_content(t_game *game);

/* exit_utils */
int		sl_exit(t_game *game, char *msg, int exit_status);

/* debug_utils */
int		sl_debug_loop(void);
int		sl_debug_keycode_keypress(int keycode);


int		sl_check_in_range(int p_x, int p_y, int x, int y);
int 	sl_math_is_in_range(int center_point, int coord);
int 	sl_math_get_center(int point);
int		sl_move_is_blocked(t_game *game);
void	sl_move(t_game *game);
#endif