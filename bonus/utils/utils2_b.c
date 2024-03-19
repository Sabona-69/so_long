/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 00:07:01 by hel-omra          #+#    #+#             */
/*   Updated: 2024/03/02 12:10:27 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_b.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

int	ft_strlen_nl(char *s)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

int	ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char	*s)
{
	char	*s1;
	int		i;

	i = 0;
	s1 = malloc (ft_strlen(s) + 1);
	if (!s1)
		return (free(s), s = NULL);
	while (s[i])
	{
		s1[i] = s[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strjoin(char *s, char *buffer)
{
	char	*string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (ft_strdup(buffer));
	string = malloc(ft_strlen(s) + ft_strlen(buffer) + 1);
	if (!string)
		return (free(s), s = NULL);
	while (s[i])
	{
		string[i] = s[i];
		i++;
	}
	while (buffer[j])
	{
		string[i] = buffer[j];
		i++;
		j++;
	}
	string[i] = '\0';
	free(s);
	return (string);
}
