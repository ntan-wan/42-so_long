/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooked_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:56:46 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/23 13:36:27 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_input(int keycode, t_game *game)
{
	if (keycode == XK_Escape)	
		end_program(game);
	return (0);
}
