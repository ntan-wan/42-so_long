/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:13:13 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/30 13:53:00 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

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
	eventmasks
 */
# define KEY_PRESS_MASK 1L<<0
# define KEY_RELEASE_MASK 1L<<1

/* 
	The amont of "time" each frame last.
	Smaller the value, faster the animation.
 */
# define INTERVAL 10

/* 
	player's movement;
 */
# define IDLE 0
# define LEFT 1
# define RIGHT 2

# ifdef __APPLE__
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_W 13
#  define ESC 53
# else
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_W 119
#  define ESC 65307
# endif

/* 
	x = width
	y = height
	key = custom name given to img, for searching img purpose.
 */
typedef struct s_img
{
	int				x;
	int				y;
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

typedef struct s_player
{
	int		movement;
	t_anim	*idle;
	t_anim	*move_right;
	t_anim	*attack_right;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		*imgs;
	t_player	*player;
}	t_game;

/* img_utils */
void	sl_img_add(t_img **head, t_img *new);
t_img	*sl_img_search(char *key, t_img *imgs);
t_img	*sl_img_init(void *mlx, char *key, char *path);

/* load_utils */
void	sl_load_img(void *mlx, t_img **head, char *key, char *path);
void	sl_load_imgs_player(void *mlx, t_img **imgs);

/* copy_utils */
void	sl_copy_img(t_img *dst, t_img *src, int x, int y);
void	sl_copy_player_img(t_img *buffer, t_player *player);

/* anim_utils */
t_anim	*sl_anim_init(void);
void	sl_anim_add_frame(t_anim *anim, t_img *new);
t_img	*sl_anim_get_frame(t_anim *anim, int frame_index);

/* player_utils */
t_img	*sl_player_get_anim(t_player *player);
void	sl_player_init(void *mlx, t_player **player, t_img **imgs);

/* free_utils */
void	sl_free_content(t_game *game);

/* exit_utils */
void	sl_exit(char *msg, int exit_status);

/* debug_utils */
int		sl_debug_loop(void);
int		sl_debug_keycode_keypress(int keycode);

#endif