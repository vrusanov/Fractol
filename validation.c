/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrusanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:47:43 by vrusanov          #+#    #+#             */
/*   Updated: 2018/08/31 19:50:49 by vrusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		validation_fractal_name(char *fract_name, t_fract *fract)
{
	if (ft_strcmp("mandelbrot", fract_name) == 0
			|| ft_strcmp("M", fract_name) == 0)
		fract->name_flag = 0;
	else if (ft_strcmp("julia", fract_name) == 0
			|| ft_strcmp("J", fract_name) == 0)
		fract->name_flag = 1;
	else if (ft_strcmp("serpinsky", fract_name) == 0
			|| ft_strcmp("S", fract_name) == 0)
		fract->name_flag = 2;
	else
	{
		ft_error_fractal(2);
		exit(1);
	}
	option_argv();
}

void		ft_error_fractal(int i)
{
	if (i == 2)
		ft_putendl("\n    Wroooong!");
	option_argv();
}
