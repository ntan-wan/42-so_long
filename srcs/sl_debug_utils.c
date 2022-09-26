/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_debug_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:52:22 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/26 16:53:14 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_printf(const char *str, ...);

/* print keypress keycode */
int	sl_debug_keycode_keypress(int keycode)
{
	ft_printf("keycode -> %d\n", keycode);
	return (0);
}

/* handle no event */
int	sl_debug_loop(void)
{
	return (0);
}
