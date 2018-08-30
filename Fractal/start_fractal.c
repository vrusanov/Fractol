#include "fractal.h"

void        choice_fractal(t_fract *fract)
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



void        start_fractal(t_fract *fract)
{
    fract->mlx = mlx_init();
    fract->mlx = mlx_new_window(fract->mlx, WIDTH, HEIGHT,
                                "fractol by vrusanov");
    fract->image = mlx_new_image(fract->mlx_ptr, WIDTH, HEIGHT);


}

