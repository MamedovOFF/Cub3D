/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:56:24 by spurple           #+#    #+#             */
/*   Updated: 2022/07/01 20:35:15 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "./cub3d.h"
# include <sys/errno.h>
# include <string.h>

# define FILE_TYPE ".cub"
# define CONFIG_INFO_FAILURE "Error\nInvalid configuration info."
# define MAP_FAILURE "Error\nInvalid map."
# define FILE_FORMAT_FAILURE "Error\nInvalid file format. Expected : *.cub"
# define TEXTURE_FORMAT_FAILURE\
		"Error\nInvalid texture file format. Expected : *.xpm"
# define NUMBER_ARGS_FAILURE "Error\nInvalid number of arguments! Excpected : 2."
# define NUMBER_CHAR_FAILURE\
		"Error\nInvalid map : wrong number of characters. Required : 1."
# define ALLOWED_SYMB_FAILURE\
		"Error\nInvalid map : unrecognized symbol. Allowed : \" 01WSNE\"."

# define TEXTURE_FORMAT ".xpm"

typedef struct s_parse
{
	int			config_count;
	int			status;
	int			fd_opened;
	int			fd;
	t_list		*input_data;
	t_list		*curent_data;
	t_cub		*cub;
	char		*trimmed_str;
	char		**splitted_str;
	void		(*config_init[6])(char *, struct s_parse *);
	char		**config_names;
}				t_parse;

void	init_no(char *path, t_parse *parse);
void	init_so(char *path, t_parse *parse);
void	init_we(char *path, t_parse *parse);
void	init_ea(char *path, t_parse *parse);
void	init_f(char *path, t_parse *parse);
void	init_c(char *path, t_parse *parse);
void	init_color(char *rgb, t_parse *parse, int	*color);
void	init_config(t_config *conf);
t_cub	*init_cub(t_parse *parse);

char	**make_map(char *arg);
void	valid_filename(int argc, char **argv);
void	clean_list(t_list *list);
void	exit_with_error_parse(char *error, t_parse *parse);
t_parse	*init_parse(void);
void	valid_config_str(char *str, t_parse *parse);
int		check_config(char **config, t_parse *parse);
void	set_config_funcs(t_parse *parse);
void	open_texture(char *path, t_parse *parse, t_texture **texture1);
int		parse_map(t_parse *parse);
void	clean_parse_inner(t_parse *parse);
char	**list_to2darr(t_list *list, t_parse *parse);
void	firstly_parse(char **map, t_parse *parse);
int		parse_int(char *str);
void	proc_symbol(char **map, int i, int j, t_parse *parse);
int		check_i(int i, t_parse *parse);
int		ends_with(char *input, char *postfix);
#endif