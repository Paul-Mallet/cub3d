/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiquet <bfiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:20:57 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/12 13:35:46 by bfiquet          ###   ########.fr       */
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
		error_map(data);
	else
		len++;
	return (close (fd), len);
}

int	free_tab(char **tab)
{
	int	i;

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
