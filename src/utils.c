/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiquet <bfiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:59:38 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/27 11:17:12 by bfiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_textures_and_images(t_data *data)
{
	if (data->parsing.text_we)
		free(data->parsing.text_we);
	if (data->parsing.text_ea)
		free(data->parsing.text_ea);
	if (data->parsing.text_no)
		free(data->parsing.text_no);
	if (data->parsing.text_so)
		free(data->parsing.text_so);
	if (data->parsing.img_ea)
		mlx_destroy_image(data->mlx.mlx_co, data->parsing.img_ea);
	if (data->parsing.img_so)
		mlx_destroy_image(data->mlx.mlx_co, data->parsing.img_so);
	if (data->parsing.img_no)
		mlx_destroy_image(data->mlx.mlx_co, data->parsing.img_no);
	if (data->parsing.img_we)
		mlx_destroy_image(data->mlx.mlx_co, data->parsing.img_we);
	data->parsing.text_we = NULL;
	data->parsing.text_ea = NULL;
	data->parsing.text_no = NULL;
	data->parsing.text_so = NULL;
}

int	free_parsing(t_data *data)
{
	int	i;

	i = 0;
	if (data->parsing.orientation)
		free(data->parsing.orientation);
	free_textures_and_images(data);
	if (data->parsing.map)
		free_tab(data->parsing.map);
	if (data->parsing.map_int)
		free_tab(data->parsing.map_int);
	if (data->parsing.file)
		free_tab(data->parsing.file);
	exit(0);
	return (0);
}
