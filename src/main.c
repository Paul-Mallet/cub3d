/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiquet <bfiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:59:24 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/11 12:52:55 by bfiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		fd;

	printf("test\n");
	if (argc != 2)
		return (printf("Error : invalid arguments"));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nInvalid argument\n"));
	printf("test\n");
	if (!check_format(argv[1]))
	{
		ft_printf("Error\nInvalid file\n");
		return (1);
	}
	printf("test\n");
	read_map(argv[1], &data);
	int i = 0;
	while (ft_strncmp(data.map[i], "C", 1) != 0)
	{
		i++;
		printf("%d\n", i);
	}
	printf("test\n");
	get_color(&data, data.map[i]);
	printf("test %d\n", data.color_c);
	if (!check_letter(&data))
		return (error_map(&data, 1), 1);
	
}
