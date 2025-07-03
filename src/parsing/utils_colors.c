/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:56:29 by pamallet          #+#    #+#             */
/*   Updated: 2025/07/03 16:00:25 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_isspace(const char c)
{
	return (c == ' ');
}

int	check_before_rgb(char *line, int i)
{
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] && !ft_isdigit(line[i]) && ft_strcmp(&line[i], "\n"))
		return (printf("Error\nInvalid char detected in color\n"), -1);
	return (i);
}
