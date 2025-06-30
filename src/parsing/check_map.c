/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:02:54 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/30 18:51:42 by pamallet         ###   ########.fr       */
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
	data->parsing.file = malloc(sizeof(char *) * (j + 1));
	if (!data->parsing.file)
		return (-1);
	i = 0;
	while (i < j)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data->parsing.file[i] = ft_strdup(line);
		free(line);
		i++;
	}
	return (data->parsing.file[i] = NULL, close(fd), 0);
}

// read + fill map here
// find a way to strdup + fill while < max_cols_len
int	read_map(t_data *data, int i)
{
	int		j;
	char	*tmp;
	int		lines;

	j = 0;
	lines = data->parsing.file_line_number - i;
	data->parsing.map = (char **)malloc(sizeof(char *) * (lines + 1));
	if (!data->parsing.map)
		return (-1);
	while (data->parsing.file[i])
	{
		if (!ft_strcmp(data->parsing.file[i], "\n")
			|| !ft_strchr(data->parsing.file[i], '1'))
			break ;
		data->parsing.map[j] = ft_strdup(data->parsing.file[i]);
		tmp = data->parsing.map[j];
		data->parsing.map[j] = ft_strtrim(data->parsing.map[j], "\n");
		free(tmp);
		i++;
		j++;
	}
	data->parsing.map[j] = NULL;
	data->parsing.map_line_number = j;
	return (0);
}
