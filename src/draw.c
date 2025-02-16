/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 07:47:11 by yaperalt          #+#    #+#             */
/*   Updated: 2025/02/15 14:10:09 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	draw_fractal(t_data *f)
{
	f->x = 0;
	f->y = 0;
	while (f->x < HEIGHT)
	{
		while (f->y < WIDTH)
		{
			if (f->f_code == 1)
			{
				// mandelbrot(f);
				put_pixel(f, f->x, f->y, 0xFF5733);
			}
			else if (f->f_code == 2)
			{
				// julia(f);
				put_pixel(f, f->x, f->y, 0x4CAF50);
			}
			else if (f->f_code == 3)
			{
				// burningship(f);
				put_pixel(f, f->x, f->y, 0x3A6EA5);
			}
			(f->y)++;
		}
		f->y = 0;
		(f->x)++;
	}
}
