/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:35:33 by hel-omra          #+#    #+#             */
/*   Updated: 2024/03/20 14:30:53 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RESET "\033[0m"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include "mlx.h"

typedef struct s_position
{
	int		x;
	int		y;
}	t_position;

typedef struct s_mlx
{
	void	*init;
	void	*window;
	void	*player;
	void	*exit;
	void	*o_exit;
	void	*collect;
	void	*wall;
	void	*floor;
	int		moves;
}	t_mlx;

typedef struct s_elements
{
	t_position	exit;
	t_position	player;
	t_mlx		game;
	char		**map;
	char		**map_cp;
	int			fd;
	int			x_len;
	int			y_len;
	int			c;
	int			p;
	int			e;
}	t_elements;

// Parsing
void	check_syntax(char *av, t_elements *vrs);
void	map_innit(char *av, t_elements *vrs);
void	get_position(char **s, t_elements *vrs);
void	innit_t_elements(t_elements *x);
void	map_parse(char *av, t_elements *x);

// Utils
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s, char *buffer);
char	*get_next_line(int fd);
char	*ft_strdup(char	*s);
int		ft_strlen(char *s);
int		ft_strlen_nl(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putnbr(int n);

// Handle Errors
void	**ft_free2d(char **str, int k);
void	ft_error(char *s);
void	ft_putstr_fd(char *s, int fd);
void	mlx_error(t_elements *vrs, char *s);
int		exit_window(t_elements *vrs);

// Game 
void	put_image(t_elements *vrs, void *s, int x, int y);
void	*xpm_to_image(t_elements *vrs, char *s);
void	create_game(t_elements *vrs);
void	init_t_mlx(t_elements *vrs);
void	put_map_to_window(t_elements *vrs);
int		map_update(t_elements *vrs, char ***s, int x, int y);
void	move(char move, t_elements *vrs);

#endif