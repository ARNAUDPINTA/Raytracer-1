/*
** find_sphere.c for finc_sphere in /home/pinta_a/rendu/INFOGRAPHIE/gfx_raytracer1
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Mon Feb 29 02:08:51 2016 pinta_a
** Last update Sun Mar 13 18:54:23 2016 pinta_a
*/

#include <lapin.h>
#include <math.h>
#include "include.h"
#include "struct.h"
#include "proto.h"

void		my_copy_set_sphere(t_info *sphere,
				   t_set *set,
				   t_posz *pos,
				   double dist)
{
  set->dist = dist;
  set->color = sphere->color;
  set->type = sphere->type;
  set->ray.pos.x = pos->x;
  set->ray.pos.y = pos->y;
  set->ray.pos.z = pos->z;
  set->ray.vec.x = pos->x - sphere->pos.x;
  set->ray.vec.y = pos->y - sphere->pos.y;
  set->ray.vec.z = pos->z - sphere->pos.z;
  set->ray.vec = my_vector_u(&set->ray.vec);
}

void		_my_resolv_equa_sphere(t_info *sphere,
				       t_set *set,
				       t_ray *ray,
				       double sol)
{
  t_posz	pos;
  double	dist;

  pos.x = ray->vec.x * sol + ray->pos.x;
  pos.y = ray->vec.y * sol + ray->pos.y;
  pos.z = ray->vec.z * sol + ray->pos.z;
  dist = sqrt(pow(pos.x - ray->pos.x, 2)
	      + pow(pos.y - ray->pos.y, 2)
	      + pow(pos.z - ray->pos.z, 2));
  if (dist < set->dist || set->dist == 0)
    my_copy_set_sphere(sphere, set, &pos, dist);
}

void		my_resolv_equa_sphere(t_info *sphere,
				      t_equa *equa,
				      t_ray *ray,
				      t_set *set)
{
  double	sol;

  if (equa->d > 0)
    {
      sol = my_sol(((-equa->b) - sqrt(equa->d)) / (2 * equa->a),
		   ((-equa->b) + sqrt(equa->d)) / (2 * equa->a));
      if (sol > 0.001)
	_my_resolv_equa_sphere(sphere, set, ray, sol);
    }
  else if (equa->d == 0)
    {
      if (equa->a > 0)
	sol = -equa->b / (2 * equa->a);
      if (equa->a > 0 && sol > 0.001)
	_my_resolv_equa_sphere(sphere, set, ray, sol);
    }
}

void		my_equa_sphere(t_info *sphere,
			       t_ray *ray,
			       t_set *set)
{
  t_equa	equa;

  equa.a = pow(ray->vec.x, 2)
    + pow(ray->vec.y, 2)
    + pow(ray->vec.z, 2);
  equa.b = 2 * ray->vec.x * (ray->pos.x - sphere->pos.x)
    + 2 * ray->vec.y * (ray->pos.y - sphere->pos.y)
    + 2 * ray->vec.z * (ray->pos.z - sphere->pos.z);
  equa.c = pow((ray->pos.x - sphere->pos.x), 2)
    + pow((ray->pos.y - sphere->pos.y), 2)
    + pow((ray->pos.z - sphere->pos.z), 2) - pow(sphere->data, 2);
  equa.d = pow(equa.b, 2) - 4 * equa.a * equa.c;
  my_resolv_equa_sphere(sphere, &equa, ray, set);
}

void		my_find_sphere(t_geom *geom,
			       t_ray *ray,
			       t_set *set)
{
  int		i;

  i = 0;
  while (i < geom->nb_sphere)
    {
      my_equa_sphere(&geom->sphere[i], ray, set);
      i = i + 1;
    }
}
