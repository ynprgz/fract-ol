/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_to_complexplane.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 05:04:55 by yaperalt          #+#    #+#             */
/*   Updated: 2025/02/19 09:17:47 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
/*
 * Define the region of the complex plane:
 *   - Real part ranges from -2.0 (left) to 2.0 (right).
 *   - Imaginary part's lower bound is fixed at -2.
 *
 * Instead of setting a fixed upper imaginary bound,
 * we calculate MaxIm automatically based on the image dimensions
 * and the real part span. This avoids stretching the image.
 */

void	pixel_to_complexplane(t_data *f)
{
	f->min_re = -2;
	f->max_re = 2;
	f->min_im = -2;
	f->max_im = f->min_im + (f->max_re - f->min_re) * HEIGHT / WIDTH;
	f->re_factor = (f->max_re - f->min_re) / (WIDTH - 1);
	f->im_factor = (f->max_im - f->min_im) / (HEIGHT - 1);
}

/*
 * Pixel-to-complex mapping:
 *   - Top-left pixel: [0, 0]
 *   - Bottom-right pixel: [ImageWidth-1, ImageHeight-1]
 *
 * For a pixel at coordinate [x, y], the corresponding complex number is
 * computed as:
 *
 *   c_re = MinRe + x * (MaxRe - MinRe) / (ImageWidth - 1);
 *   c_im = MaxIm - y * (MaxIm - MinIm) / (ImageHeight - 1);
 *
 * Note: The y-coordinate is inverted relative to the imaginary axis,
 * hence the subtraction in the c_im calculation.
 */
