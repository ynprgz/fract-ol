/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:11:34 by yaperalt          #+#    #+#             */
/*   Updated: 2025/02/15 15:49:39 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	burningship(t_data *f)
{
	int i;

	i = 0;
	while (i < f->max_iters)
	{

	}
	if (i == f->max_iters)
		put_pixel();
	else
		put_pixel((f->color * i));
}
