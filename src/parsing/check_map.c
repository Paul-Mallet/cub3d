/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiquet <bfiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:02:54 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/12 15:08:25 by bfiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	read_file(char *filename, t_data *data)
{
	int		j;
	int		i;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\n%sCan't read the file\n"), -1);
	j = count_lines(filename, data);
	if (j == -1)
		return (-1);
	data->file = malloc(sizeof(char *) * (j + 1));
	if (!data->file)
		return (-1);
	i = 0;
	while (i < j)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data->file[i] = ft_strdup(line);
		free(line);
		i++;
	}
	return (data->file[i] = NULL, close(fd), 0);
}

int	read_map(t_data *data, int i)
{
	int		j;
	char	*tmp;
	int		lines;

	j = 0;
	lines = data->file_line_number - i;
	data->map = malloc (sizeof(char *) * (lines + 1));
	if (!data->map)
		return (-1);
	while (data->file[i])
	{
		data->map[j] = ft_strdup(data->file[i]);
		tmp = data->map[j];
		data->map[j] = ft_strtrim(data->map[j], "\n");
		free(tmp);
		i++;
		j++;
	}
	data->map[j] = NULL;
	data->map_line_number = j;
	return (0);
}
