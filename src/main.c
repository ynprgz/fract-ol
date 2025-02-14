/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:34:14 by yaperalt          #+#    #+#             */
/*   Updated: 2025/02/13 14:40:52 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/**
 *
 * @brief Initalize variables values and MiniLibX instance
 *
 */
void	init(t_data *f)
{

}

/**
 *
 * @brief Validates command-line arguments
 *
 */

int	main(int argc, char **argv)
{
	t_data *f;

	if (argc != 2 || (argv[1][0] != '1' && argv[1][0] != '2' &&
		argv[1][0] != '3'))
	{
		ft_putendl_fd("Correct usage: './fractol <fractal code>'.", 1);
		ft_putendl_fd("Available: Mandelbrot, Julia and Burningship.", 1);
		ft_putendl_fd("The codes are 1, 2 and 3 respectively.", 1);
		return (0);
	}
	f = malloc(sizeof(t_data));
	init_data(f);
}
