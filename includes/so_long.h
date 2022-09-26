/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:13:13 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/26 14:25:44 by ntan-wan         ###   ########.fr       */
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
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define ESC 53
# else
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_W 119
# define ESC 65307
# endif

typedef struct s_img_addr
{
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
} t_img_addr;

typedef struct s_img
{
	void	*img;
	int		x;
	int		y;
}	t_img;

typedef struct s_imgs
{
	char			*key;
	t_img			*img;
	struct s_imgs	*next;
}	t_imgs;

typedef struct s_player
{
	t_imgs	*idle;
}	t_player;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_player	*player;
}	t_game;

/* libft */
char	*ft_strdup(const char *str);

/* content_utils*/
void    sl_content_free(t_game *game);

/* img_utils */
t_img	*sl_img_init(void *mlx_ptr, char *path);

/* imgs_utils */
void	sl_imgs_add(t_imgs *head, t_imgs *new);
t_imgs	*sl_imgs_init(void *mlx_ptr, char *key, char *path);

/* load_imgs_utils */
void	sl_load_player_imgs(void *mlx_ptr, t_player *player);
void	sl_load_imgs(void *mlx_ptr, t_imgs *head, char *key, char *path);

/* debug_utils */
int sl_debug_loop(void);
int sl_debug_keycode_keypress(int keycode);

#endif