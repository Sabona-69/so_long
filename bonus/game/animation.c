/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 00:16:37 by hel-omra          #+#    #+#             */
/*   Updated: 2024/03/19 02:10:18 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_b.h"

void	attack(t_elements *vrs, int i)
{
	int		k;

	k = 0;
	vrs->attack_m[0] = "textures/attack/0.xpm";
	vrs->attack_m[1] = "textures/attack/1.xpm";
	vrs->attack_m[2] = "textures/attack/2.xpm";
	vrs->attack_m[3] = "textures/attack/3.xpm";
	vrs->attack_m[4] = "textures/attack/4.xpm";
	vrs->attack_m[5] = "textures/attack/5.xpm";
	put_image(vrs, vrs->game.floor, vrs->player.x, vrs->player.y);
	while (k < 6)
	{
		vrs->attack[k] = xpm_to_image(vrs, vrs->attack_m[k]);
		usleep(150000);
		put_image(vrs, vrs->game.floor, vrs->enemy[i].x, vrs->enemy[i].y);
		put_image(vrs, vrs->attack[k], vrs->enemy[i].x, vrs->enemy[i].y);
		mlx_do_sync(vrs->game.init);
		k++;
	}
}

void	chest_idle(t_elements *vrs)
{
	static int		j;

	vrs->chest_m[0] = "textures/chest/0.xpm";
	vrs->chest_m[1] = "textures/chest/1.xpm";
	vrs->chest_m[2] = "textures/chest/2.xpm";
	vrs->chest_m[3] = "textures/chest/3.xpm";
	vrs->chest_m[4] = "textures/chest/4.xpm";
	if (j == 800)
	{
		j = 0;
		if (vrs->temp == 5)
			vrs->temp = 0;
		vrs->chest[vrs->temp] = xpm_to_image(vrs, vrs->chest_m[vrs->temp]);
		put_image(vrs, vrs->game.floor, vrs->exit.x, vrs->exit.y);
		put_image(vrs, vrs->chest[vrs->temp], vrs->exit.x, vrs->exit.y);
		vrs->temp++;
	}
	j++;
}
