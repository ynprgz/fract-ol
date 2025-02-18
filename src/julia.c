/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:11:44 by yaperalt          #+#    #+#             */
/*   Updated: 2025/02/18 11:14:50 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	julia(t_data *f)
{
	int		i;
	double	temp;

	i = 0;
	f->z_re = f->min_re + f->x * f->re_factor;
	f->z_im = f->max_im - f->y * f->im_factor;
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
