/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iu_scene.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaria-p <mfaria-p@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:34:37 by mfaria-p          #+#    #+#             */
/*   Updated: 2024/12/04 16:15:20 by mfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IU_SCENE_H
# define IU_SCENE_H

# include "../libft/libft/ft_printf.h"
# include "../libft/libft/get_next_line.h"
# include "../libft/libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define MOVE_FACTOR .1
# define ROT_FACTOR .001

# define XK_ESCAPE 0xff1b
# define XK_W 0x0077
# define XK_S 0x0073
# define XK_A 0x0061
# define XK_D 0x0064
# define XK_SPACE 0x0020
# define XK_SHIFT 0xffe1
# define XK_UP 0xff52
# define XK_DOWN 0xff54
# define XK_C 0x0063
# define XK_L 0x006c
# define XK_R 0x0072

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_data;
	int			bpp;
	int			size_line;
	int			endian;
	int			fd;
}				t_data;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_ambient
{
	float		ratio;
	t_color		color;
}				t_ambient;

typedef struct s_camerahe
{
	float		x;
	float		y;
	float		z;
	float		orient_x;
	float		orient_y;
	float		orient_z;
	float		fov;
}				t_camerahe;

typedef struct s_light
{
	float		x;
	float		y;
	float		z;
	float		brightness;
	t_color		color;
}				t_light;

typedef struct s_sphere
{
	float		x;
	float		y;
	float		z;
	float		diameter;
	t_color		color;
}				t_sphere;

typedef struct s_plane
{
	float		x;
	float		y;
	float		z;
	float		orient_x;
	float		orient_y;
	float		orient_z;
	t_color		color;
}				t_plane;

typedef struct s_cylinder
{
	float		x;
	float		y;
	float		z;
	float		orient_x;
	float		orient_y;
	float		orient_z;
	float		diameter;
	float		height;
	t_color		color;
}				t_cylinder;

typedef struct s_scenehe
{
	t_data		data;
	char		*line;
	char		**params;
	t_ambient	ambient;
	t_camerahe	camera;
	t_light		light;
	t_sphere	*spheres;
	int			sphere_count;
	t_plane		*planes;
	int			plane_count;
	t_cylinder	*cylinders;
	int			cylinder_count;
	int			camera_count;
	int			light_count;
	int			ambient_count;
}				t_scenehe;

// window related functions
void			open_window(t_scenehe *scene);

// error handling
void			is_invalid_file(t_scenehe *scene);
int				ft_error(char *str, t_scenehe *scene, int e);
void			clean_scene(t_scenehe *scene);
void			clean_data(t_data *data);
void			free_and_nullify(void **ptr);

// checks before parsing functions
void			check_ambient(const char *line, t_scenehe *scene);
void			check_camera(const char *line, t_scenehe *scene);
void			check_light(const char *line, t_scenehe *scene);
void			check_sphere(const char *line, t_scenehe *scene);
void			check_plane(const char *line, t_scenehe *scene);
void			check_cylinder(const char *line, t_scenehe *scene);
void			check_vector(char ***str, t_scenehe *scene, int j);
void			check_colors(char ***str, t_scenehe *scene, int j);

// scene parsing functions
void			process_line(char *line, t_scenehe *scene);
char			*cleanline(char *line, t_scenehe *scene);
void			check_element_type(char *clean_line, t_scenehe *scene);
void			parse_scene(const char *filename, t_scenehe *scene);
void			parse_ambient(const char *line, t_scenehe *scene);
void			parse_camera(const char *line, t_scenehe *scene);
void			parse_light(const char *line, t_scenehe *scene);
void			parse_sphere(const char *line, t_scenehe *scene);
void			parse_plane(const char *line, t_scenehe *scene);
void			parse_cylinder(const char *line, t_scenehe *scene);
void			parse_position(const char **line, t_cylinder *cylinder);
void			parse_orientation(const char **line, t_cylinder *cylinder,
					t_scenehe *scene);

// scene parsing utility functions
int				parse_int(const char **str);
float			parse_float(const char **str, int sign, float result);
void			skip_spaces(const char **str);
void			parse_color(const char **str, t_color *color, t_scenehe *scene);
void			*ft_realloc(void *ptr, size_t size);
void			*ft_memcpy(void *dest, const void *src, size_t n);
int				is_float(char *str);
int				is_int(char *str);
void			free_array(char *arr[]);
void			free_arrays(char ***str, char **nbrs);
int				array_length(char *arr[]);

// hooks
int				quit(void *param);
int				mouse_press_hook(int button, int x, int y, void *param);
int				scene_rotate(void *param);
int				mouse_release_hook(int button, int x, int y, void *param);
int				animate(void *param);
int				key_release_hook(int keycode, void *param);
int				key_press_hook(int keycode, void *param);
int				scene_translate(void *param);

#endif
