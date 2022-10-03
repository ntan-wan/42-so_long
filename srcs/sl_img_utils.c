/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_img_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:25:23 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/02 11:34:22 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_img	*sl_img_init(void *mlx, char *key, char *path)
{
	t_img	*new;

	new = (t_img *)malloc(sizeof(t_img));
	if (new)
	{
		new->key = ft_strdup(key);
		new->img = mlx_xpm_file_to_image(mlx, path, &new->width, &new->height);
		new->next = NULL;
		if (!new->img)
			sl_exit(path, EXIT_FAILURE);
	}
	else
		ft_printf("img_init: init failed\n");
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
	head = the beginning of the linked list.
 */
void	sl_img_add(t_img **head, t_img *new)
{
	t_img	*tail;

	if (new)
	{
		tail = sl_img_get_last(*head);
		if (tail)
			tail->next = new;
		else
			*head = new;
	}
	else
		ft_printf("img_add: new img not found\n");
}

t_img	*sl_img_search(char *key, t_img *imgs)
{
	t_img	*ptr_img;

	ptr_img = imgs;
	while (ptr_img)
	{
		if (ft_strncmp(key, ptr_img->key, ft_strlen(key)) == 0)
			return (ptr_img);
		ptr_img = ptr_img->next;
	}
	ft_printf("img_search: img not found\n");
	return (NULL);
}
