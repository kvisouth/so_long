/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:15:29 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/05 17:52:56 by kevisout         ###   ########.fr       */
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
	close(fd);
	parse->file = str;
	return (1);
}

int	parse_args(char **str, t_parse *parse)
{
	if (!parse_suffix(str[1]))
		return (0);
	if (!parse_file_exist(str[1], parse))
		return (0);
	return (1);
}
