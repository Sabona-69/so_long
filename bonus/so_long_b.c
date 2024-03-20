/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:28:27 by hel-omra          #+#    #+#             */
/*   Updated: 2024/03/20 15:20:14 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_b.h"

int	main(int ac, char **av)
{
	t_elements	vrs;

	if (ac != 2)
		return (0);
	innit_t_elements(&vrs);
	map_parse(av[1], &vrs);
	enemy_position(vrs.map, &vrs);
	create_game(&vrs);
}
