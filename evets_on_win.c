/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evets_on_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrusanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:11:38 by vrusanov          #+#    #+#             */
/*   Updated: 2018/08/31 13:15:06 by vrusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		deep_maker(t_fract *fract)
{
	if (fract->name_flag == 0 || fract->name_flag == 1)
	{
		if (fract->deep < 2147483647)
		{
			fract->deep++;
			mandelbrot_func(fract);
		}
	}
	else if (fract->name_flag == 2)
	{
		if (fract->deep * 2 < 21000000)
		{
			fract->deep *= 2;
			serpinsky_func(fract);
		}
	}
}

int			event_mouse_key(int key, int x, int y, t_fract *fract)
{
	x = 0;
	y = 0;
	if (key == 5)
		zoom_mouse(fract);
	else if (key == 4)
		zoom_mouse_out(fract);
	return (0);
}

int			key_events(int key, t_fract *fract)
{
	if (key == 53)
		x_exit(fract);
	if (key == 67)
		deep_maker(fract);
	else if (key == 69)
		key_69(fract);
	else if (key == 78)
		key_78(fract);
	return (0);
}

void		zoom_mouse_out(t_fract *fract)
{
	if (fract->name_flag == 0 || fract->name_flag == 1)
	{
		if (fract->deep > 6)
			fract->deep--;
		if (fract->zoom / 1.05 > 0.001)
			fract->zoom /= 1.05;
		mandelbrot_func(fract);
	}
	else if (fract->name_flag == 2)
	{
		zoom_mouse_for_serp(fract);
		serpinsky_func(fract);
	}
}

void		zoom_mouse(t_fract *fract)
{
	if (fract->name_flag == 0 || fract->name_flag == 1)
	{
		if (fract->deep < 10E7 && fract->zoom > 40)
			fract->deep++;
		if (fract->zoom * 1.05 < 2000000000)
			fract->zoom *= 1.05;
		mandelbrot_func(fract);
	}
	else if (fract->name_flag == 2)
	{
		if (if_serp_positiv(fract) == 1)
		{
			fract->deep += 100;
			fract->serp.frst_x -= 100;
			fract->serp.frst_y += 100;
			fract->serp.scnd_y -= 100;
			fract->serp.thrd_x += 100;
			fract->serp.thrd_y += 100;
		}
		serpinsky_func(fract);
	}
}
