/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:11:25 by yaperalt          #+#    #+#             */
/*   Updated: 2025/02/18 11:30:36 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/**
  Initialize z = 0

  Iterate until the max number of iterations is reached
  or the magnitude of z exceeds 2 (i.e., z_re² + z_im² >= 4)

  Color the pixel depending on the escape count:
  - Black if the point is in the Mandelbrot set (max iterations reached)
  - Otherwise, a color scaled by the number of iterations
 */
void	mandelbrot(t_data *f)
{
	int		i;
	double	temp;

	i = 0;
	f->z_re = 0;
	f->z_im = 0;
	while (i < f->max_iters && ((f->z_re * f->z_re) + (f->z_im * f->z_im) < 4))
	{
		temp = f->z_re;
		f->z_re = f->z_re * f->z_re - f->z_im * f->z_im + f->c_re;
		f->z_im = 2 * f->z_im * temp + f->c_im;
		i++;
	}
	if (i == f->max_iters)
		put_pixel(f, f->x, f->y, 0x0);
	else
		put_pixel(f, f->x, f->y, (f->color * i));
}
