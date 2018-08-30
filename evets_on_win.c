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
    else if (fract->name_flag == 2)
    {
        write(1, "z",1);
        if (fract->deep * 2 < 21000000)
        {
            fract->deep *= 2;
            serpinsky_func(fract);
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
    else if (key == 69)
        ft_key_69(fract);
    else if (key == 78)
        ft_key_78(fract);
    return (0);
}

void        zoom_mouse_out(t_fract *fract)
{
    if (fract->name_flag == 0 || fract->name_flag == 1)
    {
        if (fract->deep > 10)
            fract->deep--;
        if (fract->zoom / 1.05 > 0.001)
            fract->zoom /= 1.05;
        printf("%f\n", fract->zoom);
        mandelbrot_func(fract);
//        printf("1221212\n");
    }
    else if (fract->name_flag == 2)
    {
        key_mouse_help_for_help(fract);
        serpinsky_func(fract);
    }
}
void        zoom_mouse(t_fract *fract)
{
    if (fract->name_flag == 0 || fract->name_flag == 1)
    {
        if (fract->deep < 10E7 && fract->zoom > 40)
            fract->deep++;
        if (fract->zoom * 1.05 < 2000000000)
            fract->zoom *= 1.05;
        printf("zoom = %f\n", fract->zoom);
        mandelbrot_func(fract);
    }
    else if (fract->name_flag == 2)
    {
            if (if_serp_positiv(fract) == 1)
            {
                fract->deep += 100;
                fract->serp.frst_x -= 100;
                fract->serp.frst_y += 100;
                fract->serp.scnd_y -= 100;
                fract->serp.thrd_x += 100;
                fract->serp.thrd_y += 100;
            }
            serpinsky_func(fract);
        }
}


void	key_mouse_help_for_help(t_fract *fract)// rename
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
    {
        fract->serp.frst_y -= 1;
        fract->serp.scnd_y += 1;
        fract->serp.thrd_x -= 1;
        fract->serp.thrd_y -= 1;
        fract->deep -= 1;
        fract->serp.frst_x += 1;
    }
}
void	ft_key_69(t_fract *fract) {
    if (fract->name_flag == 0) {
        if (fract->deep < 2147483647)
            fract->deep++;
        mandelbrot_func(fract);
    } else if (fract->name_flag == 1) {
        if (fract->deep < 2147483647)
            fract->deep++;
        mandelbrot_func(fract);
    } else if (fract->name_flag == 2)
    {
        write(1, "+", 1);
        fract->deep *= 1.5;
        //fract->zoom *= 1.05;
        printf("zoom = %f\n", fract->zoom);
        serpinsky_func(fract);
    }
}
void	ft_key_78(t_fract *fract) {
    if (fract->name_flag == 0) {
        if (fract->deep - 10 > 0)
            fract->deep--;
        mandelbrot_func(fract);
    } else if (fract->name_flag == 1) {
        if (fract->deep - 10 > 0)
            fract->deep--;
        mandelbrot_func(fract);
    } else if (fract->name_flag == 2) {
        write(1, "-", 1);
       // fract->zoom /= 1.05;
        fract->deep /= 1.5;
        serpinsky_func(fract);
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