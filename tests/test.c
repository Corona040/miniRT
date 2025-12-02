/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:52:23 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/14 13:26:19 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int  double_equals_00(void);
int  double_equals_01(void);
int  double_equals_02(void);
int  double_equals_03(void);
int  vec_equals_00(void);
int  vec_equals_01(void);
int  vec_scalar_prod_00(void);
int  vec_scalar_prod_01(void);
int  vec_scalar_prod_02(void);
int  vec_add_00(void);
int  vec_add_01(void);
int  vec_subtract_00(void);
int  vec_subtract_01(void);
int  vec_dot_prod_00(void);
int  vec_dot_prod_01(void);
int  vec_magnitude_00(void);
int  vec_magnitude_01(void);
int  vec_distance_00(void);
int  vec_distance_01(void);
int  vec_normalize_00(void);
int  vec_normalize_01(void);
int  vec_cross_prod_00(void);
int  vec_cross_prod_01(void);
int  vec_cosine_00(void);
int  vec_cosine_01(void);
int  vec_scalar_proj_00(void);
int  vec_scalar_proj_01(void);
int  vec_proj_00(void);
int  vec_proj_01(void);
int  vec_proj_02(void);
int  vec_plane_proj_00(void);
int  vec_plane_proj_01(void);
int  vec_rotate_ax_00(void);
int  mat_equals_00(void);
int  mat_equals_01(void);
int  mat_equals_02(void);
int  mat_scalar_prod_00(void);
int  mat_add_00(void);
int  mat_subtract_00(void);
int  mat_prod_00(void);
int  mat_prod_01(void);
int  mat_prod_02(void);
int  mat_vec_prod_00(void);
int  mat_vec_prod_01(void);
int  mat_vec_prod_02(void);
int  mat_vec_prod_03(void);
int  mat_transpose_00(void);
int  mat_transpose_01(void);
int  mat_transpose_02(void);
int  mat_determinant_00(void);
int  mat_determinant_01(void);
int  mat_determinant_02(void);
int  mat_determinant_03(void);
int  mat_cofactor_00(void);
int  mat_minor_00(void);
int  mat_adjoint_00(void);
int  mat_inverse_00(void);
int  mat_inverse_01(void);
int  mat_inverse_02(void);
int  quadratic_roots_00(void);
int  quadratic_roots_01(void);
int  quadratic_roots_02(void);
int  quadratic_roots_03(void);
int  quadratic_roots_04(void);
int  ray_position_00(void);
int  ray_position_01(void);
int  ray_position_02(void);
int  ray_sphere_intersect_00(void);
int  ray_sphere_intersect_01(void);
int  ray_sphere_intersect_02(void);
int  ray_sphere_intersect_03(void);
int  ray_sphere_intersect_04(void);

int  tests_run = 0;
suite  tests_laag = {
          double_equals_00, double_equals_01, double_equals_02, double_equals_03,
          vec_equals_00, vec_equals_01,
          vec_scalar_prod_00, vec_scalar_prod_01, vec_scalar_prod_02,
          vec_add_00, vec_add_01,
          vec_subtract_00, vec_subtract_01,
          vec_dot_prod_00, vec_dot_prod_01,
          vec_magnitude_00, vec_magnitude_01,
          vec_distance_00, vec_distance_01,
          vec_normalize_00, vec_normalize_01,
          vec_cross_prod_00, vec_cross_prod_01,
          vec_cosine_00, vec_cosine_01,
          vec_scalar_proj_00, vec_scalar_proj_01,
          vec_proj_00, vec_proj_01, vec_proj_02,
          vec_plane_proj_00, vec_plane_proj_01,
          vec_rotate_ax_00,
          mat_equals_00, mat_equals_01, mat_equals_02,
          mat_scalar_prod_00,
          mat_add_00,
          mat_subtract_00,
          mat_prod_00, mat_prod_01, mat_prod_02,
          mat_vec_prod_00, mat_vec_prod_01, mat_vec_prod_02, mat_vec_prod_03,
          mat_transpose_00, mat_transpose_01, mat_transpose_02,
          mat_determinant_00, mat_determinant_01, mat_determinant_02, mat_determinant_03,
          mat_cofactor_00,
          mat_minor_00,
          mat_adjoint_00,
          mat_inverse_00, mat_inverse_01, mat_inverse_02,
          NULL
        };

suite  tests_ray = {
          quadratic_roots_00, quadratic_roots_01, quadratic_roots_02, quadratic_roots_03, quadratic_roots_04,
          ray_position_00, ray_position_01, ray_position_02,
          ray_sphere_intersect_00, ray_sphere_intersect_01, ray_sphere_intersect_02, ray_sphere_intersect_03, ray_sphere_intersect_04,
          NULL
        };

t_vec  vec_print(t_vec v)
{
  printf("%f\t", v.x);
  printf("%f\t", v.y);
  printf("%f\t", v.z);
  printf("\n");
  return (v);
}

t_quat  quat_print(t_quat q)
{
  printf("%f\t", q.w);
  printf("%f\t", q.i);
  printf("%f\t", q.j);
  printf("%f\t", q.k);
  printf("\n");
  return (q);
}

t_mat  mat_print(t_mat  m)
{
  for (int i = 0; i < MATRIX_SIZE; i++)
  {
    if (i % 3 == 0)
      printf("\n");
    printf("%f\t", ((double *)m.mat)[i]);
  }
  printf("\n");
  return (m);
}

int  double_equals_00(void)
{
  _ft_assert(double_equals(0, 1e-11));
  return (SUCCESS);
}

int  double_equals_01(void)
{
  _ft_assert(!double_equals(0, 1));
  return (SUCCESS);
}

int  double_equals_02(void)
{
  _ft_assert(!double_equals(1.001, 1.002));
  return (SUCCESS);
}

int  double_equals_03(void)
{
  _ft_assert(double_equals(1.00000000000000001, 1.00000000000000002));
  return (SUCCESS);
}

int  vec_equals_00(void)
{
  t_vec  u = {1, 8, 9};

  _ft_assert(vec_equals(u,u));
  return (SUCCESS);
}

int  vec_equals_01(void)
{
  t_vec  u = {1, 2, 3};
  t_vec  v = {1, 2, 1};

  _ft_assert(!vec_equals(u,v));
  return (SUCCESS);
}

int  vec_scalar_prod_00(void)
{
  t_vec  u = {3, 54, 2};
  int      n = 7;
  t_vec  result = {n * 3, n * 54, n * 2};

  _ft_assert(vec_equals(vec_scalar_prod(n, u), result));
  return (SUCCESS);
}

int  vec_scalar_prod_01(void)
{
  t_vec  u = {3, 54, 2};
  int      n = 1;

  _ft_assert(vec_equals(vec_scalar_prod(n, u), u));
  return (SUCCESS);
}

int  vec_scalar_prod_02(void)
{
  t_vec  u = {3, 54, 2};
  int      n = 0;

  _ft_assert(vec_equals(vec_scalar_prod(n, u), (t_vec){0, 0, 0}));
  return (SUCCESS);
}

int  vec_add_00(void)
{
  t_vec  u = {1, 3, 5};
  t_vec  v = {5, 3, 1};

  _ft_assert(vec_equals(vec_add(u, v), (t_vec){6, 6, 6}));
  return (SUCCESS);
}

int  vec_add_01(void)
{
  t_vec  u = {-1, 3, -5};
  t_vec  v = {5, 3, 1};

  _ft_assert(vec_equals(vec_add(u, v), (t_vec){4, 6, -4}));
  return (SUCCESS);
}

int  vec_subtract_00(void)
{
  t_vec  u = {-1, 3, -5};
  t_vec  v = {5, 3, 1};

  _ft_assert(vec_equals(vec_subtract(u, v), (t_vec){-6, 0, -6}));
  return (SUCCESS);
}

int  vec_subtract_01(void)
{
  t_vec  u = {-1, 3, -5};

  _ft_assert(vec_equals(vec_subtract(u, u), (t_vec){0, 0, 0}));
  return (SUCCESS);
}

int  vec_dot_prod_00(void)
{
  t_vec  u = {-1, 3, -5};

  _ft_assert(vec_dot_prod(u, u) == 35);
  return (SUCCESS);
}

int  vec_dot_prod_01(void)
{
  t_vec  u = {1, 10, 2};
  t_vec  v = {1, 10, 9};

  _ft_assert(vec_dot_prod(u, v) == 119);
  return (SUCCESS);
}

int  vec_magnitude_00(void)
{
  t_vec  u = {1, 1, 1};

  _ft_assert(double_equals(vec_magnitude(u), sqrt(3)));
  return (SUCCESS);
}

int  vec_magnitude_01(void)
{
  t_vec u = {0, 0, 0};

  _ft_assert(double_equals(vec_magnitude(u), 0));
  return (SUCCESS);
}

int  vec_distance_00(void)
{
  t_vec  u = {0, 0, 0};
  t_vec  v = {0, 1, 1};

  _ft_assert(double_equals(vec_distance(u, v), sqrt(2)));
  return (SUCCESS);
}

int  vec_distance_01(void)
{
  t_vec  u = {1, 0, 2};

  _ft_assert(double_equals(vec_distance(u, u),0));
  return (SUCCESS);
}

int  vec_normalize_00(void)
{
  t_vec  u = {0, 0, 0};
  
  _ft_assert(vec_equals(vec_normalize(u), (t_vec){0, 0, 0}));
  return (SUCCESS);
}

int  vec_normalize_01(void)
{
  t_vec  u = {1, 1, 1};
  
  _ft_assert(vec_equals(vec_normalize(u), (t_vec){1 / sqrt(3), 1 / sqrt(3), 1 / sqrt(3)}));
  return (SUCCESS);
}

int  vec_cross_prod_00(void)
{
  t_vec  u = {1, 2, 3};
  t_vec  v = {8, .5, 10};

  _ft_assert(vec_equals(vec_cross_prod(u, v), (t_vec){18.5, 14, -15.5}));
  return (SUCCESS);
}

int  vec_cross_prod_01(void)
{
  t_vec  u = {0, 0, 0};
  t_vec  v = {6, 7, 3};

  _ft_assert(vec_equals(vec_cross_prod(u, v), (t_vec){0, 0, 0}));
  return (SUCCESS);
}

int  vec_cosine_00(void)
{
  t_vec  u = {0, 0, 0};

  _ft_assert(double_equals(vec_cosine(u, u), 0));
  return (SUCCESS);
}

int  vec_cosine_01(void)
{
  t_vec  u = {1, 1, 0};
  t_vec  v = {0, 1, 0};

  _ft_assert(double_equals(vec_cosine(u, v), .5 * sqrt(2)));
  return (SUCCESS);
}

int  vec_scalar_proj_00(void)
{
  t_vec  u = {1, 3, 1};
  t_vec  v = {0, .5, 0};

  _ft_assert(double_equals(vec_scalar_proj(u, v), 3));
  return (SUCCESS);
}

int  vec_scalar_proj_01(void)
{
  t_vec  u = {1, 3, 1};
  t_vec  v = {0, .5, 0};

  _ft_assert(double_equals(vec_scalar_proj(v, u), 0.452267016866645));
  return (SUCCESS);
}

int  vec_proj_00(void)
{
  t_vec  u = {0, 0, 0};
  t_vec  v = {0, 0, 0};

  _ft_assert(vec_equals(vec_proj(u, v), (t_vec){0, 0, 0}));
  return (SUCCESS);
}

int  vec_proj_01(void)
{
  t_vec  u = {1, 3, 5};
  t_vec  v = {0, 0, 0};

  _ft_assert(vec_equals(vec_proj(u, v), (t_vec){0, 0, 0}));
  return (SUCCESS);
}

int  vec_proj_02(void)
{
  t_vec  u = {1, 3, 5};
  t_vec  v = {0, 0, .1};

  _ft_assert(vec_equals(vec_proj(u, v), (t_vec){0, 0, 5}));
  return (SUCCESS);
}

int  vec_plane_proj_00(void)
{
  t_vec  u = {1, 3, 5};
  t_vec  n = {0, 1, 0};

  _ft_assert(vec_equals(vec_plane_proj(u, n), (t_vec){1, 0, 5}));
  return (SUCCESS);
}

int  vec_plane_proj_01(void)
{
  t_vec  u = {1, 3, 5};
  t_vec  n = {0, .5, 2};

  _ft_assert(vec_equals(vec_plane_proj(u, n), (t_vec){1, 1.64705882353, -0.41176470588}));
  return (SUCCESS);
}

int  vec_rotate_ax_00(void)
{
  t_vec  u = {1, 1, 1};
  t_vec  ax = {-1, 1, 0};

  _ft_assert(vec_equals(vec_rotate_ax(u, ax, M_PI), (t_vec){-1, -1, -1}));
  return (SUCCESS);
}

int  mat_equals_00(void)
{
  t_mat  m = {{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}};

  _ft_assert(mat_equals(m, m));
  return (SUCCESS);
}

int  mat_equals_01(void)
{
  t_mat  m = {{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}};
  t_mat  n = {{{1, 1, 1}, {1, 1, 1}, {1, 3, 1}}};

  _ft_assert(!mat_equals(m, n));
  return (SUCCESS);
}

int  mat_equals_02(void)
{
  _ft_assert(mat_equals(mat_identity(), mat_identity()));
  return (SUCCESS);
}

int  mat_scalar_prod_00(void)
{
  t_mat  m = {{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}};
  t_mat  n = {{{3, 3, 3}, {3, 3, 3}, {3, 3, 3}}};

  _ft_assert(mat_equals(mat_scalar_prod(3, m), n));
  return (SUCCESS);
}

int  mat_add_00(void)
{
  t_mat  m = {{{1, 1, -1}, {.1, .5, 1.9}, {100, 0, 0}}};
  t_mat  n = {{{-1, 1, -1}, {-.2, .5, -1.9}, {0, 0, -100}}};
  t_mat  w = {{{0, 2, -2}, {-.1, 1, 0}, {100, 0, -100}}};

  _ft_assert(mat_equals(mat_add(m, n), w));
  return (SUCCESS);
}

int  mat_subtract_00(void)
{
  t_mat  m = {{{1, 1, -1}, {.1, .5, 1.9}, {100, 0, 0}}};
  t_mat  n = {{{-1, 1, -1}, {-.2, .5, -1.9}, {0, 0, -100}}};
  t_mat  w = {{{2, 0, 0}, {.3, 0, 3.8}, {100, 0, 100}}};

  _ft_assert(mat_equals(mat_subtract(m, n), w));
  return (SUCCESS);
}

int  mat_prod_00(void)
{
  t_mat  m = {{{1, 1, -1}, {.1, .5, 1.9}, {100, 0, 0}}};
  t_mat  n = {{{-1, 1, -1}, {-.2, .5, -1.9}, {0, 0, -100}}};
  t_mat  w = {{{-1.2, 1.5, 97.1}, {-.2, .35, -191.05}, {-100, 100, -100}}};

  _ft_assert(mat_equals(mat_prod(m, n), w));
  return (SUCCESS);
}

int  mat_prod_01(void)
{
  t_mat  m = {{{-1.2, 1.5, 97.1}, {-.2, .35, -191.05}, {-100, 100, -100}}};

  _ft_assert(mat_equals(mat_prod(mat_identity(), m), m));
  return (SUCCESS);
}

int  mat_prod_02(void)
{
  t_mat  m = {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}};
  t_mat  n = {{{-1.2, 1.5, 97.1}, {-.2, .35, -191.05}, {-100, 100, -100}}};

  _ft_assert(mat_equals(mat_prod(m, n), m));
  return (SUCCESS);
}

int  mat_vec_prod_00(void)
{
  t_vec  u = {.655, 0, 101};

  _ft_assert(vec_equals(mat_vec_prod(mat_identity(), u), u));
  return (SUCCESS);
}

int  mat_vec_prod_01(void)
{
  t_mat  m = {{{1, 1, -1}, {.1, .5, 1.9}, {100, 0, 0}}};
  t_vec  u = {.655, 0, 101};
  t_vec  v = {-100.345, 191.9655, 65.5};

  _ft_assert(vec_equals(mat_vec_prod(m, u), v));
  return (SUCCESS);
}

int  mat_vec_prod_02(void)
{
  t_mat  m = {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}};
  t_vec  u = {.655, 0, 101};
  t_vec  v = {0, 0, 0};

  _ft_assert(vec_equals(mat_vec_prod(m, u), v));
  return (SUCCESS);
}

int  mat_vec_prod_03(void)
{
  t_mat  m = {{{1, 1, -1}, {.1, .5, 1.9}, {100, 0, 0}}};
  t_vec  u = {0, 0, 0};
  t_vec  v = {0, 0, 0};

  _ft_assert(vec_equals(mat_vec_prod(m, u), v));
  return (SUCCESS);
}

int  mat_transpose_00(void)
{
  _ft_assert(mat_equals(mat_transpose(mat_identity()), mat_identity()));
  return (SUCCESS);
}

int  mat_transpose_01(void)
{
  t_mat  m = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
  t_mat  n = {{{1, 4, 7}, {2, 5, 8}, {3, 6, 9}}};

  _ft_assert(mat_equals(mat_transpose(m), n));
  return (SUCCESS);
}

int  mat_transpose_02(void)
{
  t_mat  m = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
  t_mat  n = {{{1, 4, 7}, {2, 5, 8}, {3, 6, 9}}};

  _ft_assert(mat_equals(mat_transpose(n), m));
  return (SUCCESS);
}

int  mat_determinant_00(void)
{
  t_mat  m = {{{3, .7, 7}, {12, .1, 1}, {3, 3, -4}}};

  _ft_assert(double_equals(mat_determinant(m), 275.4));
  return (SUCCESS);
}

int  mat_determinant_01(void)
{
  t_mat  m = {{{0, 0, 0}, {12, .1, 1}, {3, 3, -4}}};

  _ft_assert(double_equals(mat_determinant(m), 0));
  return (SUCCESS);
}

int  mat_determinant_02(void)
{
  t_mat  m = {{{0, 3, 4}, {0, .1, 1}, {0, 3, -4}}};

  _ft_assert(double_equals(mat_determinant(m), 0));
  return (SUCCESS);
}

int  mat_determinant_03(void)
{
  t_mat  m = {{{1, 0, 3}, {0, .1, 1}, {-3, -3, 0}}};

  _ft_assert(double_equals(mat_determinant(m), 3.9));
  return (SUCCESS);
}

int  mat_cofactor_00(void)
{
  t_mat  m = {{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}};
  t_mat  n = {{{1, -1, 1}, {-1, 1, -1}, {1, -1, 1}}};

  _ft_assert(mat_equals(mat_cofactor(m), n));
  return (SUCCESS);
}

// cofactor of minor!!!
int mat_minor_00(void)
{
  t_mat m = {{{-1.2, 1.5, 97.1}, {0.2, 0.35, -191.05}, {-100, 100, -100}}};
  t_mat n = {{{19070, 19125, 55}, {9860, 9830, -30}, {-320.56, -209.84, -0.72}}};
  _ft_assert(mat_equals(mat_minor(m), n));
  return SUCCESS;
}
int  mat_adjoint_00(void)
{
  t_mat  m = {{{-1.2, 1.5, 97.1}, {-.2, .35, -191.05}, {-100, 100, -100}}};
  t_mat  n = {{{19070, 9860, -320.56}, {19085, 9830, -248.68}, {15, -30, -.12}}};

  _ft_assert(mat_equals(mat_adjoint(m), n));
  return (SUCCESS);
}

int  mat_inverse_00(void)
{
  t_mat  m = {{{-1.2, 1.5, 97.1}, {-.2, .35, -191.05}, {-100, 100, -100}}};
  t_mat  n = {{{2.64861, 1.36944, -.04452}, {2.65069, 1.36527, -.03453}, {.00208, -.00416, -.00001}}};

  _ft_assert(mat_equals(mat_inverse(m), n));
  return (SUCCESS);
}

int  mat_inverse_01(void)
{
  t_mat  m = {{{2.64861, 1.36944, -.04452}, {2.65069, 1.36527, -.03453}, {.00208, -.00416, -.00001}}};

  _ft_assert(mat_equals(mat_prod(mat_inverse(m), m), mat_identity()));
  return (SUCCESS);
}

int  mat_inverse_02(void)
{
  t_mat  m = {{{0, 1, -.04}, {2.6, 1.3, 0}, {.002, 0, -.2}}};
  t_mat  n = {{{-.49990, .38454, .09998}, {.99980, .00015, -.19996}, {-.004999, .00385, -4.999}}};

  _ft_assert(mat_equals(mat_inverse(m), n));
  return (SUCCESS);
}

int  quadratic_roots_00(void)
{
  t_roots  xs;

  xs = quadratic_roots(0, 2, 2);
  _ft_assert(xs.count == 0);
  return (SUCCESS);
}

int  quadratic_roots_01(void)
{
  t_roots  xs;

  xs = quadratic_roots(4.5, 3, 7);
  _ft_assert(xs.count == 0);
  return (SUCCESS);
}

int  quadratic_roots_02(void)
{
  t_roots  xs;

  xs = quadratic_roots(4.5, 3, 0);
  _ft_assert(xs.count == 2 && double_equals(xs.x1, -.66666) && double_equals(xs.x2, 0));
  return (SUCCESS);
}

int  quadratic_roots_03(void)
{
  t_roots  xs;

  xs = quadratic_roots(4.5, 10, 2);
  _ft_assert(xs.count == 2 && double_equals(xs.x1, -2) && double_equals(xs.x2, -.22222));
  return (SUCCESS);
}

int  quadratic_roots_04(void)
{
  t_roots  xs;

  xs = quadratic_roots(1, 0, 0);
  _ft_assert(xs.count == 1 && double_equals(xs.x1, 0) && double_equals(xs.x2, 0));
  return (SUCCESS);
}

int  ray_position_00(void)
{
  t_ray  ray = {{2, 3, 4}, {1, 0, 0}};

  _ft_assert(vec_equals(ray_position(ray, 0), ray.origin));
  return (SUCCESS);
}

int  ray_position_01(void)
{
  t_ray  ray = {{2, 3, 4}, {1, 0, 0}};

  _ft_assert(vec_equals(ray_position(ray, 1), (t_vec){3, 3, 4}));
  return (SUCCESS);
}

int  ray_position_02(void)
{
  t_ray  ray = {{2, 3, 4}, {1, 0, 0}};

  _ft_assert(vec_equals(ray_position(ray, 2.5), (t_vec){4.5, 3, 4}));
  return (SUCCESS);
}

int  ray_sphere_intersect_00(void)
{
  t_ray    ray = {{0, 0, -5}, {0, 0, 1}};
  t_obj    sphere = {
    (t_shape){SPHERE, 1, 1, 1},
    (t_material){{0,0,0},0,0,0,0},
    (t_vec){0,0,0},
    (t_vec){0,0,0},
    (t_mat){{{1,0,0},{0,1,0},{0,0,1}}},
  };
  t_roots  xs;

  xs = ray_sphere_intersect(ray, &sphere);
  _ft_assert(xs.count == 2 && double_equals(xs.x1, 4) && double_equals(xs.x2, 6));
  return (SUCCESS);
}

int  ray_sphere_intersect_01(void)
{
  t_ray    ray = {{0, 1, -5}, {0, 0, 1}};
  t_obj    sphere = {
    (t_shape){SPHERE, 1, 1, 1},
    (t_material){{0,0,0},0,0,0,0},
    (t_vec){0,0,0},
    (t_vec){0,0,0},
    (t_mat){{{1,0,0},{0,1,0},{0,0,1}}},
  };
  t_roots    xs;

  xs = ray_sphere_intersect(ray, &sphere);
  _ft_assert(xs.count == 1 && double_equals(xs.x1, 5) && double_equals(xs.x2, 5));
  return (SUCCESS);
}

int  ray_sphere_intersect_02(void)
{
  t_ray    ray = {{0, 2, -5}, {0, 0, 1}};
  t_obj    sphere = {
    (t_shape){SPHERE, 1, 1, 1},
    (t_material){{0,0,0},0,0,0,0},
    (t_vec){0,0,0},
    (t_vec){0,0,0},
    (t_mat){{{1,0,0},{0,1,0},{0,0,1}}},
  };
  t_roots    xs;

  xs = ray_sphere_intersect(ray, &sphere);
  _ft_assert(xs.count == 0);
  return (SUCCESS);
}

int  ray_sphere_intersect_03(void)
{
  t_ray    ray = {{0, 0, 0}, {0, 0, 1}};
  t_obj    sphere = {
    (t_shape){SPHERE, 1, 1, 1},
    (t_material){{0,0,0},0,0,0,0},
    (t_vec){0,0,0},
    (t_vec){0,0,0},
    (t_mat){{{1,0,0},{0,1,0},{0,0,1}}},
  };
  t_roots    xs;

  xs = ray_sphere_intersect(ray, &sphere);
  _ft_assert(xs.count == 2 && double_equals(xs.x1, -1) && double_equals(xs.x2, 1));
  return (SUCCESS);
}

int  ray_sphere_intersect_04(void)
{
  t_ray    ray = {{0, 0, 5}, {0, 0, 1}};
  t_obj    sphere = {
    (t_shape){SPHERE, 1, 1, 1},
    (t_material){{0,0,0},0,0,0,0},
    (t_vec){0,0,0},
    (t_vec){0,0,0},
    (t_mat){{{1,0,0},{0,1,0},{0,0,1}}},
  };
  t_roots    xs;

  xs = ray_sphere_intersect(ray, &sphere);
  _ft_assert(xs.count == 2 && double_equals(xs.x1, -6) && double_equals(xs.x2, -4));
  return (SUCCESS);
}

int  unit_test_suite(suite tests)
{
  while (*tests)
    _ft_verify((*(tests++)));
  return (SUCCESS);
}

int  main(void)
{
  int  result;

  result = 0;
  result += unit_test_suite(tests_laag);
  result += unit_test_suite(tests_ray);
  if (result == 0)
    printf(GREEN"PASSED\n");
  printf(DFLT"Tests run: %d\n", tests_run);

  return (result);
}
