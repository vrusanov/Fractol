/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrusanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:52:37 by vrusanov          #+#    #+#             */
/*   Updated: 2018/08/31 19:55:21 by vrusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRACTAL_H
# define _FRACTAL_H

# include "./libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

# define HEIGHT		1000
# define WIDTH 		1000

typedef struct		s_serpinsky
{
	int				x;
	int				y;
	int				frst_x;
	int				frst_y;
	int				scnd_x;
	int				scnd_y;
	int				thrd_x;
	int				thrd_y;
}					t_serp;

typedef struct		s_mandelbrot
{
	double			cim;
	double			cre;
}					t_mndlbrt;

typedef struct		s_julia
{
	double			cre;
	double			cim;
	double			old_cre;
	double			old_cim;
}					t_julia;

typedef struct		s_fractal
{
	t_serp			serp;
	t_julia			julia;
	t_mndlbrt		mndlbrt;
	void			*mlx_ptr;
	void			*mlx;
	void			*win;
	void			*image;
	int				name_flag;
	double			mv_x;
	double			mv_y;
	double			zoom;
	int				color;
	int				deep;
	char			*addr;
	double			tmp_re;
	double			tmp_im;
	double			tmp_re_2;
	double			tmp_im_2;
	int				iter;
	int				size_line;
	int				endian;
	int				bits_per_pixel;
	int				count_pxl;
	double			tmp_cre;
	double			tmp_cim;
}					t_fract;

void				error_fractal(int i);
void				validation_fractal_name(char *fract_name, t_fract *fract);
void				option_argv(void);
void				start_fractal(t_fract *fract);
void				option_mandelbrot(t_fract *fract);
void				mandelbrot_func(t_fract *fract);
void				choice_fractal(t_fract *fract);
void				start_fractal(t_fract *fract);
void				calculs_dots(t_fract *fract, int x, int y, int flag);
int					key_events(int key, t_fract *window);
int					x_exit(t_fract *fract);
void				deep_maker(t_fract *fract);
void				zoom_mouse(t_fract *fract);
int					event_mouse_key(int key, int x, int y, t_fract *fract);
void				zoom_mouse_out(t_fract *fract);
int					event_mouse_key_julia(int x, int y, t_fract *fract);
void				put_color_pixel_mndlbrt(t_fract *fract,
		int count_pxl, double color, int flag);
int					calculs_pixel(int x, int y);
void				fract_help_for_put(t_fract *fract, int x, int y);
double				random_for_serp(int n, int iter);
void				option_julia(t_fract *fract);
void				option_serpinsky(t_fract *fract);
void				put_color_pixel_serp(t_fract *fract,
		int x, int y, int color);
void				find_dots_serpinskogo(t_fract *fract, int iter, int tmp);
void				serpinsky_func(t_fract *fract);
int					calculs_pixel_for_serp(t_fract *fract, int x, int y);
int					if_serp_negative(t_fract *fract);
int					if_serp_positiv(t_fract *fract);
void				zoom_mouse_for_serp(t_fract *fract);
void				key_78(t_fract *fract);
void				key_69(t_fract *fract);
void				ft_error_fractal(int i);
void				hlp_zoom_mouse_serp(t_fract *fract);

#endif
