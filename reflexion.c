/*
** reflexion.c for reflexion in /home/pinta_a/rendu/INFOGRAPHIE/gfx_raytracer1
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Tue Mar  1 02:23:20 2016 pinta_a
** Last update Fri Mar 11 15:44:56 2016 pinta_a
*/

#include <lapin.h>
#include <math.h>
#include "struct.h"
#include "proto.h"

double		my_scalaire(t_posz *u, t_posz *v)
{
  return (u->x * v->x + u->y * v->y + u->z * v->z);
}

t_ray		my_ray_reflexion(t_ray *ray, t_set *set)
{
  double	scal;
  t_ray		new;

  scal = my_scalaire(&ray->vec, &set->ray.vec);
  new.pos.x = set->ray.pos.x;
  new.pos.y = set->ray.pos.y;
  new.pos.z = set->ray.pos.z;
  new.vec.x = ray->vec.x - 2 * scal * set->ray.vec.x;
  new.vec.y = ray->vec.y - 2 * scal * set->ray.vec.y;
  new.vec.z = ray->vec.z - 2 * scal * set->ray.vec.z;
  return (new);
}
