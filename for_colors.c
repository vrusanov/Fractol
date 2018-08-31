/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrusanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:31:59 by vrusanov          #+#    #+#             */
/*   Updated: 2018/08/31 13:35:20 by vrusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		put_color_pixel_mndlbrt(t_fract *fract,
		int count_pxl, double color, int flag)
{
	if (flag == 1)
	{
		fract->addr[count_pxl] = 0;
		fract->addr[count_pxl + 1] = 0;
		fract->addr[count_pxl + 2] = 0;
	}
	else
	{
		fract->addr[count_pxl] = color + 425 % 32;
		fract->addr[count_pxl + 1] = color - 133 / 3;
		fract->addr[count_pxl + 2] = color * 66;
	}
}

void		fract_help_for_put(t_fract *fract, int x, int y)
{
	int		count_pxl;

	if (fract->iter == fract->deep)
	{
		count_pxl = calculs_pixel(x + WIDTH / 2, (y + HEIGHT / 2) - 1);
		put_color_pixel_mndlbrt(fract, count_pxl, 0, 1);
	}
	else
	{
		count_pxl = calculs_pixel(x + WIDTH / 2, (y + HEIGHT / 2) - 1);
		put_color_pixel_mndlbrt(fract, count_pxl,
				((fract->iter * fract->deep) % 128), 0);
	}
}

void		put_color_pixel_serp(t_fract *fract, int x, int y, int color)
{
	int		i;

	if (x < WIDTH && y < HEIGHT && x > 0 && y > 0)
	{
		i = calculs_pixel(x, y - 1);
		fract->addr[i] = 29;
		fract->addr[i + 1] = color * 45;
		fract->addr[i + 2] = 29;
	}
}
