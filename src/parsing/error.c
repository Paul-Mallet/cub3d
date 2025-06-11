/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiquet <bfiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:20:57 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/11 14:44:58 by bfiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_format(char *argv)
{
	size_t	i;

	i = ft_strlen(argv);
	i -= 4;
	if (argv[i] == '.' || argv[i + 1] == 'c'
		|| argv[i + 2] == 'u' || argv[i + 3] == 'b')
		return (1);
	return (0);
}

int	count_lines(char *filename, t_data *data)
{
	int		fd;
	char	c;
	int		len;
	int		bit;

	len = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\n%sCan't read the file\n"), -1);
	bit = 1;
	while (bit)
	{
		bit = read(fd, &c, 1);
		if (bit == -1)
			return (ft_printf("Error\n"));
		if (c == '\n')
			len++;
	}
	if (c == '\n')
		error_map(data, 0);
	else
		len++;
	return (close (fd), len);
}

int	check_char(char c)
{
	if (c == 'N' || c == '0' || c == '1' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	check_letter(t_data *data)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = data->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!check_char(map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	error_map(t_data *data, int i)
{
	int	j;

	j = -1;
	if (i == 1)
	{
		while (data->map[++j])
			free(data->map[j]);
		free(data->map);
	}
	ft_printf("Error\nInvalid map\n");
	exit(0);
}
