/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_to_complexplane.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 05:04:55 by yaperalt          #+#    #+#             */
/*   Updated: 2025/02/25 13:42:43 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	pixel_to_complexplane(t_data *f)
{
	f->re_factor = (f->max_re - f->min_re) / (WIDTH - 1);
	f->im_factor = (f->max_im - f->min_im) / (HEIGHT - 1);
	f->move_factor = 0.1 * (f->max_re - f->min_re);
}

void	set_coord(t_data *f)
{
	f->min_re = -1.5;
	f->max_re = 1.5;
	f->min_im = -1.5;
	f->max_im = 1.5;
}
