/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 02:15:15 by hel-omra          #+#    #+#             */
/*   Updated: 2024/03/19 06:22:53 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	*xpm_to_image(t_elements *vrs, char *s)
{
	void	*elem;
	int		i;

	i = 64;
	elem = mlx_xpm_file_to_image(vrs->game.init, s, &i, &i);
	if (!elem)
		mlx_error(vrs, RED"xpm file error !\n");
	return (elem);
}

void	put_image(t_elements *vrs, void *s, int x, int y)
{
	mlx_put_image_to_window(vrs->game.init, vrs->game.window,
		s, x * 64, y * 64);
}

int	apply_moves(int key, t_elements *vrs)
{
	if (key == 13 || key == 126)
		move('W', vrs);
	else if (key == 0 || key == 123)
		move('A', vrs);
	else if (key == 1 || key == 125)
		move('S', vrs);
	else if (key == 2 || key == 124)
		move('D', vrs);
	else if (key == 53)
		exit_window(vrs);
	return (0);
}

void	create_game(t_elements *vrs)
{
	init_t_mlx(vrs);
	put_map_to_window(vrs);
	mlx_key_hook(vrs->game.window, apply_moves, vrs);
	mlx_hook(vrs->game.window, 17, 0, exit_window, vrs);
	mlx_loop(vrs->game.init);
	ft_free2d(vrs->map, vrs->y_len);
}
