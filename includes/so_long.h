/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:13:13 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/28 17:54:22 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <X11/X.h>

# define SCREEN_W 960
# define SCREEN_H 540

# define ON_DESTROY 17


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
	frame_count = to indicate the position of the img
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
	t_img	*idle;
	t_img	*move_right;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_player	*player;
}	t_game;

/* img_utils */
void	sl_img_add(t_img **head, t_img *new);
t_img	*sl_img_init(void *mlx, char *key, char *path);

/* load_utils */
void	sl_load_img(void *mlx, t_img **head, char *key, char *path);
void	sl_load_imgs_player(void *mlx, t_player *player);

/* copy_utils */
void	sl_copy_img(t_img *dst, t_img *src, int x, int y);

/* player_utils */
void	sl_player_init(void *mllx_ptr, t_player *player);

/* free_utils */
void	sl_free_content(t_game *game);

/* exit_utils */
void    sl_exit(char *msg, int exit_status);

/* debug_utils */
int		sl_debug_loop(void);
int		sl_debug_keycode_keypress(int keycode);

#endif