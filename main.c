/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrusanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:42:35 by vrusanov          #+#    #+#             */
/*   Updated: 2018/08/31 13:45:00 by vrusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int			x_exit(t_fract *fract)
{
	mlx_destroy_window(fract->mlx, fract->win);
	fract = NULL;
	exit(0);
	return (0);
}

void		option_argv(void)
{
	ft_putstr("\n  usage: ./fractol fractol_name\n");
	ft_putstr("__________________________________\n");
	ft_putstr("  M - mandelbrot\n");
	ft_putstr("  J - julia\n");
	ft_putstr("  S - serpinski\n");
}

double		random_for_serp(int n, int iter)
{
	int		dot;

	if (n < 11)
	{
		dot = random() % 10;
		if (dot < n && dot > 0)
			return (dot);
	}
	else if (n > 10)
	{
		dot = random() % 100;
		if (dot < n && dot > 0)
			return (dot);
	}
	random_for_serp(n, iter);
	return (2);
}

int			main(int ac, char *av[])
{
	t_fract	fract[1];

	if (ac < 2)
		option_argv();
	else if (ac > 2)
		ft_putstr("\n too many arguments\n");
	else if (ac == 2)
	{
		validation_fractal_name(av[1], fract);
		fract->mlx = mlx_init();
		fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGHT,
				"fractol by vrusanov");
		fract->image = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
		fract->addr = mlx_get_data_addr(fract->image, &fract->bits_per_pixel,
				&fract->size_line, &fract->endian);
		choice_fractal(fract);
		mlx_hook(fract->win, 2, 5, key_events, fract);
		mlx_hook(fract->win, 17, 1L << 17, x_exit, fract);
		mlx_hook(fract->win, 6, 1L, event_mouse_key_julia, fract);
		mlx_mouse_hook(fract->win, event_mouse_key, fract);
		mlx_loop(fract->mlx);
	}
	return (0);
}
