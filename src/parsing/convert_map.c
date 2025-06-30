/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 08:58:13 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/06/30 16:43:10 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void	print_map_int(t_data *data)
// {
// 	int	x;
// 	int	y;

// 	x = -1;
// 	while (++x < data->parsing.map_line_number)
// 	{
// 		y = -1;
// 		while (++y < data->parsing.map_col_number)
// 			printf("%d", data->parsing.map_int[x][y]);
// 		printf("\n");
// 	}
// }

// void	print_map_char(t_data *data)
// {
// 	int	x;
// 	int	y;

// 	x = -1;
// 	while (++x < data->parsing.map_line_number)
// 	{
// 		y = -1;
// 		while (++y < data->parsing.map_col_number)
// 			printf("%c", data->parsing.map[x][y]);
// 		printf("\n");
// 	}
// }

void	malloc_rows(t_data *data, int rows)
{
	data->parsing.map_int = (int **)malloc(rows * sizeof(int *));
	if (!data->parsing.map_int)
		handle_err("Error\nMalloc failed.\n", data);
}

void	malloc_cols(t_data *data, int rows, int cols)
{
	int	x;

	x = -1;
    while (++x < rows)
	{
		data->parsing.map_int[x] = (int *)malloc(cols * sizeof(int));
		if (!data->parsing.map_int[x])
			handle_err("Error\nMalloc failed.\n", data);
    }
}

// full fill empty(space already handle) in char** map;
// cause [x][y] try to access NULL value on shorter row's map
// = cubic / rect map
void	convert_map_to_int(t_data *data)
{
	int	x;
	int	y;
	int	rows;
	int	cols;
	int	char_cell;
	
	rows = data->parsing.map_line_number;
	cols = data->parsing.map_col_number;
	malloc_rows(data, rows);
	malloc_cols(data, rows, cols);
	x = -1;
	while (++x < rows)
	{
		y = -1;
		while (++y < cols)
		{
			char_cell = data->parsing.map[x][y];
			if (char_cell == 'N' || char_cell == 'S'
				|| char_cell == 'E' || char_cell == 'W')
				data->parsing.map_int[x][y] = 0;
			else
				data->parsing.map_int[x][y] = char_cell - '0';
		}
	}
}
