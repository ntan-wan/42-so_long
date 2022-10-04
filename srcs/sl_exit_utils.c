/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_exit_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 08:23:53 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/04 11:24:59 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	sl_exit(t_game *game, char *msg, int exit_status)
{
	if (exit_status)
		perror(msg);
	else
		ft_putstr_fd(msg, 1);
	sl_free_content(game);
	exit(exit_status);
	return (0);
}
