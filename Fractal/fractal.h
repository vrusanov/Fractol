#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

# define HEIGHT		1000
# define WIDTH 		1000

typedef struct      s_mandelbrot
{
    double          cim;
    double          cre;
//    double          tmp_im;
//    double          tmp_re;

}                   t_mndlbrt;

typedef struct	s_julia
{
    double cre;
    double cim;
    double old_cre;
    double old_cim;
}				t_julia;

typedef struct       s_fractal
{
    t_julia         julia;
    t_mndlbrt       manda;
    void             *mlx_ptr;
    void             *mlx;
    void             *win;
    void             *image;
    int              name_flag;
    double           mv_x;
    double           mv_y;
    double           zoom;
    int              color;
    int              deep;
    char             *addr;
    double           tmp_re;
    double           tmp_im;
    double           tmp_re_2;
    double           tmp_im_2;
    int              iter;
    int              size_line;
    int              endian;
    int              bits_per_pixel;
    int              count_pxl;
    double           tmp_cre;
    double           tmp_cim;

}                    t_fract;

void    error_fractal(int i);
void    validation_fractal_name(char *fract_name, t_fract *fract);
void	option_argv(void);
void    start_fractal(t_fract *fract);
void    option_mandelbrot(t_fract *fract);
void    mandelbrot_func(t_fract *fract);
void    choice_fractal(t_fract *fract);
void    start_fractal(t_fract *fract);
void    calculs_dots( t_fract *fract, int x, int y, int flag);
int	    key_events(int key, t_fract *window);
int		x_exit(t_fract *fract);
void	deep_maker(t_fract *fract);
void    zoom_mouse(t_fract *fract);
int     event_mouse_key(int key, int x, int y, t_fract *fract);
void    zoom_mouse_out(t_fract *fract);
int     event_mouse_key_julia(int x, int y, t_fract *fract);
void    put_color_pixel_mndlbrt(t_fract *fract, int count_pxl, int color, int flag);
void    fract_help_for_put(t_fract * fract, int x, int y);


void		option_julia(t_fract *fract);

#endif