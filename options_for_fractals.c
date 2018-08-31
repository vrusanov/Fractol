/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_for_fractals.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrusanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:45:13 by vrusanov          #+#    #+#             */
/*   Updated: 2018/08/31 13:45:53 by vrusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		option_mandelbrot(t_fract *fract)
{
	fract->deep = 55;
	fract->mv_x = 0;
	fract->mv_y = 0;
	fract->color = 1;
	fract->zoom = 200;
}

void		option_julia(t_fract *fract)
{
	fract->deep = 200;
	fract->zoom = 300;
	fract->mv_x = 0;
	fract->mv_y = 0;
	fract->color = 1;
	fract->tmp_cre = -0.8169;
	fract->tmp_cim = -0.1189;
}

void		option_serpinsky(t_fract *fract)
{
	fract->deep = 600000;
	fract->serp.scnd_x = 500;
	fract->serp.scnd_y = 0;
	fract->serp.frst_x = 0;
	fract->serp.frst_y = 1000;
	fract->serp.thrd_x = 1000;
	fract->serp.thrd_y = 1000;
}
