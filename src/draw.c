/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 07:47:11 by yaperalt          #+#    #+#             */
/*   Updated: 2025/02/14 08:50:31 by yaperalt         ###   ########.fr       */
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
				mandelbrot(f);
			if (f->f_code == 2)
				julia(f);
			if (f->f_code == 3)
				burningship(f);
			(f->y)++;
		}
		f->y = 0;
		(f->x)++;
	}
}
