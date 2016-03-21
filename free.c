/*
** free.c for raytracer in /home/pinta/rendu/INFOGRAPHIE/gfx_raytracer1
**
** Made by pinta_a
** Login   <pinta_a@epitech.net>
**
** Started on  Wed Feb 17 03:05:09 2016 pinta_a
** Last update Sun Mar 13 23:34:14 2016 pinta_a
*/

#include <lapin.h>
#include "struct.h"
#include "proto.h"

void	my_free(t_loop *loop)
{
  if (loop->geom.nb_sphere > 0)
    bunny_free(loop->geom.sphere); 
  if (loop->geom.nb_cone > 0)
    bunny_free(loop->geom.cone);
  if (loop->geom.nb_cylinder > 0)
    bunny_free(loop->geom.cylinder);
  if (loop->geom.nb_plan > 0)
    bunny_free(loop->geom.plan);
  if (loop->geom.nb_light > 0)
    bunny_free(loop->geom.light);
  bunny_delete_clipable(&loop->pix->clipable);
  bunny_stop(loop->win);
}
