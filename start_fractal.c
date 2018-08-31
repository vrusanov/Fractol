/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrusanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:46:25 by vrusanov          #+#    #+#             */
/*   Updated: 2018/08/31 16:41:03 by vrusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		choice_fractal(t_fract *fract)
{
	if (fract->name_flag == 0)
	{
		option_mandelbrot(fract);
		mandelbrot_func(fract);
	}
	else if (fract->name_flag == 1)
	{
		option_julia(fract);
		mandelbrot_func(fract);
	}
	else if (fract->name_flag == 2)
	{
		option_serpinsky(fract);
		serpinsky_func(fract);
	}
}
