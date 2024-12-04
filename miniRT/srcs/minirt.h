/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaria-p <mfaria-p@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:28:23 by ecorona-          #+#    #+#             */
/*   Updated: 2024/12/03 20:49:34 by mfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define CANVAS_PIXEL 600

# include "mlx.h"
# include "X11/X.h"
# include "../libft/libft/libft.h"
# include "laag.h"
# include "iu_scene.h"
# include <math.h>

// color vector have values between 0 and 1

typedef struct s_ray
{
	t_vector	origin;
	t_vector	direction;
}	t_ray;

typedef struct s_quadratic_root
{
	int		count;
	double	x1;
	double	x2;
}	t_roots;

// intensity is between [0,1]
typedef struct s_light_source
{
	t_vector	origin;
	float		intensity;
	t_vector	color;
}	t_light_source;

typedef struct s_phong
{
	t_vector	ambient;
	t_vector	diffuse;
	t_vector	specular;
}	t_phong;

// all properties are between [0,1]
typedef struct s_material
{
	t_vector	color;
	float		ambient;
	float		diffuse;
	float		specular;
	float		shine;
}	t_material;

enum e_shape_type
{
	SPHERE,
	CONE,
	CYLINDER,
	PLANE,
};

typedef struct s_shape
{
	int			type;
	t_vector	coefficients;
	double		height;
	double		constant;
	double		scale;
}	t_shape;

// translation is origin
typedef struct s_object
{
	t_shape			shape;
	t_material		material;
	t_vector		translation;
	struct	s_rotation
	{
		t_vector	axis;
		double		angle;
	}				rotation;
	t_vector		axis;
}	t_object;

// increment to reallocate for intersections array
// minimizing nbr of allocations
# define INTERSECTION_BUFFER_STEP 2048

typedef struct s_intersection 
{
	double		t;
	t_object	*obj;
}	t_intersection;

typedef	struct s_intersections
{
	t_intersection	*hit;
	size_t			size;
	t_intersection	*is;
}	t_intersections;

typedef struct s_hit
{
	t_intersection	i;
	t_vector		point;
	t_vector		normal;
	t_vector		eyev;
	int				is_inside;
}	t_hit;

// default camera origin
typedef struct s_camera
{
	double		scale;
	double		hsize;
	double		vsize;
	double		pixel_size;
	double		half_width;
	double		half_height;
	struct
	{
		t_vector	axis;
		double		angle;
	}			rotation;
	t_vector	origin;
	t_vector	axis;
	t_vector	left;
	t_vector	up;
	double		fov;
}	t_camera;

typedef struct s_img
{
	void	*img;
	char	*addr;
	void *mlx; 
    void *win;
	int		bpp;
	int		len;
	int		endian;
}	t_img;

typedef struct s_world
{
	t_vector		ray_origin;
	t_list			*objects;
	t_vector		ambient;
	t_light_source	light;
	t_img			*img;
	t_camera		camera;
	t_scenehe		*scene;
	t_vector		direction_rot;
	t_vector		direction_move;
	t_object        *selected_object;
	int				selected_light;
}	t_world;

typedef struct s_scene
{
	t_camera	*camera;
	t_world		*world;
	t_vector	tmp;
	void		*mlx_ptr;
	void		*mlx_win;
	t_img		*img;
}	t_scene;

/* ************************************************************************** */
// light.c
t_vector	vector_reflect(t_vector in, t_vector normal);
t_phong		lighting(t_material material, t_light_source light,t_vector point, t_vector eyev, t_vector normal, int shadow);
t_light_source	*light_translate(t_light_source *light, t_vector direction, double shift);
// interface:
t_light_source	light_init(t_vector xyz, t_vector rgb, double intensity);
/* ************************************************************************** */
// ray.c
t_vector	ray_position(t_ray ray, double t);
t_roots		quadratic_roots(double a, double b, double c);
t_roots		ray_object_intersect(t_ray ray, t_object object);
t_roots		ray_circle_intersect(t_ray ray, t_object object, double z);
t_roots		ray_plane_intersect(t_ray ray, t_object object, double z);
t_intersections	*ray_world_intersect(t_intersections *is, t_ray ray, volatile t_world *world);

/* ************************************************************************** */
// shape.c
t_shape		shape_sphere_create(void);
t_shape		shape_cylinder_create(void);
t_shape		shape_cone_create(void);
t_shape		shape_plane_create(void);
t_shape		*shape_scale(t_shape *shape, double scale);
t_vector	normal_at(t_vector p, t_object object);

/* ************************************************************************** */
// object.c
// interface:
t_object	*object_sphere_create(t_vector xyz, t_vector rgb, double d);
t_object	*object_cylinder_create(t_vector xyz, t_vector rgb, t_vector axis, double d, double h);
t_object	*object_plane_create(t_vector xyz, t_vector rgb, t_vector axis);
t_object	*object_cone_create(t_vector xyz, t_vector rgb, t_vector axis, double d, double h);
t_object	*object_height_new(t_object *obj, double height);
t_object	*object_coord_new(t_object *obj, t_vector coord);
t_object	*object_rot_new(t_object *obj, t_vector axis, double angle);
t_object	*object_coef_new(t_object *obj, t_vector new_coef);
t_object	*object_translate(t_object *obj, t_vector direction, double shift);
t_object	*object_rotate(t_object *obj, t_vector axis, double angle);
t_object	*object_scale(t_object *obj, double scale);
t_object	*object_select(volatile t_world *world, int x, int y);

/* ************************************************************************** */
// world.c
// interface:
volatile t_world		*world_object_add(volatile t_world *world, t_object *object);
void		world_destroy(volatile t_world *world);
volatile t_world		*world_init(volatile t_world *world);

/* ************************************************************************** */
// intersections.c
t_intersections	*intersections_roots_add(t_intersections *is, t_roots xs, t_object *obj);
t_intersections	*intersections_init(t_intersections *is);

/* ************************************************************************** */
// hit.c
t_hit		hit(t_intersection i, t_ray ray);
t_vector	shade_hit(volatile t_world *world, t_hit hit);
t_vector	color_at(volatile t_world *world, t_ray ray);

/* ************************************************************************** */
// camera.c
t_ray		ray_for_pixel(t_camera *camera, int x, int y);
t_img		*render(t_img *img, t_camera *camera, volatile t_world *world);
// interface:
t_camera	init_camera2(t_scenehe *scene);
t_camera	*camera_rescale(t_camera *camera, double new_scale);
t_camera	*camera_coord_new(t_camera *camera, t_vector coord);
t_camera	*camera_rot_new(t_camera *camera, t_vector axis, double angle);
t_camera	*camera_translate(t_camera *camera, t_vector direction, double shift);
t_camera	*camera_rotate(t_camera *camera, t_vector axis, double angle);

//render scene
void render_scene(t_scenehe *scene, volatile t_world *world);

t_img	img_init(t_data *data);
void init_scene(t_scenehe *scene);
void            handle_scaling(int keycode, t_object *object);
void            handle_movement(int keycode, t_world *world, t_camera camera);
#endif
