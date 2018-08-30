#include "fractal.h"

void        option_mandelbrot(t_fract *fract)
{
    fract->deep = 50;
    fract->mv_x = 0;
    fract->mv_y = 0;
    fract->color = 1;
    fract->zoom = 300;
}

void        mandelbrot_func(t_fract *fract)
{
    ft_bzero(fract->addr, WIDTH * HEIGHT * 4);
    calculs_dots(fract, WIDTH / 2 * -1, HEIGHT / 2 * -1, 0);
    mlx_put_image_to_window(fract->mlx_ptr, fract->win, fract->image, 0, 0);
}

void            if_mandelbrot(t_fract *fract, int *flag)
{
    fract->iter = -1;
    while (++fract->iter < fract->deep)
    {
        fract->tmp_re_2 = fract->tmp_re * fract->tmp_re;
        fract->tmp_im_2 = fract->tmp_im * fract->tmp_im;
        if (fract->tmp_re_2 + fract->tmp_im_2 > 1.0E5)
        {
            flag = 0;
            break ;
        }
        fract->tmp_im = 2 * fract->tmp_re * fract->tmp_im + fract->tmp_cim;
        fract->tmp_re = fract->tmp_re_2 - fract->tmp_im_2 + fract->tmp_cre;
    }
}

int             calculs_pixel(int x, int y)
{
    int count_pix;

    count_pix = 0;
    count_pix = (x * 4) + ((WIDTH * 4) * y);
    return (count_pix);
//    if (y > 0)
//        return (y * fract->string_size + x * 4);
//    else if (y == 0)
//        return (fract->string_size + x * 4);
//    else if (y < 0)
//        return (0);
//    return (0);
}

//int		calculs_pixel_for_serp(t_fract *fract, int x, int y)
//{
//    if (y > 0)
//        return (y * fract->size_line + x * 4);
//    else if (y == 0)
//        return (fract->size_line + x * 4);
//    else if (y < 0)
//        return (0);
//    return (0);
//}

void            fract_help_for_put(t_fract * fract, int x, int y)
{
    int count_pxl;

    if (fract->iter == fract->deep)
    {
        count_pxl = calculs_pixel(x + WIDTH / 2, (y + HEIGHT / 2) - 1);
        put_color_pixel_mndlbrt(fract, count_pxl, 0, 1);
    }
    else
    {
        count_pxl = calculs_pixel(x + WIDTH / 2, (y + HEIGHT / 2) - 1);
        put_color_pixel_mndlbrt(fract, count_pxl, (fract->iter * 225 * fract->deep) % 100, 0);
    }
}

void            put_color_pixel_mndlbrt(t_fract *fract, int count_pxl, int color, int flag)
{

    if (flag == 1)
    {
        fract->addr[count_pxl] = 0;
        fract->addr[count_pxl + 1] = 0;
        fract->addr[count_pxl + 2] = 0;
    }
    else
    {
        fract->addr[count_pxl] = color * 265 >> 8;
        fract->addr[count_pxl + 1] = color * 265 << 8;
        fract->addr[count_pxl + 2] = color * 265;
    }
}

//void            fract_help(t_fract *fract, int count_pxl, int flag, int x)
//{
//
//}

void            calculs_dots( t_fract *fract, int x, int y, int flag)
{
    t_mndlbrt sv; //rename

    while (++y < HEIGHT / 2)
    {
        sv.cim = y / fract->zoom;
        if (fract->name_flag == 0)
            fract->tmp_cim = sv.cim;
        x = (WIDTH / 2) * -1;
        while (++x < WIDTH / 2)
        {
            if (fract->name_flag == 0)
            {
                sv.cre = x / fract->zoom - 0.5;
                fract->tmp_cre = sv.cre;
            }
            else
                sv.cre = x / fract->zoom;
            fract->tmp_re = sv.cre;
            fract->tmp_im = sv.cim;
            if_mandelbrot(fract, &flag);
            fract_help_for_put(fract, x, y);
        }
    }
}
//if (fract->iter == fract->deep)
//{
//mlx_pixel_put(fract->mlx_ptr, fract->win, x + 500, y + 500, 0x000000);
//}
//else
//mlx_pixel_put(fract->mlx_ptr, fract->win, x + 500, y + 500, (0xffffff / fract->deep * fract->iter ));
////                mlx_pixel_put(fract->mlx_ptr, fract->win, x + 500, y + 500, (fract->iter % 32) * 0xFFF000);
//}

//            if (fract->iter == fract->deep)
//            {
//                count_pxl = calculs_pixel(x + WIDTH / 2, (y + HEIGHT / 2) - 1);
//                put_color_pixel_mndlbrt(fract, count_pxl, 0, 1);
//            }
//            else
//            {
//                count_pxl = calculs_pixel(x + WIDTH / 2, (y + HEIGHT / 2) - 1);
//                put_color_pixel_mndlbrt(fract, count_pxl, (0xffef / fract->deep * fract->iter), 0);
//            }