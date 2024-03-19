/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_b.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:35:33 by hel-omra          #+#    #+#             */
/*   Updated: 2024/03/19 06:29:06 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_B_H
# define SO_LONG_B_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RESET "\033[0m"

# define UP "textures/player/up.xpm"
# define LEFT "textures/player/left.xpm"
# define DOWN "textures/player/down.xpm"
# define RIGHT "textures/player/right.xpm"
# define N_LEFT "textures/enemy/left.xpm"
# define N_RIGHT "textures/enemy/right.xpm"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include "mlx.h"
# include <time.h>

typedef struct s_position
{
	int		x;
	int		y;
}	t_position;

typedef struct s_enemy
{
	int		x;
	int		y;
	int		flag;
}	t_enemy;

typedef struct s_mlx
{
	void			*init;
	void			*window;
	void			*player;
	void			*enemy;
	void			*exit;
	void			*o_exit;
	void			*collect;
	void			*wall;
	void			*floor;
	int				moves;
}	t_mlx;

typedef struct s_elements
{
	t_position		exit;
	t_position		player;
	t_enemy			enemy[5];
	t_mlx			game;
	void			*attack[6];
	void			*chest[10];
	char			*attack_m[6];
	char			*chest_m[10];
	char			**map;
	char			**map_cp;
	int				x_len;
	int				y_len;
	int				c;
	int				p;
	int				e;
	int				n;
	int				temp;
}	t_elements;

// Parsing
void	check_syntax_b(char *av, t_elements *vrs);
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
void	*xpm_to_image(t_elements *vrs, char *s);
void	you_lost(t_elements *vrs, int i);
void	ft_win(t_elements *vrs);
int		flag(void);
void	put_image(t_elements *vrs, void *s, int x, int y);
char	*ft_itoa(int nbr);

// Handle Errors
void	**ft_free2d(char **str, int k);
void	ft_error(char *s);
void	ft_putstr_fd(char *s, int fd);
void	mlx_error(t_elements *vrs, char *s);

// Game
void	attack(t_elements *vrs, int i);
void	print_move(t_elements *vrs);
void	create_game(t_elements *vrs);
void	init_t_mlx(t_elements *vrs);
void	put_map_to_window(t_elements *vrs);
int		map_update(t_elements *vrs, int x, int y);
void	move(char move, t_elements *vrs);
int		enemy_patrol(t_elements *vrs);
void	enemy_position(char **s, t_elements *vrs);
void	chest_idle(t_elements *vrs);
int		exit_window(t_elements *vrs);

#endif