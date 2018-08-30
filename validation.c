
#include  "fractal.h"

void    validation_fractal_name(char *fract_name, t_fract *fract)
{

    if (ft_strcmp("Mandelbrot", fract_name) == 0 || ft_strcmp("M", fract_name) == 0)
    {
        printf("%s\n", fract_name);
        fract->name_flag = 0;
        printf("%d\n", fract->name_flag);
    }
    else if (ft_strcmp("Julia", fract_name) == 0 || ft_strcmp("J", fract_name) == 0)
    {
        printf("%s\n", fract_name);
        fract->name_flag = 1;
        printf("%d\n", fract->name_flag);
    }
    else if (ft_strcmp("Serpinsky", fract_name) == 0 || ft_strcmp("S", fract_name) == 0)
    {
        fract->name_flag = 2;
    }
    else
        exit(1);
    option_argv();
//    exit(1);
}

void ft_error_fractal(int i)
{
    if (i == 2)
        ft_putendl("error!");
}