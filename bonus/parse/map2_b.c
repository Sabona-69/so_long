/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:47:27 by hel-omra          #+#    #+#             */
/*   Updated: 2024/03/19 03:37:00 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_b.h"

void	map_innit(char *av, t_elements *vrs)
{
	char	*map;
	char	*line;
	int		fd;

	fd = open(av, O_RDONLY);
	map = NULL;
	line = get_next_line(fd);
	while (line)
	{
		map = ft_strjoin(map, line);
		free(line);
		line = get_next_line(fd);
	}
	if (map && map[ft_strlen(map) - 1] == '\n')
		(free(map), ft_error(RED"New line at the end of file !\n"));
	vrs->map = ft_split(map, '\n');
	vrs->map_cp = ft_split(map, '\n');
	free(map);
	close(fd);
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

void	ft_syntax(char *line, t_elements *vrs, int fd)
{
	while (*line && *line != '\n')
	{
		if (*line != '1' && *line != '0' && *line != 'E'
			&& *line != 'P' && *line != 'C' && *line != 'N')
			(close(fd), ft_error(RED"Invalid map instractions !"));
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
	int		fd;

	fd = open(av, O_RDWR);
	if (fd < 0)
		ft_error(RED"Invalid file !");
	line = get_next_line(fd);
	(line != NULL) && (vrs->x_len = ft_strlen_nl(line));
	while (line)
	{
		vrs->y_len++;
		ft_syntax(line, vrs, fd);
		if (vrs->x_len != ft_strlen_nl(line))
			(close(fd), ft_error(RED"Map size invalid"));
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (vrs->c == 0 || vrs->e != 1 || vrs->p != 1 || vrs->n > 5)
		(ft_error(RED"Invalid map elements !"));
	if (vrs->x_len > 128 || vrs->y_len > 128)
		ft_error(RED"Mlx can't render all this !\n");
}
