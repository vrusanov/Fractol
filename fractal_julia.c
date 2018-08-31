/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrusanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:36:28 by vrusanov          #+#    #+#             */
/*   Updated: 2018/08/31 13:37:54 by vrusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		event_mouse_key_julia(int x, int y, t_fract *fract)
{
	if (x > 0 && x < 1000 && y > 0 && y < 1000 && fract->name_flag == 1)
	{
		fract->tmp_cre = -0.8169 + (double)x / 1000;
		fract->tmp_cim = -0.1189 + (double)y / 1000;
		mandelbrot_func(fract);
	}
	return (0);
}
