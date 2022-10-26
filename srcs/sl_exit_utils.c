/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_exit_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 08:23:53 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/26 11:52:21 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	sl_exit_msg(char *msg, int exit_status)
{
	ft_printf(msg);
	exit(exit_status);
	return (0);
}

int	sl_exit_free_success(t_game *game)
{
	sl_free_content(game);
	ft_printf("exit success\n");
	exit(EXIT_SUCCESS);
	return (0);
}

int	sl_exit_free_msg(t_game *game, char *msg, int exit_status)
{
	sl_free_content(game);
	ft_printf(msg);
	exit(exit_status);
	return (0);
}
