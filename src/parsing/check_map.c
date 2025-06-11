/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiquet <bfiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:02:54 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/11 11:12:42 by bfiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	read_map(char *filename, t_data *data)
{
	int		j;
	int		i;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd <= -1)
		return (ft_printf("Error\n%sCan't read the file\n"), -1);
	j = count_lines(filename, data);
	if (j == -1)
		return (-1);
	i = 0;
	while (i < j)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data->map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	return (close (fd), 0);
}
