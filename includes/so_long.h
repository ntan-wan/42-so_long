/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:13:13 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/27 18:32:41 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SCREEN_W 960
# define SCREEN_H 540

# define ON_DESTROY 17

# include <mlx.h>
# include <stdlib.h>
# include <X11/X.h>

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
	bpp = bits_per_pixel
	size_line = amount of bytes taken by one row of our image
 */
typedef struct s_img
{
	int				x;
	int				y;
	char			*key;
	void			*img;
	struct s_img	*next;
}	t_img;

typedef struct s_img_addr
{
	char	*addr;
	char	*pixel;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img_addr;

typedef struct s_player
{
	t_img	*idle;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_player	*player;
}	t_game;

/* libft */
char	*ft_strdup(const char *str);

/* player_utils */
void	sl_player_init(void *mllx_ptr, t_player *player);
void	sl_player_load_imgs(void *mlx, t_player *player);

/* copy_utils */
void	sl_copy_img(t_img *dst, t_img *src);

/* img_utils */
void	sl_img_load(void *mlx, t_img **head, char *key, char *path);

/* free_utils */
void	sl_free_content(t_game *game);

/* debug_utils */
int		sl_debug_loop(void);
int		sl_debug_keycode_keypress(int keycode);

#endif