/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_imgs_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:25:23 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/26 16:51:06 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_imgs	*sl_imgs_init(void *mlx_ptr, char *key, char *path)
{
	t_imgs	*new;

	new = (t_imgs *)malloc(sizeof(t_imgs));
	new->key = ft_strdup(key);
	new->frame = sl_img_init(mlx_ptr, path);
	new->next = NULL;
	return (new);
}

static t_imgs	*sl_imgs_get_last(t_imgs *head)
{
	t_imgs	*ptr_tail;

	ptr_tail = head;
	if (!ptr_tail)
		return (NULL);
	while (ptr_tail->next)
		ptr_tail = ptr_tail->next;
	return (ptr_tail);
}

void	sl_imgs_add(t_imgs **head, t_imgs *new)
{
	t_imgs	*tail;

	tail = sl_imgs_get_last(*head);
	if (tail)
		tail->next = new;
	else
		*head = new;
}

/* init and add imgs */
void	sl_imgs_load(void *mlx_ptr, t_imgs **head, char *key, char *path)
{
	sl_imgs_add(head, sl_imgs_init(mlx_ptr, key, path));
}
