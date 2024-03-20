/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 02:15:15 by hel-omra          #+#    #+#             */
/*   Updated: 2024/03/20 14:54:19 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_b.h"

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

int	animation(t_elements *vrs)
{
	enemy_patrol(vrs);
	if (vrs->c != 0)
		chest_idle(vrs);
	return (0);
}

void	create_game(t_elements *vrs)
{
	init_t_mlx(vrs);
	put_map_to_window(vrs);
	print_move(vrs);
	mlx_key_hook(vrs->game.window, apply_moves, vrs);
	mlx_loop_hook(vrs->game.init, animation, vrs);
	mlx_hook(vrs->game.window, 17, 0, exit_window, vrs);
	mlx_loop(vrs->game.init);
	ft_free2d(vrs->map, vrs->y_len);
}
