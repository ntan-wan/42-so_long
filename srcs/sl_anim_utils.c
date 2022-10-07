/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_anim_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:23:35 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/07 10:38:12 by ntan-wan         ###   ########.fr       */
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
		ft_printf("anim_init: init failed\n");
	return (new);
}

t_img	*sl_anim_get_frame(t_anim *anim, int frame_index)
{
	int		i;
	t_list	*ptr_frame;

	i = -1;
	ptr_frame = anim->frames;
	while (ptr_frame && frame_index < anim->frame_count && ++i < frame_index)
		ptr_frame = ptr_frame->next;
	return ((t_img *)ptr_frame->content);
}

void	sl_anim_add_frame(t_anim *anim, t_img *new)
{
	if (anim && new)
	{
		ft_lstadd_back(&anim->frames, ft_lstnew(new));
		anim->frame_count = ft_lstsize(anim->frames);
	}
	else
		ft_printf("add_frame: anim or new frame not found\n");
}

int	sl_anim_get_duration(int anim_speed, int frame_count)
{
	return (anim_speed * frame_count);
}

int	sl_anim_is_last_frame(char *key, t_anim *anim)
{
	int		compared_key_len;
	t_list	*last_frame;
	char	*compared_key;

	last_frame = ft_lstlast(anim->frames);
	compared_key = ((t_img *)last_frame->content)->key;
	compared_key_len = ft_strlen(compared_key);
	return (ft_strncmp(key, compared_key, compared_key_len) == 0);
}
