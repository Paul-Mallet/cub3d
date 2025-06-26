/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiquet <bfiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:58:24 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/26 16:47:50 by bfiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_duplicates(char identifier, t_data *data)
{
	if (identifier == 'C' && data->parsing.color_c != -1)
		return (printf("Error: Duplicate ceiling color\n"), 1);
	else if (identifier == 'F' && data->parsing.color_f != -1)
		return (printf("Error: Duplicate floor color\n"), 1);
	return (0);
}

int	verif_values(t_data *data)
{
	if (data->parsing.color_c == -1 || data->parsing.color_f == -1)
		return (0);
	if (!data->parsing.text_ea || !data->parsing.text_we
		|| !data->parsing.text_no || !data->parsing.text_so)
		return (0);
	return (1);
}

int	print_error(t_data *data)
{
	if (data->parsing.color_c == -1)
		return (printf("Error: ceiling color not found\n"), 1);
	if (data->parsing.color_f == -1)
		return (printf("Error: floor color not found\n"), 1);
	if (!data->parsing.text_no)
		return (printf("Error: north texture not found\n"), 1);
	if (!data->parsing.text_so)
		return (printf("Error: south texture not found\n"), 1);
	if (!data->parsing.text_ea)
		return (printf("Error: east texture not found\n"), 1);
	if (!data->parsing.text_we)
		return (printf("Error: west texture not found\n"), 1);
	return (0);
}
