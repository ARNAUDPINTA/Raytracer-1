/*
** set.c for set in /home/pinta_a/rendu/INFOGRAPHIE/gfx_raytracer1
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Sat Mar  5 00:59:19 2016 pinta_a
** Last update Fri Mar 11 15:01:52 2016 pinta_a
*/

#include <lapin.h>
#include <math.h>
#include "struct.h"
#include "proto.h"

void		init_set(t_set *set)
{
  set->dist = 0;
  set->type = 0;
  set->color = 0;
  set->col.full = BLACK;
  set->ray.pos.x = 0;
  set->ray.pos.y = 0;
  set->ray.pos.z = 0;
  set->ray.vec.x = 0;
  set->ray.vec.y = 0;
  set->ray.vec.z = 0;
}
