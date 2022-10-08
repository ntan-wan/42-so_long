/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_exit_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 08:23:53 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/08 16:30:32 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	sl_exit(char *msg, int exit_status, int fd)
{
	ft_putstr_fd(msg, fd);
	exit(exit_status);
	return (0);
}

int	sl_exit_free(t_game *game, char *msg, int exit_status)
{
	sl_free_content(game);
	if (exit_status)
		perror(msg);
	else
		ft_putstr_fd(msg, 1);
	exit(exit_status);
	ft_printf("exit failed\n");
	return (0);
}
