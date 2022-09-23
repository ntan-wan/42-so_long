/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:13:13 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/23 13:43:36 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIN_WIDTH 960
# define WIN_HEIGHT 540

# include <mlx.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*path;
	int		width;
	int		height;
}	t_img;

typedef struct s_player
{
	int		width;
	int		height;
	int		frame_count;
	int		idle_frames;
	void	*current_img;
	void	*idle_img_0;
	void	*idle_img_1;
	void	*idle_img_2;
	void	*idle_img_3;
	void	*idle_img_4;
	void	*idle_img_5;
	void	*idle_img_6;
	void	*idle_img_7;
	void	*idle_img_8;
	void	*idle_img_9;
}	t_player;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_player	player;
}	t_game;

/* init */
void	init_game(t_game *data);

/* hook */
void	mlx_hooks_setup(t_game *data);

/* open_image */
void    open_imgs(t_game *game);

/* animation */
void anim_setup(t_game *game);
void	animate_player(t_player *player);

/* render */
void	render(t_game *game);
int		render_next_frame(t_game *game);

/* hooked_function */
int	handle_input(int keycode, t_game *game);

/* end_program */
int	end_program(t_game *game);
#endif