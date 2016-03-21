/*
** find_light.c for raytracer in /home/pinta_a/rendu/INFOGRAPHIE/gfx_raytracer1
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Fri Mar 11 15:50:08 2016 pinta_a
** Last update Sun Mar 13 22:32:57 2016 pinta_a
*/

#include <lapin.h>
#include <math.h>
#include "include.h"
#include "struct.h"
#include "proto.h"

t_ray		init_light_ray(t_info *light,
			       t_set *set)
{
  t_ray		ray;

  ray.pos.x = set->ray.pos.x;
  ray.pos.y = set->ray.pos.y;
  ray.pos.z = set->ray.pos.z;
  ray.vec.x = light->pos.x - set->ray.pos.x;
  ray.vec.y = light->pos.y - set->ray.pos.y;
  ray.vec.z = light->pos.z - set->ray.pos.z;
  return (ray);
}

void		find_light(t_loop *loop,
			   t_ray *ray,
			   t_set *set)
{
  t_light	l;
  double	dist;
  int		i;

  i = 0;
  l.id = IA;
  l.is = 0;
  l.shadow = 0;
  while (i < loop->geom.nb_light)
    {
      init_set(&l.tmp);
      l.light = init_light_ray(&loop->geom.light[i], set);
      dist = sqrt(pow(l.light.vec.x, 2)
      		  + pow(l.light.vec.y, 2)
      		  + pow(l.light.vec.z, 2));
      l.light.vec = my_vector_u(&l.light.vec);
      l.refl = my_ray_reflexion(&l.light, set);
      l.id = SUP(l.id + INF(my_scalaire(&l.light.vec, &set->ray.vec)));
      l.is = SUP(l.is + pow(INF(my_scalaire(&ray->vec, &l.refl.vec)), 7));
      my_find(loop, &l.light, &l.tmp, -1);
      if (l.tmp.dist > 0 && l.tmp.dist < dist)
      	l.shadow = l.shadow + 1;
      i = i + 1;
    }
  set_light(set, l.id, l.is, l.shadow);
}
