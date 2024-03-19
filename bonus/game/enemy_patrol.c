/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_patrol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:58:43 by hel-omra          #+#    #+#             */
/*   Updated: 2024/03/19 02:53:00 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_b.h"

int	flag(void)
{
	int	rand;

	rand = clock() % 5;
	if (rand == 0)
		rand += 1;
	return (rand);
}

void	enemy_position(char **s, t_elements *vrs)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	x = 0;
	y = 0;
	while (s[y])
	{
		x = 0;
		while (s[y][x])
		{
			if (s[y][x] == 'N')
				(1) && (vrs->enemy[i].x = x, vrs->enemy[i].y = y, i++);
			x++;
		}
		y++;
	}
}

int	valid_move(char **s, int x, int y)
{
	if (s[y][x] != 'N' && s[y][x] != '1' && s[y][x] != 'E' && s[y][x] != 'C')
		return (0);
	return (1);
}

void	update_enemy(t_elements *vrs, int x, int y, int i)
{
	if (valid_move(vrs->map, x, y) == 0)
	{
		if (i != 4 && vrs->enemy[i].flag == 2 && vrs->enemy[i + 1].flag == 4)
			vrs->enemy[i].flag = flag();
		else if (i != 0 && vrs->enemy[i].flag == 1
			&& vrs->enemy[i + 1].flag == 3)
			vrs->enemy[i].flag = flag();
		if (vrs->map[y][x] == 'P')
			you_lost(vrs, i);
		put_image(vrs, vrs->game.floor, vrs->enemy[i].x, vrs->enemy[i].y);
		vrs->map[vrs->enemy[i].y][vrs->enemy[i].x] = '0';
		put_image(vrs, vrs->game.enemy, x, y);
		vrs->map[y][x] = 'N';
		vrs->enemy[i].x = x;
		vrs->enemy[i].y = y;
	}
	else
		vrs->enemy[i].flag = flag();
}

int	enemy_patrol(t_elements *vrs)
{
	static int		j;
	int				i;
	int				x;
	int				y;

	i = 0;
	if (j == 1500)
	{
		(1) && (enemy_position(vrs->map, vrs), j = 0);
		while (i < vrs->n)
		{
			(1) && (x = vrs->enemy[i].x, y = vrs->enemy[i].y);
			if (vrs->enemy[i].flag == 1)
				(1) && (x++, vrs->game.enemy = xpm_to_image(vrs, N_RIGHT));
			else if (vrs->enemy[i].flag == 2)
				(1) && (y++, vrs->game.enemy = xpm_to_image(vrs, N_LEFT));
			else if (vrs->enemy[i].flag == 3)
				(1) && (x--, vrs->game.enemy = xpm_to_image(vrs, N_LEFT));
			else if (vrs->enemy[i].flag == 4)
				(1) && (y--, vrs->game.enemy = xpm_to_image(vrs, N_RIGHT));
			(1) && (update_enemy(vrs, x, y, i), i++);
		}
	}
	j++;
	return (0);
}
