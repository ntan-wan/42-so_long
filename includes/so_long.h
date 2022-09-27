/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:13:13 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/27 11:01:12 by ntan-wan         ###   ########.fr       */
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

typedef struct s_img
{
	char			*key;
	void			*img;
	int				x;
	int				y;
	char			*addr;
	int				bits_per_pixel;
	int				line_len;
	int				endian;
	struct s_img	*next;
}	t_img;

typedef struct s_imgs
{
	char			*key;
	t_img			*frame;
	struct s_imgs	*next;
}	t_imgs;

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

/* img_utils */
void	sl_img_add(t_img **head, t_img *new);
t_img	*sl_img_init(void *mlx, char *key, char *path);
void	sl_img_load(void *mlx, t_img **head, char *key, char *path);

/* free_utils */
void	sl_free_content(t_game *game);

/* debug_utils */
int		sl_debug_loop(void);
int		sl_debug_keycode_keypress(int keycode);

#endif