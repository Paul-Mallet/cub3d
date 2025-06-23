#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../libft/libft/libft.h"
# include "../libft/printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_data
{
	void	*mlx;
	void	*window;
	char	**file;
	char	**map;
	int		file_line_number;
	int		map_line_number;
	int		map_col_number;
	int		color_c;
	int		color_f;
	int		player_count;
	char	*text_so;
	char	*text_no;
	char	*text_ea;
	char	*text_we;
	void	*img_so;
	void	*img_no;
	void	*img_ea;
	void	*img_we;
	char	*orientation;
}	t_data;

typedef struct s_fill_data
{
	char	**map;
	int		rows;
	int		cols;
}	t_fill_data;

int		read_file(char *filename, t_data *data);
int		check_format(char *argv);
int		check_letter(t_data *data);
int		count_lines(char *filename, t_data * data);
void	error_map(t_data *data);
int		check_char(char c);
int		get_color(t_data *data, char *line);
int		free_tab(char **tab);
int		verif_textures(t_data *data);
int		read_map(t_data *data, int i);
int		close_game(t_data *data);
int		check_player(t_data * data);
int		check_chars(char *str);
int		check_spaces(t_data *data);
int		check_walls(t_data *data);
void	get_orientation(t_data *data, char c);
int		count_cols(t_data *data);
int		get_textures_and_colors(t_data *data);
int		verif_values(t_data *data);
int		check_space(t_data *data, int i, int j);
int		check_duplicates(char identifier, t_data *data);
int		print_error(t_data *data);
int		check_player_char(char c);
int		check_player_surrounded(t_data *data);

#endif
