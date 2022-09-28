/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_anim_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:23:35 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/28 18:14:17 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_anim	*sl_anim_init(void)
{
	t_anim	*new;

	new = (t_anim *)malloc(sizeof(t_anim));
	new->frames = NULL;
	new->frame_count = 0;
	return (new);
}

void	sl_anim_frame_add(t_anim *anim, void *img)
{
	ft_lstadd_back(&anim->frames, ft_lstnew(img));
	anim->frame_count = ft_lstsize(anim->frames);
}

void	sl_anim_frames_del_all(t_anim *anim)
{
	ft_lstclear(&anim->frames, free());
	anim->frame_count = 0;
}
