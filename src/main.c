/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:34:17 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/04 19:01:03 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
	close(fd);
	fd = open(parse->file, O_RDONLY);
	if (fd == -1)
		return (0);
	return (1);
}

/* Remplis parse->content avec le contenu du fichier grace a GNL */
int	fill_content(t_parse *parse)
{
	int		i;
	char	*tmp;
	char	**content;

	if (!count_lines_in_file(parse->fd, parse))
		return (0);
	content = malloc(sizeof(char *) * (parse->lines + 1));
	if (!content)
		return (0);
	tmp = NULL;
	i = 0;
	tmp = get_next_line(parse->fd);
	while (i < parse->lines - 1)
	{
		tmp = ft_strjoin(tmp, get_next_line(parse->fd));
		if (!tmp)
			return (0);
		i++;
	}
	content = ft_split(tmp, '\n');
	if (!content)
		return (0);
	parse->content = content;
	free(tmp);
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
	return (1);
}

int	main(int ac, char **av)
{
	t_parse	parse;

	if (!parsing(ac, av, &parse))
		return (write(2, "Error\n", 6), 1);
	return (write(1, "tout est clair ☝️\n", 18), 0);
}
