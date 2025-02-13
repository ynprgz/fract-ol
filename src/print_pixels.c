/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pixels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 07:18:19 by yaperalt          #+#    #+#             */
/*   Updated: 2025/02/14 08:58:36 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void put_pixel(t_data *f, int x, int y, int color)
{
    char	*pixel;

    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;
    pixel = f->addr + (y * f->line_length + x * (f->bpp / 8));
    *(unsigned int *)pixel = color;
}
