/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:26:34 by hel-omra          #+#    #+#             */
/*   Updated: 2024/03/19 05:47:13 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	check_name(char *av)
{
	int	i;

	i = ft_strlen(av);
	if (i < 4 || ft_strncmp(&av[i - 4], ".ber", 4) != 0)
		(ft_error(RED"Invalid Name !\n"), exit(1));
}

void	innit_t_elements(t_elements *vrs)
{
	vrs->exit.x = 0;
	vrs->exit.y = 0;
	vrs->player.x = 0;
	vrs->player.y = 0;
	vrs->x_len = 0;
	vrs->y_len = 0;
	vrs->c = 0;
	vrs->p = 0;
	vrs->e = 0;
	vrs->map = NULL;
	vrs->map_cp = NULL;
}

void	check_walls(char **s, int x, int y)
{
	int	i;

	i = 0;
	while (s[y])
	{
		while (s[0][i] && s[y][i])
		{
			if (s[0][i] != '1' || s[y][i] != '1')
				ft_error(RED"Invalid Map !\nCheck the walls\n");
			i++;
		}
		y++;
	}
	y = 1;
	while (s[y])
	{
		if (s[y][0] != '1' || s[y][x] != '1')
			ft_error(RED"Invalid Map !\nCheck the walls\n");
		y++;
	}
}

void	flood_fill(char ***s, int y, int x)
{
	if ((*s)[y][x] == 'E')
		(*s)[y][x] = '1';
	else if ((*s)[y][x] != '1')
	{
		(*s)[y][x] = '1';
		flood_fill(s, y, x + 1);
		flood_fill(s, y, x - 1);
		flood_fill(s, y + 1, x);
		flood_fill(s, y - 1, x);
	}
}

void	map_parse(char *av, t_elements *vrs)
{
	int		i;
	int		j;

	j = 0;
	check_name(av);
	check_syntax(av, vrs);
	map_innit(av, vrs);
	check_walls(vrs->map, vrs->x_len - 1, vrs->y_len - 1);
	get_position(vrs->map, vrs);
	flood_fill(&vrs->map_cp, vrs->player.y, vrs->player.x);
	while (vrs->map_cp[j])
	{
		i = 0;
		while (vrs->map_cp[j][i])
		{
			if (vrs->map_cp[j][i] == 'C' || vrs->map_cp[j][i] == 'P'
				|| vrs->map_cp[j][i] == 'E')
				(ft_error(RED"Invalid path !\nYou can't win\n"), exit(1));
			i++;
		}
		j++;
	}
	ft_free2d(vrs->map_cp, j);
}
