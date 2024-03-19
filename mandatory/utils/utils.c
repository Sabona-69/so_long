/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 23:07:18 by hel-omra          #+#    #+#             */
/*   Updated: 2024/02/27 00:12:08 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && i < n && s1[i] && s2[i])
		i++;
	if (i == n)
		return (0);
	return (1);
}

int	ft_count(char const *s, char sep)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == sep)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && s[i] != sep)
			i++;
	}
	return (count);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char				*new;
	unsigned int		i;
	int					j;

	i = 0;
	j = 0;
	new = malloc (len + 1);
	if (!new)
		return (NULL);
	while (i++ < start)
		j++;
	i = 0;
	while (s[start] && start < len + j)
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}

char	**ft_split(char *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	str = (char **)malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	k = 0;
	while (k < ft_count(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		str[k] = ft_substr(s, j, i - j);
		if (str[k++] == NULL)
			return ((char **)ft_free2d(str, k - 1));
	}
	str[ft_count(s, c)] = NULL;
	return (str);
}
