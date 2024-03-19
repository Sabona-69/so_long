/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:28:27 by hel-omra          #+#    #+#             */
/*   Updated: 2024/03/19 04:04:22 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_elements	vrs;

	if (ac != 2)
		return (0);
	innit_t_elements(&vrs);
	map_parse(av[1], &vrs);
	create_game(&vrs);
}
