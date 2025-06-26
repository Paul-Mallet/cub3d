/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiquet <bfiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:20:57 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/26 15:59:57 by bfiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_format(char *argv)
{
	size_t	i;

	i = ft_strlen(argv);
	i -= 4;
	if (argv[i] == '.' && argv[i + 1] == 'c'
		&& argv[i + 2] == 'u' && argv[i + 3] == 'b')
		return (1);
	return (0);
}

int	count_cols(t_data *data)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (j > max)
				max = j;
			j++;
		}
		i++;
	}
	return (max);
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
		return (ft_printf("Error\nCan't read the file\n"), -1);
	bit = 1;
	while (bit)
	{
		bit = read(fd, &c, 1);
		if (bit == -1)
			return (close (fd), ft_printf("Error\n"));
		if (c == '\n')
			len++;
	}
	if (bit != '\n' && bit != 0)
		len++;
	if (bit == '\n')
		error_map(data);
	return (close (fd), len);
}

int	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

void	error_map(t_data *data)
{
	int	j;

	j = -1;
	if (data->file)
		free_tab(data->file);
	if (data->map)
		free_tab(data->map);
	ft_printf("Error\nInvalid map\n");
	exit(0);
}
