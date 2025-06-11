/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiquet <bfiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:59:24 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/11 14:50:44 by bfiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (printf("Error : invalid arguments\n"));
	if (!check_format(argv[1]))
	{
		ft_printf("Error\nInvalid file\n");
		return (1);
	}
	data.color_c = -1;
	data.color_f = -1;
	read_map(argv[1], &data);
	int i = 0;
	while (ft_strncmp(data.map[i], "C", 1) != 0)
		i++;
	get_color(&data, data.map[i]);
	if (!check_letter(&data))
		return (error_map(&data, 1), 1);
	
}
