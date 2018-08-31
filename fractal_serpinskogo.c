/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_serpinskogo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrusanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:40:33 by vrusanov          #+#    #+#             */
/*   Updated: 2018/08/31 13:41:48 by vrusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		if_serp_positiv(t_fract *fract)
{
	if (fract->serp.thrd_x + 1000 > 10E8)
		return (0);
	return (1);
}

int		if_serp_negative(t_fract *fract)
{
	if (fract->serp.thrd_x - fract->serp.frst_x < 250)
		return (0);
	return (1);
}

void	find_dots_serpinskogo(t_fract *fract, int iter, int tmp)
{
	fract->serp.x = (fract->serp.frst_x + fract->serp.scnd_x) / 2;
	fract->serp.y = (fract->serp.frst_y + fract->serp.scnd_y) / 2;
	while (iter++ < fract->deep)
	{
		tmp = random_for_serp(10, 1);
		if (tmp > 0 && tmp < 4)
		{
			fract->serp.x = (fract->serp.x + fract->serp.frst_x) / 2;
			fract->serp.y = (fract->serp.y + fract->serp.frst_y) / 2;
			put_color_pixel_serp(fract, fract->serp.x, fract->serp.y, 250);
		}
		else if (tmp > 3 && tmp < 7)
		{
			fract->serp.x = (fract->serp.x + fract->serp.scnd_x) / 2;
			fract->serp.y = (fract->serp.y + fract->serp.scnd_y) / 2;
			put_color_pixel_serp(fract, fract->serp.x, fract->serp.y, 250);
		}
		else if (tmp > 6 && tmp < 10)
		{
			fract->serp.x = (fract->serp.x + fract->serp.thrd_x) / 2;
			fract->serp.y = (fract->serp.y + fract->serp.thrd_y) / 2;
			put_color_pixel_serp(fract, fract->serp.x, fract->serp.y, 250);
		}
	}
}

void	serpinsky_func(t_fract *fract)
{
	ft_bzero(fract->addr, WIDTH * HEIGHT * 4);
	find_dots_serpinskogo(fract, 0, 0);
	mlx_put_image_to_window(fract->mlx_ptr, fract->win, fract->image, 0, 0);
}
