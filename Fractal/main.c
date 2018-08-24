#include "fractal.h"

void	option_argv(void)
{
    ft_putstr("\n  usage: ./fractol fractol_name\n");
    ft_putstr("__________________________________\n");
    ft_putstr("  M - mandelbrot\n");
    ft_putstr("  J - julia\n");
    ft_putstr("  F - fern\n");
    ft_putstr("  T - triangle\n");
}


int             main(int ac, char *av[])
{
       t_fract     fract[1];

//
//    if (!(win = (t_fract *)malloc(sizeof(t_fract*))))
//        return (1);
    if (ac < 2)
        option_argv();
    else if (ac > 2)
        ft_putstr("\n too many arguments\n");
    else if (ac == 2)
    {
        ft_putstr("MAIN\n");
        validation_fractal_name(av[1], fract);
        fract->mlx = mlx_init();
        fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGHT,
                                     "fractol by vrusanov");

        fract->image = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
        fract->addr = mlx_get_data_addr(fract->image, &fract->bits_per_pixel, &fract->size_line, &fract->endian);
        choice_fractal(fract);
        mlx_hook(fract->win, 2, 5, key_events, fract);
        mlx_hook(fract->win, 17, 1L << 17, x_exit, fract);
        mlx_hook(fract->win, 6, 1L, event_mouse_key_julia, fract);
        mlx_mouse_hook(fract->win, event_mouse_key, fract);
        mlx_loop(fract->mlx);

    }
    return (0);
}