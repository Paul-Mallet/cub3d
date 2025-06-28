/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render_tex_gen.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:15:15 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/28 19:26:10 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	copy_texture_data(t_tex *tex,
	int texture_slot[TEX_HEIGHT*TEX_WIDTH])
{
	int	x;
	int	y;
	int	*pixel_data;
	int	pixel_color;

	pixel_data = (int *)tex->tex_addr;
	y = -1;
	while (++y < TEX_HEIGHT)
	{
		x = -1;
		while (++x < TEX_WIDTH)
		{
			pixel_color = pixel_data[((tex->tex_line_len / 4) * y) + x];
			texture_slot[TEX_WIDTH * y + x] = pixel_color;
		}
	}
}

void	load_image(t_data *data,
	int texture_slot[TEX_HEIGHT*TEX_WIDTH],
	char *pathname)
{
	int		tex_w;
	int		tex_h;
	t_tex	*tex;

	tex = &data->tex;
	tex->tex_img = mlx_xpm_file_to_image(data->mlx.mlx_co, pathname,
			&tex_w, &tex_h);
	if (!tex->tex_img)
	{
		printf("Failed to load texture: %s\ntex->tex_img: %p\n",
			pathname, tex->tex_img);
		return ;
	}
	tex->tex_addr = mlx_get_data_addr(tex->tex_img,
			&tex->tex_bpp, &tex->tex_line_len, &tex->tex_endian);
	copy_texture_data(tex, texture_slot);
	mlx_destroy_image(data->mlx.mlx_co, tex->tex_img);
}

// rm unused textures slots + resize TEX_NUM tests
void	generate_textures(t_data *data,
	int textures[TEX_NUM][TEX_HEIGHT*TEX_WIDTH])
{
	printf("ceiling: %d\n", data->parsing.color_c);
	printf("floor: %d\n", data->parsing.color_f);
	load_image(data, textures[0], data->parsing.text_ea);
	// load_colors, like part 1(RGB int value)

	// try to remove those unused textures
	load_image(data, textures[1], "./assets/bluestone.xpm");	//floor
	load_image(data, textures[2], "./assets/colorstone.xpm");	//ceiling
	load_image(data, textures[3], "./assets/barrel.xpm");
	load_image(data, textures[4], "./assets/eagle.xpm");
	load_image(data, textures[5], "./assets/bluestone.xpm");
	load_image(data, textures[6], "./assets/barrel.xpm");
	load_image(data, textures[7], "./assets/colorstone.xpm");
}
