/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_img_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:25:23 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/27 18:45:55 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_img	*sl_img_init(void *mlx, char *key, char *path)
{
	t_img	*new;

	new = (t_img *)malloc(sizeof(t_img));
	new->key = ft_strdup(key);
	new->img = mlx_xpm_file_to_image(mlx, path, &new->x, &new->y);
	new->next = NULL;
	return (new);
}

static t_img	*sl_img_get_last(t_img *head)
{
	t_img	*ptr_tail;

	ptr_tail = head;
	if (!ptr_tail)
		return (NULL);
	while (ptr_tail->next)
		ptr_tail = ptr_tail->next;
	return (ptr_tail);
}

/* 
	head = the start of the link list.
 */
static void	sl_img_add(t_img **head, t_img *new)
{
	t_img	*tail;

	tail = sl_img_get_last(*head);
	if (tail)
		tail->next = new;
	else
		*head = new;
}

/* init + add imgs */
void	sl_img_load(void *mlx, t_img **head, char *key, char *path)
{
	sl_img_add(head, sl_img_init(mlx, key, path));
}
