/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:11:25 by yaperalt          #+#    #+#             */
/*   Updated: 2025/02/16 07:12:03 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	mandelbrot(t_data *f)
{
	int i;

	i = 0;
	while (i < f->max_iters)
	{

	}
	if (f->max_iters == i)
		put_pixel();
	else
		put_pixel((f->color * i));
}
