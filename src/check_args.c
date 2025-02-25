/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:19:02 by yaperalt          #+#    #+#             */
/*   Updated: 2025/02/25 14:31:30 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	check_args(int argc, char **argv)
{
	if (argc != 3)
	{
		put_message();
		return (1);
	}
	if ((argv[1][0] != '1' && argv[1][0] != '2' && argv[1][0] != '3')
		|| argv[1][1])
	{
		put_message();
		return (1);
	}
	if ((argv[2][0] != '0' && argv[2][0] != '1' && argv[2][0] != '2'
		&& argv[2][0] != '3') || argv[2][1])
	{
		put_message();
		return (1);
	}
	if ((argv[1][0] == '1' || argv[1][0] == '3') && argv[2][0] != '0')
	{
		put_message();
		return (1);
	}
	return (0);
}
