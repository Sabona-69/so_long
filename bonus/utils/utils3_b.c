/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 02:11:48 by hel-omra          #+#    #+#             */
/*   Updated: 2024/03/19 03:20:35 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_b.h"

void	ft_putnbr(int n)
{
	if (n < 10)
	{
		n += 48;
		write(1, &n, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

char	*ft_itoa(int nbr)
{
	char	*new;
	int		i;
	int		j;

	i = 1;
	j = nbr;
	while ((j / 10) != 0)
	{
		i++;
		j /= 10;
	}
	new = malloc(i + 1);
	new[i] = '\0';
	i--;
	while (i >= 0)
	{
		new[i] = (nbr % 10) + 48;
		nbr /= 10;
		i--;
	}
	return (new);
}
