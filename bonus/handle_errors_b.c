/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:45:05 by hel-omra          #+#    #+#             */
/*   Updated: 2024/03/19 03:51:56 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_b.h"

void	ft_error(char *s)
{
	ft_putstr_fd(s, 2);
	exit(1);
}

void	**ft_free2d(char **str, int k)
{
	while (k >= 0)
	{
		free(str[k]);
		k--;
	}
	free(str);
	return (NULL);
}

int	exit_window(t_elements *vrs)
{
	ft_free2d(vrs->map, vrs->y_len);
	ft_putstr_fd(RED"Good Bye !\n"RESET, 1);
	exit(0);
}

void	mlx_error(t_elements *vrs, char *s)
{
	ft_free2d(vrs->map, vrs->y_len);
	ft_putstr_fd(s, 2);
	mlx_destroy_window(vrs->game.init, vrs->game.window);
	exit (1);
}
