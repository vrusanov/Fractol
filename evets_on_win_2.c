/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evets_on_win_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrusanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:15:42 by vrusanov          #+#    #+#             */
/*   Updated: 2018/08/31 16:39:59 by vrusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		hlp_zoom_mouse_serp(t_fract *fract)
{
	fract->serp.frst_y -= 1;
	fract->serp.scnd_y += 1;
	fract->serp.thrd_x -= 1;
	fract->serp.thrd_y -= 1;
	fract->deep -= 1;
	fract->serp.frst_x += 1;
}

void		zoom_mouse_for_serp(t_fract *fract)
{
	if (if_serp_negative(fract) == 1)
	{
		fract->serp.frst_y -= 100;
		fract->serp.scnd_y += 100;
		fract->serp.thrd_x -= 100;
		fract->serp.thrd_y -= 100;
		fract->deep -= 100;
		fract->serp.frst_x += 100;
	}
	else if (fract->serp.frst_x + 20 <= fract->serp.thrd_x)
	{
		fract->serp.frst_y -= 10;
		fract->serp.scnd_y += 10;
		fract->serp.thrd_x -= 10;
		fract->serp.thrd_y -= 10;
		fract->deep -= 10;
		fract->serp.frst_x += 10;
	}
	if (fract->serp.frst_x + 2 <= fract->serp.thrd_x)
		hlp_zoom_mouse_serp(fract);
}

void		key_69(t_fract *fract)
{
	if (fract->name_flag == 0)
	{
		if (fract->deep < 2147483647)
			fract->deep++;
		mandelbrot_func(fract);
	}
	else if (fract->name_flag == 1)
	{
		if (fract->deep < 2147483647)
			fract->deep++;
		mandelbrot_func(fract);
	}
	else if (fract->name_flag == 2)
	{
		fract->deep *= 1.5;
		serpinsky_func(fract);
	}
}

void		key_78(t_fract *fract)
{
	if (fract->name_flag == 0)
	{
		if (fract->deep - 10 > 0)
			fract->deep--;
		mandelbrot_func(fract);
	}
	else if (fract->name_flag == 1)
	{
		if (fract->deep - 10 > 0)
			fract->deep--;
		mandelbrot_func(fract);
	}
	else if (fract->name_flag == 2)
	{
		if (fract->deep / 1.5 > 10)
			fract->deep /= 1.5;
		serpinsky_func(fract);
	}
}
