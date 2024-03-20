/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_b2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 02:29:56 by hel-omra          #+#    #+#             */
/*   Updated: 2024/03/20 15:25:12 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_b.h"

void	*xpm_to_image(t_elements *vrs, char *s)
{
	void	*elem;
	int		i;

	i = 64;
	elem = mlx_xpm_file_to_image(vrs->game.init, s, &i, &i);
	if (!elem)
		mlx_error(vrs, RED"xpm file error !\n"RESET);
	return (elem);
}

void	put_image(t_elements *vrs, void *s, int x, int y)
{
	mlx_put_image_to_window(vrs->game.init, vrs->game.window,
		s, x * 64, y * 64);
}

void	put_map_to_window(t_elements *vrs)
{
	int		i;
	int		j;

	j = 0;
	while (vrs->map[j])
	{
		i = 0;
		while (vrs->map[j][i])
		{
			put_image(vrs, vrs->game.floor, i, j);
			if (vrs->map[j][i] == '1')
				put_image(vrs, vrs->game.wall, i, j);
			else if (vrs->map[j][i] == 'C')
				put_image(vrs, vrs->game.collect, i, j);
			else if (vrs->map[j][i] == 'N')
				put_image(vrs, vrs->game.enemy, i, j);
			i++;
		}
		j++;
	}
	put_image(vrs, vrs->game.exit, vrs->exit.x, vrs->exit.y);
	put_image(vrs, vrs->game.player, vrs->player.x, vrs->player.y);
}
