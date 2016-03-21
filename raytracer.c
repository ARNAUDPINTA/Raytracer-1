/*
** raytracer.c for raytracer in /home/pinta/rendu/INFOGRAPHIE/gfx_raytracer1
**
** Made by pinta_a
** Login   <pinta_a@epitech.net>
**
** Started on  Wed Feb 17 03:10:10 2016 pinta_a
** Last update Sun Mar 13 20:17:29 2016 pinta_a
*/

#include <lapin.h>
#include <math.h>
#include "include.h"
#include "struct.h"
#include "proto.h"

t_posz		my_vector_u(t_posz *vec)
{
  double	dist;
  t_posz	uvec;

  dist = sqrt(pow(vec->x, 2) + pow(vec->y, 2) + pow(vec->z, 2));
  uvec.x = vec->x / dist;
  uvec.y = vec->y / dist;
  uvec.z = vec->z / dist;
  return (uvec);
}

t_ray			my_ray(t_bunny_position *pos,
			       t_view *view)
{
  t_ray			ray;

  ray.pos.x = view->pos.x;
  ray.pos.y = view->pos.y;
  ray.pos.z = view->pos.z;
  ray.vec.x = (pos->x - WIDTH / 2) * cos(view->angle * M_PI / 180)
    + (WIDTH / (2 * tan(30 / 2))) * sin(view->angle * M_PI / 180);
  ray.vec.y = (pos->y - HEIGHT / 2);
  ray.vec.z = (pos->x - WIDTH / 2) * sin(view->angle * M_PI / 180)
    - (WIDTH / (2 * tan(30 / 2))) * cos(view->angle * M_PI / 180);
  ray.vec = my_vector_u(&ray.vec);
  return (ray);
}

void			my_raytracer(t_loop *loop)
{
  t_bunny_position	pos;
  t_ray			ray;
  t_set			set;

  pos.y = 0;
  while (pos.y < loop->pix->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < loop->pix->clipable.clip_width)
	{
	  init_set(&set);
	  ray = my_ray(&pos, &loop->view);
 	  my_find(loop, &ray, &set, 0);
	  tekpixel(loop->pix, &pos, set.col.full);
	  pos.x = pos.x + 1;
	}
      pos.y = pos.y + 1;
    }
}
