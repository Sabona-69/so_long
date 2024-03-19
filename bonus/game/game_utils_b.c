/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:06:42 by hel-omra          #+#    #+#             */
/*   Updated: 2024/03/19 05:36:12 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_b.h"

void	init_t_mlx(t_elements *vrs)
{
	int		j;

	j = 0;
	while (j < vrs->n)
		vrs->enemy[j++].flag = flag();
	vrs->game.moves = 0;
	vrs->game.init = mlx_init();
	vrs->game.window = mlx_new_window(vrs->game.init, vrs->x_len * 64,
			vrs->y_len * 64, "so_long");
	vrs->game.player = xpm_to_image(vrs, DOWN);
	vrs->game.enemy = xpm_to_image(vrs, N_RIGHT);
	vrs->game.exit = xpm_to_image(vrs, "textures/chest/0.xpm");
	vrs->game.o_exit = xpm_to_image(vrs, "textures/chest/6.xpm");
	vrs->game.collect = xpm_to_image(vrs, "textures/collect.xpm");
	vrs->game.wall = xpm_to_image(vrs, "textures/wall.xpm");
	vrs->game.floor = xpm_to_image(vrs, "textures/floor.xpm");
	if (!vrs->game.init || !vrs->game.window)
		mlx_error(vrs, RED"xpm init or window error !\n");
}

void	update_player(t_elements *vrs, int x, int y)
{
	put_image(vrs, vrs->game.floor, vrs->player.x, vrs->player.y);
	put_image(vrs, vrs->game.floor, x, y);
	put_image(vrs, vrs->game.player, x, y);
	mlx_do_sync(vrs->game.init);
}

int	find_n(char **s, t_elements *vrs)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	while (i < vrs->n)
	{
		x = vrs->enemy[i].x;
		y = vrs->enemy[i].y;
		if (s[y + 1][x] == 'P' || s[y - 1][x] == 'P' ||
			s[y][x + 1] == 'P' || s[y][x - 1] == 'P')
			return (i);
		i++;
	}
	return (i);
}

int	map_update(t_elements *vrs, int x, int y)
{
	if (vrs->map[y][x] == '1' || (vrs->map[y][x] == 'E' && vrs->c != 0))
		return (1);
	if (vrs->map[y][x] == 'N')
		you_lost(vrs, find_n(vrs->map, vrs));
	if (vrs->map[y][x] == 'C' || vrs->map[y][x] == '0')
	{
		vrs->map[vrs->player.y][vrs->player.x] = '0';
		if (vrs->map[y][x] == 'C')
			vrs->c--;
		vrs->map[y][x] = 'P';
	}
	print_move(vrs);
	if (vrs->c == 0)
	{
		put_image(vrs, vrs->game.floor, vrs->exit.x, vrs->exit.y);
		put_image(vrs, vrs->game.o_exit, vrs->exit.x, vrs->exit.y);
	}
	if (vrs->map[y][x] == 'E' && vrs->c == 0)
		ft_win(vrs);
	update_player(vrs, x, y);
	(1) && (vrs->player.x = x, vrs->player.y = y);
	return (0);
}

void	move(char move, t_elements *vrs)
{
	int		x;
	int		y;

	(1) && (x = vrs->player.x, y = vrs->player.y);
	if (move == 'W')
		(1) && (y -= 1, vrs->game.player = xpm_to_image(vrs, UP));
	else if (move == 'A')
		(1) && (x -= 1, vrs->game.player = xpm_to_image(vrs, LEFT));
	else if (move == 'S')
		(1) && (y += 1, vrs->game.player = xpm_to_image(vrs, DOWN));
	else if (move == 'D')
		(1) && (x += 1, vrs->game.player = xpm_to_image(vrs, RIGHT));
	map_update(vrs, x, y);
}
