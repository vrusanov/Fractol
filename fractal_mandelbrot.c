/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrusanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:38:04 by vrusanov          #+#    #+#             */
/*   Updated: 2018/08/31 13:39:59 by vrusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		mandelbrot_func(t_fract *fract)
{
	ft_bzero(fract->addr, WIDTH * HEIGHT * 4);
	calculs_dots(fract, WIDTH / 2 * -1, HEIGHT / 2 * -1, 0);
	mlx_put_image_to_window(fract->mlx_ptr, fract->win, fract->image, 0, 0);
}

void		if_mandelbrot(t_fract *fract, int *flag)
{
	fract->iter = -1;
	while (++fract->iter < fract->deep)
	{
		fract->tmp_re_2 = fract->tmp_re * fract->tmp_re;
		fract->tmp_im_2 = fract->tmp_im * fract->tmp_im;
		if (fract->tmp_re_2 + fract->tmp_im_2 > 1.0E5)
		{
			*flag = 0;
			break ;
		}
		fract->tmp_im = 2 * fract->tmp_re * fract->tmp_im + fract->tmp_cim;
		fract->tmp_re = fract->tmp_re_2 - fract->tmp_im_2 + fract->tmp_cre;
	}
}

int			calculs_pixel(int x, int y)
{
	int		count_pix;

	count_pix = 0;
	count_pix = (x * 4) + ((WIDTH * 4) * y);
	return (count_pix);
}

void		calculs_dots(t_fract *fract, int x, int y, int flag)
{
	t_mndlbrt sv;

	while (++y < HEIGHT / 2)
	{
		sv.cim = (double)y / fract->zoom;
		if (fract->name_flag == 0)
			fract->tmp_cim = sv.cim;
		x = (WIDTH / 2) * -1;
		while (++x < WIDTH / 2)
		{
			if (fract->name_flag == 0)
			{
				sv.cre = (double)x / fract->zoom - 0.5;
				fract->tmp_cre = sv.cre;
			}
			else
				sv.cre = (double)x / fract->zoom;
			fract->tmp_re = sv.cre;
			fract->tmp_im = sv.cim;
			if_mandelbrot(fract, &flag);
			fract_help_for_put(fract, x, y);
		}
	}
}
