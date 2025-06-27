/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 08:58:13 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/06/27 09:48:01 by paul_mallet      ###   ########.fr       */
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
			handle_error(data);
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
		handle_error(data); // exit() allowed
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
