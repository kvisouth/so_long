/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:14:24 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/05 16:52:02 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* Check si la map est fermee */
int	parse_map_closed(t_parse *parse)
{
	int	i;

	i = 0;
	while (parse->content[0][i] != '\n')
	{
		if (parse->content[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < parse->lines)
	{
		if ((parse->content[i][0] != '1')
			|| (parse->content[i][ft_strlen(parse->content[i]) - 2] != '1'))
			return (0);
		i++;
	}
	i = 0;
	while (parse->content[parse->lines - 1][i] != '\n')
	{
		if (parse->content[parse->lines - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

/* Check si la map est rectangle (Toutes les lignes sont de la meme longueur) */
int	parse_map_rectangle(t_parse *parse)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(parse->content[0]);
	while (i < parse->lines)
	{
		if ((int)ft_strlen(parse->content[i]) != len)
			return (0);
		i++;
	}
	if (parse->content[parse->lines] != NULL)
		return (0);
	return (1);
}

/* Check si la map est valide (La forme + si elle est fermee) */
int	parse_map_walls(t_parse *parse)
{
	if (!parse_map_rectangle(parse))
		return (0);
	if (!parse_map_closed(parse))
		return (0);
	return (1);
}
