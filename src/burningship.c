/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:11:34 by yaperalt          #+#    #+#             */
/*   Updated: 2025/02/18 12:20:17 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	burningship(t_data *f)
{
	int		i;
	double	temp;

	i = 0;
	f->z_re = 0;
	f->z_im = 0;
	while (i < f->max_iters && ((f->z_re * f->z_re) + (f->z_im * f->z_im) < 4))
	{
		f->z_re = fabs(f->z_re);
		f->z_im = fabs(f->z_im);
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
