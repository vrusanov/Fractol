#include "fractal.h"

void    option_serpinsky(t_fract *fract)
{
    fract->deep = 600000;
    fract->serp.scnd_x = 500;
    fract->serp.scnd_y = 0;
    fract->serp.frst_x = 0;
    fract->serp.frst_y = 1000;
    fract->serp.thrd_x = 1000;
    fract->serp.thrd_y = 1000;
}

int		if_serp_positiv(t_fract *fract)
{
    if (fract->serp.thrd_x + 1000 > 10E8)
        return (0);
    return (1);
}

int		if_serp_negative(t_fract *fract)
{
    if (fract->serp.thrd_x - fract->serp.frst_x < 250)
        return (0);
    return (1);
}

void	put_color_pixel_serp(t_fract *fract, int x, int y, int color)
{
    int i;

    if (x < WIDTH && y < HEIGHT && x > 0 && y > 0)
    {
        i = calculs_pixel(x, y - 1);
//        printf("i = %d\n", i);
        fract->addr[i] = 59;
        fract->addr[i + 1] = color;
        fract->addr[i + 2] = 2;
    }
}

void	find_dots_serpinskogo(t_fract *fract, int iter, int tmp)
{
    fract->serp.x = (fract->serp.frst_x + fract->serp.scnd_x) / 2;
    fract->serp.y = (fract->serp.frst_y + fract->serp.scnd_y) / 2;
    while (iter++ < fract->deep)
    {
        tmp = random_for_serp(10, 1); // написать
        if (tmp > 0 && tmp < 4)
        {
            fract->serp.x = (fract->serp.x + fract->serp.frst_x) / 2;
            fract->serp.y = (fract->serp.y + fract->serp.frst_y) / 2;
            put_color_pixel_serp(fract, fract->serp.x, fract->serp.y, 225);
        }
        else if (tmp > 3 && tmp < 7)
        {
            fract->serp.x = (fract->serp.x + fract->serp.scnd_x) / 2;
            fract->serp.y = (fract->serp.y + fract->serp.scnd_y) / 2;
            put_color_pixel_serp(fract, fract->serp.x, fract->serp.y, 225);
        }
        else if (tmp > 6 && tmp < 10)
        {
            fract->serp.x = (fract->serp.x + fract->serp.thrd_x) / 2;
            fract->serp.y = (fract->serp.y + fract->serp.thrd_y) / 2;
            put_color_pixel_serp(fract, fract->serp.x, fract->serp.y, 225);
        }
    }
}


void	serpinsky_func(t_fract *fract)
{
    ft_bzero(fract->addr, WIDTH * HEIGHT * 4);
    find_dots_serpinskogo(fract, 0, 0);
    mlx_put_image_to_window(fract->mlx_ptr, fract->win, fract->image, 0, 0);
}