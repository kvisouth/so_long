/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:14:52 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/06 16:02:12 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* Libere la memoire allouee pour un tableau de char */
void	free_tabs(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

/* Compte le nombre de lignes dans le fichier */
int	count_lines_in_file(t_parse *parse)
{
	int		lines;
	char	*line;

	lines = 0;
	parse->fd = open(parse->file, O_RDONLY);
	if (parse->fd == -1)
		return (0);
	while (42)
	{
		line = get_next_line(parse->fd);
		if (!line)
			break ;
		lines++;
		free(line);
	}
	close(parse->fd);
	if (lines == 0)
		return (0);
	return (lines);
}

/* Remplis parse->content avec le contenu du fichier grace a GNL */
int	fill_content(t_parse *parse)
{
	int		i;
	char	**content;

	parse->lines = count_lines_in_file(parse);
	if (!parse->lines)
		return (0);
	content = malloc(sizeof(char *) * (parse->lines + 1));
	if (!content)
		return (0);
	i = 0;
	parse->fd = open(parse->file, O_RDONLY);
	if (parse->fd == -1)
		return (0);
	while (i < parse->lines)
	{
		content[i] = get_next_line(parse->fd);
		if (!content[i])
			return (free_tabs(content), 0);
		i++;
	}
	while (get_next_line(parse->fd))
		;
	content[i] = NULL;
	parse->content = content;
	return (close(parse->fd), 1);
}

/* Sers a afficher la map */
void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	printf("\n");
}
