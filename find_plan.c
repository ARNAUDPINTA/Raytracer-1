/*
** find_plan.c for find_plan in /home/pinta_a/rendu/INFOGRAPHIE/gfx_raytracer1
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Mon Feb 29 18:00:01 2016 pinta_a
** Last update Wed Mar 16 18:01:41 2016 pinta_a
*/

#include <lapin.h>
#include <math.h>
#include "include.h"
#include "struct.h"
#include "proto.h"

void		my_copy_set_plan(t_info *plan,
				 t_set *set,
				 t_posz *pos,
				 double dist)
{
  int		x;
  int		z;

  x = (int)(ABS(pos->x / 10)) % 2;
  z = (int)(ABS(pos->z / 10)) % 2;
  set->dist = dist;
  set->type = plan->type;
  set->ray.pos.x = pos->x;
  set->ray.pos.y = pos->y;
  set->ray.pos.z = pos->z;
  set->color = plan->color;
  if (set->type >= 2
      && ((z == 0 && x == 0)
	  || (z == 1 && x == 1)))
    {
      set->color = (set->color + 1) % 8;
      set->type = set->type - 1;
    }
  set->ray.vec.x = plan->vec.x;
  set->ray.vec.y = plan->vec.y;
  set->ray.vec.z = plan->vec.z;
  set->ray.vec = my_vector_u(&set->ray.vec);
}

void		_my_equa_plan(t_info *plan,
			      t_ray *ray,
			      t_set *set,
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
    my_copy_set_plan(plan, set, &pos, dist);
}

void		my_equa_plan(t_info *plan,
			     t_ray *ray,
			     t_set *set)
{
  t_equa	equa;

  equa.a = plan->vec.x * (ray->pos.x - plan->pos.x)
    + plan->vec.y * (ray->pos.y - plan->pos.y)
    + plan->vec.z * (ray->pos.z - plan->pos.z);
  equa.b = plan->vec.x * ray->vec.x
    + plan->vec.y * ray->vec.y
    + plan->vec.z * ray->vec.z;
  if (equa.b != 0 && (equa.c = -(equa.a / equa.b)) > 0.001)
    _my_equa_plan(plan, ray, set, equa.c);
}

void		my_find_plan(t_geom *geom,
			     t_ray *ray,
			     t_set *set)
{
  int		i;

  i = 0;
  while (i < geom->nb_plan)
    {
      my_equa_plan(&geom->plan[i], ray, set);
      i = i + 1;
    }
}
