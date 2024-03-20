/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:47:27 by hel-omra          #+#    #+#             */
/*   Updated: 2024/03/20 15:38:58 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_b.h"

void	map_innit(char *av, t_elements *vrs)
{
	char	*map;
	char	*line;

	vrs->fd = open(av, O_RDONLY);
	map = NULL;
	line = get_next_line(vrs->fd);
	while (line)
	{
		map = ft_strjoin(map, line);
		free(line);
		line = get_next_line(vrs->fd);
	}
	if (map && map[ft_strlen(map) - 1] == '\n')
		(close(vrs->fd), free(map),
			ft_error(RED"New line at the end of file !\n"RESET));
	vrs->map = ft_split(map, '\n');
	vrs->map_cp = ft_split(map, '\n');
	free(map);
	close(vrs->fd);
}

void	get_position(char **s, t_elements *vrs)
{
	int		x;
	int		y;

	y = 0;
	while (s[y])
	{
		x = 0;
		while (s[y][x])
		{
			if (s[y][x] == 'E')
				(1) && (vrs->exit.x = x, vrs->exit.y = y);
			if (s[y][x] == 'P')
				(1) && (vrs->player.x = x, vrs->player.y = y);
			x++;
		}
		y++;
	}
}

void	ft_syntax(char *line, t_elements *vrs)
{
	while (*line && *line != '\n')
	{
		if (*line != '1' && *line != '0' && *line != 'E'
			&& *line != 'P' && *line != 'C' && *line != 'N')
			(close(vrs->fd), ft_error(RED"Invalid map instractions !\n"RESET));
		else if (*line == 'C')
			vrs->c++;
		else if (*line == 'P')
			vrs->p++;
		else if (*line == 'E')
			vrs->e++;
		else if (*line == 'N')
			vrs->n++;
		line++;
	}
}

void	check_syntax_b(char *av, t_elements *vrs)
{
	char	*line;

	vrs->fd = open(av, O_RDWR);
	if (vrs->fd < 0)
		ft_error(RED"Invalid file !\n"RESET);
	line = get_next_line(vrs->fd);
	(line != NULL) && (vrs->x_len = ft_strlen_nl(line));
	while (line)
	{
		vrs->y_len++;
		ft_syntax(line, vrs);
		if (vrs->x_len != ft_strlen_nl(line))
			(close(vrs->fd), free(line),
				ft_error(RED"Map size invalid\n"RESET));
		free(line);
		line = get_next_line(vrs->fd);
	}
	close(vrs->fd);
	if (vrs->c == 0 || vrs->e != 1 || vrs->p != 1 || vrs->n > 5)
		ft_error(RED"Invalid map elements !\n"RESET);
	if (vrs->x_len > 128 || vrs->y_len > 128)
		ft_error(RED"Mlx can't render all this !\n"RESET);
}
