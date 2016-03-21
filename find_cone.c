/*
** find_cone.c for find_cone in /home/pinta_a/rendu/INFOGRAPHIE/gfx_raytracer1
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Mon Feb 29 22:46:57 2016 pinta_a
** Last update Sun Mar 13 20:45:38 2016 pinta_a
*/

#include <lapin.h>
#include <math.h>
#include "include.h"
#include "struct.h"
#include "proto.h"

#include <stdio.h>

void		my_copy_set_cone(t_info *cone,
				 t_set *set,
				 t_posz *pos,
				 double dist)
{
  double	vx;
  double	vz;
  double	m;

  set->dist = dist;
  set->color = cone->color;
  set->type = cone->type;
  set->ray.pos.x = pos->x;
  set->ray.pos.y = pos->y;
  set->ray.pos.z = pos->z;
  vx = pos->x - cone->pos.x;
  vz = pos->z - cone->pos.z;
  m = sqrt(vx * vx + vz * vz);
  vx = vx / m;
  vz = vz / m;
  set->ray.vec.x = vx * 500 / cone->data;
  set->ray.vec.z = vz * 500 / cone->data;
  set->ray.vec.y = cone->data / 500;
  set->ray.vec = my_vector_u(&set->ray.vec);
}

void		_my_resolv_equa_cone(t_info *cone,
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
    my_copy_set_cone(cone, set, &pos, dist);
}

void		my_resolv_equa_cone(t_info *cone,
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
	_my_resolv_equa_cone(cone, set, ray, sol);
    }
  else if (equa->d == 0)
    {
      if (equa->a > 0)
	sol = -equa->b / (2 * equa->a);
      if (equa->a > 0 && sol > 0.001)
	_my_resolv_equa_cone(cone, set, ray, sol);
    }
}

void		my_equa_cone(t_info *cone,
			     t_ray *ray,
			     t_set *set)
{
  t_equa	equa;

  equa.a = pow(ray->vec.x, 2)
    + pow(ray->vec.z, 2)
    - pow(ray->vec.y, 2)
    * pow(tan((M_PI * cone->data) / 180), 2);
  equa.b = 2 * ray->vec.x * (ray->pos.x - cone->pos.x)
    + 2 * ray->vec.z * (ray->pos.z - cone->pos.z)
    - 2 * ray->vec.y * (ray->pos.y - cone->pos.y)
    * pow(tan((M_PI * cone->data) / 180), 2);
  equa.c = pow((ray->pos.x - cone->pos.x), 2)
    + pow((ray->pos.z - cone->pos.z), 2)
    - pow((ray->pos.y - cone->pos.y), 2)
    * pow(tan(M_PI * cone->data / 180), 2);
  equa.d = pow(equa.b, 2) - 4 * equa.a * equa.c;
  my_resolv_equa_cone(cone, &equa, ray, set);
}

void		my_find_cone(t_geom *geom,
			     t_ray *ray,
			     t_set *set)
{
  int		i;

  i = 0;
  while (i < geom->nb_cone)
    {
      my_equa_cone(&geom->cone[i], ray, set);
      i = i + 1;
    }
}
