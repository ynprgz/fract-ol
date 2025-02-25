/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 07:47:11 by yaperalt          #+#    #+#             */
/*   Updated: 2025/02/25 13:05:42 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	draw_fractal(t_data *f)
{
	f->y = 0;
	mlx_clear_window(f->mlx, f->window);
	while (f->y < HEIGHT)
	{
		f->x = 0;
		while (f->x < WIDTH)
		{
			if (f->f_code == 1 || f->f_code == 3)
			{
				f->c_re = f->min_re + f->x * f->re_factor;
				f->c_im = f->max_im - f->y * f->im_factor;
			}
			if (f->f_code == 1)
				mandelbrot(f);
			else if (f->f_code == 2)
				julia(f);
			else if (f->f_code == 3)
				burningship(f);
			f->x++;
		}
		f->y++;
	}
}
