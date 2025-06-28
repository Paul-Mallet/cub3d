/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:49:41 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/28 19:09:20 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	verif_text_so(t_data *data)
{
	int	width;
	int	height;

	if (!data->parsing.text_so)
		return (ft_printf("No SOUTH texture found\n"), -1);
	data->parsing.img_so = mlx_xpm_file_to_image(data->mlx.mlx_co, data->parsing.text_so,
			&width, &height);
	if (!data->parsing.img_so)
	{
		printf("path not found for SOUTH texture\n");
		data->parsing.img_so = NULL;
		return (-1);
	}
	return (0);
}

int	verif_text_no(t_data *data)
{
	int	width;
	int	height;

	if (!data->parsing.text_no)
		return (ft_printf("No NORTH texture found\n"), -1);
	data->parsing.img_no = mlx_xpm_file_to_image(data->mlx.mlx_co, data->parsing.text_no,
			&width, &height);
	if (!data->parsing.img_no)
	{
		printf("path not found for NORTH texture\n");
		data->parsing.img_no = NULL;
		return (-1);
	}
	return (0);
}

int	verif_text_ea(t_data *data)
{
	int	width;
	int	height;

	if (!data->parsing.text_ea)
		return (ft_printf("No EAST texture found\n"), -1);
	printf("EAST texture: %s\n", data->parsing.text_ea);
	data->parsing.img_ea = mlx_xpm_file_to_image(data->mlx.mlx_co, data->parsing.text_ea,
			&width, &height);
	if (!data->parsing.img_ea)
	{
		printf("path not found for EAST texture: %s\n", data->parsing.text_ea);
		data->parsing.img_ea = NULL;
		return (-1);
	}
	return (0);
}

int	verif_text_we(t_data *data)
{
	int	width;
	int	height;

	if (!data->parsing.text_we)
		return (ft_printf("No WEST texture found\n"), -1);
	data->parsing.img_we = mlx_xpm_file_to_image(data->mlx.mlx_co, data->parsing.text_we,
			&width, &height);
	if (!data->parsing.img_we)
	{
		printf("path not found for WEST texture\n");
		data->parsing.img_we = NULL;
		return (-1);
	}
	return (0);
}

int	verif_textures(t_data *data)
{
	if (verif_text_ea(data) == -1 || verif_text_no(data) == -1
		|| verif_text_so(data) == -1 || verif_text_we(data) == -1)
		return (-1);
	return (0);
}
