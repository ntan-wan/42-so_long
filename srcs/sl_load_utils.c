/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:54:09 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/04 10:54:12 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* init + add imgs */
void	sl_load_img(void *mlx, t_img **head, char *key, char *path)
{
	sl_img_add(head, sl_img_init(mlx, key, path));
}

void	sl_load_anim_chest(t_img *imgs, t_chest *chest)
{
	t_chest	*ptr_chest;

	ptr_chest = chest;
	while (ptr_chest)
	{
		sl_item_load_anim_chest_open(ptr_chest, imgs);
		sl_item_load_anim_chest_close(ptr_chest, imgs);
		ptr_chest = ptr_chest->next;
	}
}
