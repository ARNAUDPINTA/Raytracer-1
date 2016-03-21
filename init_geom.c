/*
** init_geom.c for raytracer in /home/pinta/rendu/INFOGRAPHIE/gfx_raytracer1
**
** Made by pinta_a
** Login   <pinta_a@epitech.net>
**
** Started on  Wed Feb 17 01:25:08 2016 pinta_a
** Last update Fri Mar 11 15:21:35 2016 pinta_a
*/

#include <lapin.h>
#include <unistd.h>
#include "struct.h"
#include "proto.h"

int		my_init_geom(t_loop *loop,
			     char *file,
			     char *forme)
{
  t_bunny_ini	*ini;

  if ((ini = bunny_load_ini(file)) == NULL)
    {
      write(2, "error: in .ini file or no such .ini file\n", 41);
      return (1);
    }
  if (my_init_view(ini, &loop->view, forme)
      || my_init_light(ini, &loop->geom, forme))
    {
      write(2, "error: in .ini file\n", 20);
      return (2);
    }
  if (my_init_sphere(ini, &loop->geom, forme)
      || my_init_cylinder(ini, &loop->geom, forme)
      || my_init_cone(ini, &loop->geom, forme)
      || my_init_plan(ini, &loop->geom, forme))
    {
      write(2, "error: in .ini file\n", 20);
      return (3);
    }
  return (0);
}
