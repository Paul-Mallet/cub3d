/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiquet <bfiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:59:38 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/26 16:00:05 by bfiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_textures_and_images(t_data *data)
{
	if (data->text_we)
		free(data->text_we);
	if (data->text_ea)
		free(data->text_ea);
	if (data->text_no)
		free(data->text_no);
	if (data->text_so)
		free(data->text_so);
	if (data->img_ea)
		mlx_destroy_image(data->mlx, data->img_ea);
	if (data->img_so)
		mlx_destroy_image(data->mlx, data->img_so);
	if (data->img_no)
		mlx_destroy_image(data->mlx, data->img_no);
	if (data->img_we)
		mlx_destroy_image(data->mlx, data->img_we);
	data->text_we = NULL;
	data->text_ea = NULL;
	data->text_no = NULL;
	data->text_so = NULL;
}

int	close_game(t_data *data)
{
	int	i;

	i = 0;
	if (data->orientation)
		free(data->orientation);
	free_textures_and_images(data);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	if (data->map)
		free_tab(data->map);
	if (data->file)
		free_tab(data->file);
	exit(0);
	return (0);
}
