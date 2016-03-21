/*
** find.c for raytracer in /home/pinta_a/rendu/INFOGRAPHIE/gfx_raytracer1
** 
** Made by arnaud pinta
** Login   <pinta_a@epitech.net>
** 
** Started on  Fri Feb 26 15:31:22 2016 arnaud pinta
** Last update Sun Mar 13 21:18:58 2016 pinta_a
*/

#include <lapin.h>
#include <math.h>
#include "include.h"
#include "struct.h"
#include "proto.h"

double		my_sol(double sol1, double sol2)
{
  if (sol1 > 0.001 && sol1 < sol2)
    return (sol1);
  if (sol2 > 0.001 && sol2 < sol1)
    return (sol2);
  return (0);
}

void		my_find(t_loop *loop,
			t_ray *ray,
			t_set *set,
			int rec)
{
  set->dist = 0;
  set->color = 0;
  set->type = 0;
  my_find_sphere(&loop->geom, ray, set);
  my_find_cylinder(&loop->geom, ray, set);
  my_find_cone(&loop->geom, ray, set);
  my_find_plan(&loop->geom, ray, set);
  set->col = loop->palette[set->color];
  if (set->dist > 0 && rec != -1)
    find_light(loop, ray, set);
  if (set->type == 1 && rec < REFL_NB && rec != -1)
    {
      *ray = my_ray_reflexion(ray, set);
      my_find(loop, ray, set, rec + 1);
    }
}
