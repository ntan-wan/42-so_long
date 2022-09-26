/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_img_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:33:28 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/26 14:27:05 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//remember to free
t_img	*sl_img_init(void *mlx_ptr, char *path)
{
	t_img	*new;

	new = (t_img *)malloc(sizeof(t_img));
	new->img = mlx_xpm_file_to_image(mlx_ptr, path, &new->x, &new->y);
	return (new);
}
