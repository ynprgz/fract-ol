/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pixels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 07:18:19 by yaperalt          #+#    #+#             */
/*   Updated: 2025/02/18 12:19:46 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/**
 * The image is stored linearly in memory (as a long string of bytes).
 * To find the pixel at position (x, y), we need to jump:
 *
 * Each row takes up f->line_length bytes. We multiply y * f->line_length to
 * jump all the rows before row y.
 *
 * Each pixel takes up f->bpp / 8 bytes (since bpp are bits, and dividing by
 * 8 gives us bytes). We multiply x * (f->bpp / 8) to jump the previous pixels
 * in that same row.
 */
void	put_pixel(t_data *f, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	pixel = f->addr + (y * f->line_length + x * (f->bpp / 8));
	*(unsigned int *)pixel = color;
}
