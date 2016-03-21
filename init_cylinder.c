/*
** init_cylinder.c for init_cylinder in /home/pinta_a/rendu/INFOGRAPHIE/gfx_raytracer1
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Mon Feb 29 01:30:09 2016 pinta_a
** Last update Sun Mar 13 19:19:09 2016 pinta_a
*/

#include <lapin.h>
#include "struct.h"
#include "proto.h"

int		my_copy_field_cylinder(const char *field[6],
				       t_info *cylinder,
				       int i)
{
  if (my_getnbr_d(field[0], &cylinder[i].pos.x)
      || my_getnbr_d(field[1], &cylinder[i].pos.y)
      || my_getnbr_d(field[2], &cylinder[i].pos.z))
    return (1);
  if (my_getnbr_d(field[3], &cylinder[i].data)
      || my_getnbr_i(field[4], &cylinder[i].color)
      || my_getnbr_i(field[5], &cylinder[i].type))
    return (2);
  if (cylinder[i].color < 0 || cylinder[i].color > 7)
    return (4);
  return (0);
}

int		_my_init_cylinder(t_bunny_ini *ini,
				  t_info *cylinder,
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
	  field[pars.k] = bunny_ini_get_field(ini, forme, "cylinder", pars.j);
	  if (field[pars.k] == NULL)
	    return (1);
	  pars.k = pars.k + 1;
	  pars.j = pars.j + 1;
	}
      if (my_copy_field_cylinder(field, cylinder, pars.i))
	return (2);
      pars.i = pars.i + 1;
    }
  if (bunny_ini_get_field(ini, forme, "cylinder", pars.j) != NULL)
    return (3);
  return (0);
}

int		my_init_cylinder(t_bunny_ini *ini,
				 t_geom *geom,
				 char *forme)
{
  const char	*field;

  if ((field = bunny_ini_get_field(ini, forme, "cylinder", 0)) == NULL)
    return (1);
  if (my_getnbr_i(field, &geom->nb_cylinder))
    return (2);
  if (geom->nb_cylinder < 0)
    return (3);
  if (geom->nb_cylinder == 0
      && bunny_ini_get_field(ini, forme, "cylinder", 1) != NULL)
    return (4);
  if (geom->nb_cylinder == 0)
    return (0);
  if ((geom->cylinder = bunny_malloc(sizeof(t_info) * geom->nb_cylinder)) == NULL)
    return (5);
  if (_my_init_cylinder(ini, geom->cylinder, forme, geom->nb_cylinder))
    return (6);
  return (0);
}
