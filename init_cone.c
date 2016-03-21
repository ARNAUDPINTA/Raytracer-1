/*
** init_cone.c for raytracer in /home/pinta/rendu/INFOGRAPHIE/gfx_raytracer1
**
** Made by pinta_a
** Login   <pinta_a@epitech.net>
**
** Started on  Wed Feb 17 02:07:34 2016 pinta_a
** Last update Sun Mar 13 18:53:00 2016 pinta_a
*/

#include <lapin.h>
#include "struct.h"
#include "proto.h"

int		my_copy_field_cone(const char *field[6],
				   t_info *cone,
				   int i)
{
  if (my_getnbr_d(field[0], &cone[i].pos.x)
      || my_getnbr_d(field[1], &cone[i].pos.y)
      || my_getnbr_d(field[2], &cone[i].pos.z))
    return (1);
  if (my_getnbr_d(field[3], &cone[i].data)
      || my_getnbr_i(field[4], &cone[i].color)
      || my_getnbr_i(field[5], &cone[i].type))
    return (2);
  if (cone[i].color < 0 || cone[i].color > 7)
    return (3);
  return (0);
}

int		_my_init_cone(t_bunny_ini *ini,
			      t_info *cone,
			      char *forme,
			      int nb)
{
  const char	*field[6];
  t_pars	pars;

  pars.i = 0;
  pars.j = 1;
  while (pars.i < nb)
    {
      pars.k = 0;
      while (pars.k < 6)
	{
	  field[pars.k] = bunny_ini_get_field(ini, forme, "cone", pars.j);
	  if (field[pars.k] == NULL)
	    return (1);
	  pars.k = pars.k + 1;
	  pars.j = pars.j + 1;
	}
      if (my_copy_field_cone(field, cone, pars.i))
	return (2);
      pars.i = pars.i + 1;
    }
  if (bunny_ini_get_field(ini, forme, "cone", pars.j) != NULL)
    return (3);
  return (0);
}

int		my_init_cone(t_bunny_ini *ini,
			     t_geom *geom,
			     char *forme)
{
  const char	*field;

  if ((field = bunny_ini_get_field(ini, forme, "cone", 0)) == NULL)
    return (1);
  if (my_getnbr_i(field, &geom->nb_cone))
    return (2);
  if (geom->nb_cone < 0)
    return (3);
  if (geom->nb_cone == 0
      && bunny_ini_get_field(ini, forme, "cone", 1) != NULL)
    return (4);
  if (geom->nb_cone == 0)
    return (0);
  if ((geom->cone = bunny_malloc(sizeof(t_info) * geom->nb_cone)) == NULL)
    return (5);
  if (_my_init_cone(ini, geom->cone, forme, geom->nb_cone))
    return (6);
  return (0);
}
