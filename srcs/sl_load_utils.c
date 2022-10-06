/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:54:09 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/06 08:57:43 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* init + add imgs */
void	sl_load_img(void *mlx, t_img **head, char *key, char *path)
{
	sl_img_add(head, sl_img_init(mlx, key, path));
}
