/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgrosven <kgrosven@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:58:45 by kgrosven          #+#    #+#             */
/*   Updated: 2024/01/11 10:54:53 by kgrosven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	char	*aux;
	size_t	i;

	aux = (char *)s;
	i = 0;
	while (i < n)
		aux[i++] = '\0';
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*aux;

	aux = malloc(count * size);
	if (!aux)
		return (NULL);
	ft_bzero(aux, count * size);
	return (aux);
}

char	*ft_strchr(const char *s, int c)
{
	char	*aux;

	aux = (char *)s;
	while (*aux != c && *aux != 0)
		aux++;
	if (*aux == c)
		return (aux);
	else
		return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	aux;

	if (!str)
		return (0);
	aux = 0;
	while (str[aux])
		aux++;
	return (aux);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*strjoin;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(str1) + ft_strlen(str2);
	strjoin = malloc(sizeof(char) * (len + 1));
	if (!strjoin)
		return (NULL);
	i = 0;
	while (str1 && str1[i])
	{
		strjoin[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2 && str2[j])
	{
		strjoin[i] = str2[j];
		i++;
		j++;
	}
	strjoin[len] = 0;
	return (strjoin);
}
