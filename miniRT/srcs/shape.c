/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:07:22 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/18 12:38:37 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*typedef struct s_shape*/
/*{*/
/*	const struct	s_parameters*/
/*	{*/
/*		e_shape_type	type;*/
/*		t_vector		coefficients;*/
/*		t_vector		shift;*/
/*		double			constant;*/
/*	}					parameters;*/
/*	double				scale;*/
/*	t_matrix			transform;*/
/*}	t_shape;*/

t_shape	sphere(void)
{
	t_shape	ret = {{SPHERE, (t_vector){1,1,1}, (t_vector){0,0,0}, 1}, 1, (t_matrix){{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}}};

	return (ret);
}

t_shape	cylinder(void)
{
	t_shape	ret = {{CONE, (t_vector){1,1,0}, (t_vector){0,0,0}, 1}, 1, (t_matrix){{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}}};

	return (ret);
}

t_shape	cone(void)
{
	t_shape	ret = {{CONE, (t_vector){1,1,-1}, (t_vector){0,0,1}, 0}, 1, (t_matrix){{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}}};

	return (ret);
}

t_vector	normal_at(t_vector p, t_object object)
{
	t_shape		shape;
	t_vector	ret;

	shape = object.shape;
	p = vector_subtract(p, object.translation);
	p = vector_rotate(p, object.rotation.axis, -object.rotation.angle);
}
