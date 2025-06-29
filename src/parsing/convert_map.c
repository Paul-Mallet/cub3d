/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 08:58:13 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/06/29 18:12:06 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	malloc_cols(t_data *data, int rows, int cols)
{
	int	x;

	x = -1;
    while (++x < rows)
	{
		data->parsing.map_int[x] = (int *)malloc(cols * sizeof(int));
		if (!data->parsing.map_int[x])
			handle_err("malloc failed.\n", data);
    }
}

void	print_map_int(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	printf("data->parsing.map_line_number: %d\n"
		"data->parsing.map_col_number: %d\n",
		data->parsing.map_line_number,
		data->parsing.map_col_number);
	while (++x < data->parsing.map_line_number)
	{
		y = -1;
		while (++y < data->parsing.map_col_number)
			printf("%d", data->parsing.map_int[x][y]);
		printf("\n");
	}
}

void	print_map_char(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	while (++x < data->parsing.map_line_number)
	{
		y = -1;
		while (++y < data->parsing.map_col_number)
			printf("%c", data->parsing.map[x][y]);
		printf("\n");
	}
}

void	convert_map_to_int(t_data *data)
{
	int	x;
	int	y;
	int	rows;
	int	cols;
	int	char_cell;
	
	// think to free data->parsing.map_int at each render of hooks call
	// change all map by map_int in exec
	// int[x][y] with 0(space), 1(walls), 2(empty), N,S,E,W(setup player.dirs, then convert to 0 -> space)
	rows = data->parsing.map_line_number;
	cols = data->parsing.map_col_number;
	data->parsing.map_int = (int **)malloc(rows * sizeof(int *));
	if (!data->parsing.map_int)
		handle_err("malloc failed.\n", data); // exit() allowed
	malloc_cols(data, rows, cols);

	//check if correct [x][y] or [y][x]
	x = -1;
	while (++x < rows)
	{
		y = -1;
		while (++y < cols)
		{
			char_cell = data->parsing.map[x][y];
			// treat NSEW as space in the map to avoid bugs
			// where is NSEW = player.pos_x, pos_y & player.dir_x, dir_y
			if (char_cell == 'N' || char_cell == 'S'
				|| char_cell == 'E' || char_cell == 'W')
				data->parsing.map_int[x][y] = 0;
			else
				data->parsing.map_int[x][y] = char_cell - '0';
		}
	}
}
