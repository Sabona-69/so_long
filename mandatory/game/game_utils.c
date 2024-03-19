/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 05:58:23 by hel-omra          #+#    #+#             */
/*   Updated: 2024/03/19 06:19:54 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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
			i++;
		}
		j++;
	}
	put_image(vrs, vrs->game.exit, vrs->exit.x, vrs->exit.y);
	put_image(vrs, vrs->game.player, vrs->player.x, vrs->player.y);
}

void	init_t_mlx(t_elements *vrs)
{
	vrs->game.moves = 0;
	vrs->game.init = mlx_init();
	vrs->game.window = mlx_new_window(vrs->game.init, vrs->x_len * 64,
			vrs->y_len * 64, "so_long");
	vrs->game.player = xpm_to_image(vrs, "textures/player/down.xpm");
	vrs->game.exit = xpm_to_image(vrs, "textures/chest/0.xpm");
	vrs->game.o_exit = xpm_to_image(vrs, "textures/chest/6.xpm");
	vrs->game.collect = xpm_to_image(vrs, "textures/collect.xpm");
	vrs->game.wall = xpm_to_image(vrs, "textures/wall.xpm");
	vrs->game.floor = xpm_to_image(vrs, "textures/floor.xpm");
	if (!vrs->game.init || !vrs->game.window)
		mlx_error(vrs, RED"xpm init or window error !\n");
}

void	ft_win(t_elements *vrs)
{
	ft_free2d(vrs->map, vrs->y_len);
	(ft_putstr_fd(GREEN"You Win !\n"RESET, 1), exit(1));
}

int	map_update(t_elements *vrs, char ***s, int x, int y)
{
	if ((*s)[y][x] == '1' || ((*s)[y][x] == 'E' && vrs->c != 0))
		return (1);
	if ((*s)[y][x] == 'C' || (*s)[y][x] == '0')
	{
		(*s)[vrs->player.y][vrs->player.x] = '0';
		if ((*s)[y][x] == 'C')
			vrs->c--;
		(*s)[y][x] = 'P';
	}
	ft_putstr_fd("moves : "YELLOW, 1);
	ft_putnbr(vrs->game.moves++);
	ft_putstr_fd(RESET"\n", 1);
	vrs->player.x = x;
	vrs->player.y = y;
	put_map_to_window(vrs);
	if (vrs->c == 0)
	{
		put_image(vrs, vrs->game.floor, vrs->exit.x, vrs->exit.y);
		put_image(vrs, vrs->game.o_exit, vrs->exit.x, vrs->exit.y);
	}
	if ((*s)[y][x] == 'E' && vrs->c == 0)
		ft_win(vrs);
	return (0);
}

void	move(char move, t_elements *vrs)
{
	int		x;
	int		y;

	x = vrs->player.x;
	y = vrs->player.y;
	if (move == 'W')
		y -= 1;
	else if (move == 'A')
		x -= 1;
	else if (move == 'S')
		y += 1;
	else if (move == 'D')
		x += 1;
	map_update(vrs, &vrs->map, x, y);
}
