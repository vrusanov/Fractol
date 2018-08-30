#include "fractal.h"

void		option_julia(t_fract *fract)
{
    fract->deep = 200;
    fract->zoom = 300;
    fract->mv_x = 0;
    fract->mv_y = 0;
    fract->color = 1;
    fract->tmp_cre = -0.8169;
    fract->tmp_cim = -0.1189;
}