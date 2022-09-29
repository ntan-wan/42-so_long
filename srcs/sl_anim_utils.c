/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_anim_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:23:35 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/29 10:25:53 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_anim	*sl_anim_init(void)
{
	t_anim	*new;

	new = (t_anim *)malloc(sizeof(t_anim));
	if (new)
	{
		new->frames = NULL;
		new->frame_count = 0;
	}
	else
		ft_putstr_fd("anim_init: init failed\n", 1);
	return (new);
}

void	sl_anim_add_frame(t_anim *anim, t_img *new)
{
	if (anim && new)
	{
		ft_lstadd_back(&anim->frames, ft_lstnew(new->img));
		anim->frame_count = ft_lstsize(anim->frames);
	}
	else
		ft_putstr_fd("add_frame: anim or new frame not found\n", 1);
}

void	sl_anim_del_all_frames(t_anim *anim)
{
	if (anim)
	{
		ft_lstclear(&anim->frames, free);
		anim->frame_count = 0;
	}
	else
		ft_putstr_fd("del_all_frames: frames not found\n", 1);
}
