#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../libft/libft/libft.h"
# include "../libft/printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	char		**map;
	int			color_c;
	int			color_f;

	
}	t_data;

int		read_map(char *filename, t_data *data);
int		check_format(char *argv);
int		check_letter(t_data *data);
int		count_lines(char *filename, t_data *data);
void	error_map(t_data *data, int i);
int		check_char(char c);
int		get_color(t_data *data, char *line);

#endif