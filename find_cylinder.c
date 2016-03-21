/*
** find_cylinder.c for find_cylinder in /home/pinta_a/rendu/INFOGRAPHIE/gfx_raytracer1
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Mon Feb 29 17:56:10 2016 pinta_a
** Last update Sun Mar 13 18:54:11 2016 pinta_a
*/

#include <lapin.h>
#include <math.h>
#include "include.h"
#include "struct.h"
#include "proto.h"

void		my_copy_set_cylinder(t_info *cylinder,
				     t_set *set,
				     t_posz *pos,
				     double dist)
{
  set->dist = dist;
  set->color = cylinder->color;
  set->type = cylinder->type;
  set->ray.pos.x = pos->x;
  set->ray.pos.y = pos->y;
  set->ray.pos.z = pos->z;
  set->ray.vec.x = 0;
  set->ray.vec.y = pos->y - cylinder->pos.y;
  set->ray.vec.z = pos->z - cylinder->pos.z;
  set->ray.vec = my_vector_u(&set->ray.vec);
}

void		_my_resolv_equa_cylinder(t_info *cylinder,
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
    my_copy_set_cylinder(cylinder, set, &pos, dist);
}

void		my_resolv_equa_cylinder(t_info *cylinder,
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
	_my_resolv_equa_cylinder(cylinder, set, ray, sol);
    }
  else if (equa->d == 0)
    {
      if (equa->a > 0)
	sol = -equa->b / (2 * equa->a);
      if (equa->a > 0 && sol > 0.001)
	_my_resolv_equa_cylinder(cylinder, set, ray, sol);
    }
}

void		my_equa_cylinder(t_info *cylinder,
				 t_ray *ray,
				 t_set *set)
{
  t_equa	equa;

  equa.a = pow(ray->vec.y, 2)
    + pow(ray->vec.z, 2);
  equa.b = 2 * ray->vec.y * (ray->pos.y - cylinder->pos.y)
    + 2 * ray->vec.z * (ray->pos.z - cylinder->pos.z);
  equa.c = pow((ray->pos.y - cylinder->pos.y), 2)
    + pow((ray->pos.z - cylinder->pos.z), 2) - pow(cylinder->data, 2);
  equa.d = pow(equa.b, 2) - 4 * equa.a * equa.c;
  my_resolv_equa_cylinder(cylinder, &equa, ray, set);
}

void		my_find_cylinder(t_geom *geom,
				 t_ray *ray,
				 t_set *set)
{
  int		i;

  i = 0;
  while (i < geom->nb_cylinder)
    {
      my_equa_cylinder(&geom->cylinder[i], ray, set);
      i = i + 1;
    }
}
