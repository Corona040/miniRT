/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:13:18 by ecorona-          #+#    #+#             */
/*   Updated: 2024/12/12 11:37:23 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	ray_position(t_ray ray, double t)
{
	return (vec_add(ray.origin, vec_scalar_prod(t, ray.dir)));
}

t_roots	quadratic_roots(double a, double b, double c)
{
	double	delta;
	double	x1;
	double	x2;

	if (a == 0)
		return ((t_roots){0, 0, 0});
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return ((t_roots){0, 0, 0});
	else if (delta == 0)
	{
		x1 = -b / (2 * a);
		return ((t_roots){1, x1, x1});
	}
	x1 = (-b - sqrtf(delta)) / (2 * a);
	x2 = (-b + sqrtf(delta)) / (2 * a);
	return ((t_roots){2, x1, x2});
}

t_roots	ray_plane_intersect(t_ray ray, t_obj obj, double z)
{
	double		t;

	ray.origin = vec_subtract(ray.origin, obj.translation);
	ray.origin = vec_rotate_ax(ray.origin, obj.rotation.axis, -obj.rotation.angle);
	ray.dir = vec_rotate_ax(ray.dir, obj.rotation.axis, -obj.rotation.angle);
	t = (z - ray.origin.z) / ray.dir.z;
	return ((t_roots){1, t, t});
}

t_roots	ray_obj_intersect(t_ray ray, t_obj obj)
{
	t_shape	shape;
	double	abc[3];
	t_roots	xs;
	t_vec	p;

	shape = obj.shape;
	if (shape.type == PLANE)
		return (ray_plane_intersect(ray, obj, 0));
	ray.origin = vec_subtract(ray.origin, obj.translation);
	ray.origin = vec_rotate_ax(ray.origin, obj.rotation.axis, -obj.rotation.angle);
	ray.dir = vec_rotate_ax(ray.dir, obj.rotation.axis, -obj.rotation.angle);
	abc[0] = vec_dot_prod(shape.coef, vec_elem_prod(ray.dir, ray.dir));
	abc[1] = 2 * vec_dot_prod(shape.coef, vec_elem_prod(ray.origin, ray.dir));
	abc[2] = vec_dot_prod(shape.coef, vec_elem_prod(ray.origin, ray.origin));
	abc[2] -= shape.constant;
	xs = quadratic_roots(abc[0], abc[1], abc[2]);
	p = ray_position(ray, xs.x1);
	if (obj.shape.height > 0 && \
		(p.z > obj.shape.height / 2 || p.z < -obj.shape.height / 2))
		xs.x1 = -1;
	p = ray_position(ray, xs.x2);
	if (obj.shape.height > 0 \
		&& (p.z > obj.shape.height / 2 || p.z < -obj.shape.height / 2))
		xs.x2 = -1;
	return (xs);
}

t_touches	*ray_world_hits(t_touches *is, t_ray ray, t_world *world)
{
	t_roots	xs;
	t_list	*obj;

	obj = world->objs;
	while (obj)
	{
		xs = ray_obj_intersect(ray, *(t_obj *)obj->content);
		is = touches_roots_add(is, xs, obj->content);
		obj = obj->next;
	}
	return (is);
}
