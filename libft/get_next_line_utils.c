/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:12:45 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/04 17:57:08 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Le meme ft_strjoin que la libft a la difference qu'il free 's1' a la fin */
char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	char	*ret;

	ret = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	k = 0;
	i = 0;
	while (s1[i])
		ret[k++] = s1[i++];
	j = 0;
	while (s2[j])
		ret[k++] = s2[j++];
	ret[k] = '\0';
	free((char *)s1);
	return (ret);
}

/* Coupe 'str' depuis '\n' et retourne ce qu'il y a apres. */
char	*ft_cutstr(char *str)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\n')
		i++;
	ret = malloc(ft_strlen(str) - i + 1);
	if (!ret)
		return (NULL);
	i++;
	while (str[i])
		ret[j++] = str[i++];
	ret[j] = '\0';
	free(str);
	return (ret);
}
