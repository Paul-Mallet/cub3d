/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiquet <bfiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:49:41 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/26 15:59:59 by bfiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	verif_text_so(t_data *data)
{
	int	width;
	int	height;

	if (!data->text_so)
		return (ft_printf("No SOUTH texture found\n"), -1);
	data->img_so = mlx_xpm_file_to_image(data->mlx, data->text_so,
			&width, &height);
	if (!data->img_so)
	{
		printf("path not found for SOUTH texture\n");
		data->img_so = NULL;
		return (-1);
	}
	return (0);
}

int	verif_text_no(t_data *data)
{
	int	width;
	int	height;

	if (!data->text_no)
		return (ft_printf("No NORTH texture found\n"), -1);
	data->img_no = mlx_xpm_file_to_image(data->mlx, data->text_no,
			&width, &height);
	if (!data->img_no)
	{
		printf("path not found for NORTH texture\n");
		data->img_no = NULL;
		return (-1);
	}
	return (0);
}

int	verif_text_ea(t_data *data)
{
	int	width;
	int	height;

	if (!data->text_ea)
		return (ft_printf("No EAST texture found\n"), -1);
	data->img_ea = mlx_xpm_file_to_image(data->mlx, data->text_ea,
			&width, &height);
	if (!data->img_ea)
	{
		printf("path not found for EAST texture\n");
		data->img_ea = NULL;
		return (-1);
	}
	return (0);
}

int	verif_text_we(t_data *data)
{
	int	width;
	int	height;

	if (!data->text_we)
		return (ft_printf("No WEST texture found\n"), -1);
	data->img_we = mlx_xpm_file_to_image(data->mlx, data->text_we,
			&width, &height);
	if (!data->img_we)
	{
		printf("path not found for WEST texture\n");
		data->img_we = NULL;
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
