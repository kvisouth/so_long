/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:34:17 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/05 15:56:26 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	reset_get_next_line(t_parse *parse)
{
	close(parse->fd);
	parse->fd = open(parse->file, O_RDONLY);
	if (parse->fd == -1)
		return (0);
	return (1);
}

/* Check si notre argument finit par .ber */
int	parse_suffix(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 4] != '.'
		|| str[i - 3] != 'b'
		|| str[i - 2] != 'e'
		|| str[i - 1] != 'r')
		return (0);
	return (1);
}

/* Check si le fichier .ber saisi existe et est ouvrable */
int	parse_file_exist(char *str, t_parse *parse)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (0);
	parse->fd = fd;
	parse->file = str;
	return (1);
}

int	count_lines_in_file(int fd, t_parse *parse)
{
	int		line;

	line = 0;
	while (get_next_line(fd))
		line++;
	parse->lines = line;
	if (!reset_get_next_line(parse))
		return (0);
	return (1);
}

/* Remplis parse->content avec le contenu du fichier grace a GNL */
int	fill_content(t_parse *parse)
{
	int		i;
	char	**content;

	if (!count_lines_in_file(parse->fd, parse))
		return (0);
	content = malloc(sizeof(char *) * (parse->lines + 1));
	if (!content)
		return (0);
	i = 0;
	while (i < parse->lines)
	{
		content[i] = get_next_line(parse->fd);
		if (!content[i])
			return (0);
		i++;
	}
	if (!reset_get_next_line(parse))
		return (0);
	content[i] = NULL;
	parse->content = content;
	return (1);
}

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
	int len;

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

/* Initialise les variables p, c, e */
void	init_pce(t_parse *parse)
{
	parse->p = 0;
	parse->c = 0;
	parse->e = 0;	
}

/* Check les elements de la map (P, C, E) */
int	parse_pce(t_parse *parse)
{
	int	i;
	int	j;

	i = 0;
	init_pce(parse);
	while (i < parse->lines)
	{
		j = 0;
		while (parse->content[i][j])
		{
			if (parse->content[i][j] == 'P')
				parse->p++;
			if (parse->content[i][j] == 'C')
				parse->c++;
			if (parse->content[i][j] == 'E')
				parse->e++;
			j++;
		}
		i++;
	}
	if (parse->p != 1 || parse->c < 1 || parse->e != 1)
		return (0);
	return (1);
}

/* Check si il y a autre chose dans la map que les caracteres P, C, E, 1 et 0 */
int	parse_map_junk(t_parse *parse)
{
	int	i;
	int	j;

	i = 0;
	while (i < parse->lines)
	{
		j = 0;
		while (parse->content[i][j])
		{
			if (parse->content[i][j] != 'P'
				&& parse->content[i][j] != 'C'
				&& parse->content[i][j] != 'E'
				&& parse->content[i][j] != '1'
				&& parse->content[i][j] != '0'
				&& parse->content[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/* Parse les elements de la map (P, C, E, 1 et 0) */
int	parse_map_info(t_parse *parse)
{
	if (!parse_pce(parse))
		return (0);
	if (!parse_map_junk(parse))
		return (0);
	return (1);
}

int	parsing(int ac, char **av, t_parse *parse)
{
	if (ac != 2)
		return (0);
	if (!parse_suffix(av[1]))
		return (0);
	if (!parse_file_exist(av[1], parse))
		return (0);
	if (!fill_content(parse))
		return (0);
	if (!parse_map_walls(parse))
		return (0);
	if (!parse_map_info(parse))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_parse	parse;

	if (!parsing(ac, av, &parse))
		return (write(2, "Error\n", 6), 1);
	int i = 0;
	while (i < parse.lines)
	{
		printf("%s", parse.content[i]);
		i++;
	}
	return (0);
}
