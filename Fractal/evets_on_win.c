#include "fractal.h"

int			x_exit(t_fract *fract)
{

    mlx_destroy_window(fract->mlx, fract->win);
    exit(0);
    return (0);
}

void	deep_maker(t_fract *fract)
{
    if (fract->name_flag == 0 || fract->name_flag == 1)
    {
        if (fract->deep < 2147483647)
        {
            fract->deep++;
            mandelbrot_func(fract);
        }
    }
}

int         event_mouse_key(int key, int x, int y, t_fract *fract)
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
    return (0);
}

void        zoom_mouse_out(t_fract *fract) {
    if (fract->name_flag == 0 || fract->name_flag == 1) {
        if (fract->deep > 10) {
            fract->deep--;
            fract->zoom /= 1.05;
            mandelbrot_func(fract);

        }
    }
}
void        zoom_mouse(t_fract *fract)
{
    if (fract->name_flag == 0 || fract->name_flag == 1)
    {
        if (fract->deep < 10E7 && fract->zoom > 30) {
            fract->deep++;
            fract->zoom *= 1.05;
            mandelbrot_func(fract);
        }
    }
}


int     event_mouse_key_julia(int x, int y, t_fract *fract)
{
    if (x > 0 && x < 1000 && y > 0 && y < 1000 && fract->name_flag == 1)  {
//        ft_putendl("1234");
        fract->tmp_cre = -0.8169 + (double)x / 1000;
        fract->tmp_cim = -0.1189 + (double)y / 1000;
        mandelbrot_func(fract);
    }
    return (0);
}