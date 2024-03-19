/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 23:24:28 by hel-omra          #+#    #+#             */
/*   Updated: 2024/03/19 03:43:09 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_b.h"

void	you_lost(t_elements *vrs, int i)
{
	void	*defeat;

	defeat = xpm_to_image(vrs, "textures/defeat.xpm");
	mlx_put_image_to_window(vrs->game.init, vrs->game.window,
		defeat, (vrs->x_len / 2 - 1) * 64, 0 * 64);
	attack(vrs, i);
	usleep(100000);
	mlx_error(vrs, RED"YOU LOST T-T \n"RESET);
}

void	ft_win(t_elements *vrs)
{
	void			*victory;

	put_image(vrs, vrs->game.floor, vrs->player.x, vrs->player.y);
	put_image(vrs, vrs->game.player, vrs->exit.x, vrs->exit.y);
	victory = xpm_to_image(vrs, "textures/victory.xpm");
	put_image(vrs, victory, vrs->x_len / 2 - 1, 0);
	mlx_do_sync(vrs->game.init);
	sleep(2);
	ft_free2d(vrs->map, vrs->y_len);
	(ft_putstr_fd(GREEN"You Win !\n"RESET, 1), exit(1));
}

void	print_move(t_elements *vrs)
{
	void	*moves;
	char	*s;

	s = ft_itoa(vrs->game.moves);
	ft_putstr_fd("moves : ", 1);
	moves = xpm_to_image(vrs, "textures/moves3.xpm");
	mlx_put_image_to_window(vrs->game.init, vrs->game.window,
		moves, 0 * 150, 0 * 64);
	mlx_string_put(vrs->game.init, vrs->game.window, (0 * 150) + 33,
		(0 * 64) + 21, 0, ("moves : "));
	mlx_string_put(vrs->game.init, vrs->game.window, (0 * 150) + 108,
		(0 * 64) + 21, 0, (s));
	free(s);
	ft_putstr_fd(YELLOW, 1);
	ft_putnbr(vrs->game.moves);
	ft_putstr_fd(RESET, 1);
	vrs->game.moves++;
	write(1, "\n", 1);
}
