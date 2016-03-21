/*
** init_sphere.c for raytracer in /home/pinta/rendu/INFOGRAPHIE/gfx_raytracer1
**
** Made by pinta_a
** Login   <pinta_a@epitech.net>
**
** Started on  Wed Feb 17 02:06:56 2016 pinta_a
** Last update Sun Mar 13 18:51:30 2016 pinta_a
*/

#include <lapin.h>
#include "struct.h"
#include "proto.h"

int		my_copy_field_sphere(const char *field[6],
				     t_info *sphere,
				     int i)
{
  if (my_getnbr_d(field[0], &sphere[i].pos.x)
      || my_getnbr_d(field[1], &sphere[i].pos.y)
      || my_getnbr_d(field[2], &sphere[i].pos.z))
    return (1);
  if (my_getnbr_d(field[3], &sphere[i].data)
      || my_getnbr_i(field[4], &sphere[i].color)
      || my_getnbr_i(field[5], &sphere[i].type))
    return (2);
  if (sphere[i].color < 0 || sphere[i].color > 7)
    return (3);
  return (0);
}

int		_my_init_sphere(t_bunny_ini *ini,
				t_info *sphere,
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
	  field[pars.k] = bunny_ini_get_field(ini, forme, "sphere", pars.j);
	  if (field[pars.k] == NULL)
	    return (1);
	  pars.k = pars.k + 1;
	  pars.j = pars.j + 1;
	}
      if (my_copy_field_sphere(field, sphere, pars.i))
	return (2);
      pars.i = pars.i + 1;
    }
  if (bunny_ini_get_field(ini, forme, "sphere", pars.j) != NULL)
    return (3);
  return (0);
}

int		my_init_sphere(t_bunny_ini *ini,
			       t_geom *geom,
			       char *forme)
{
  const char	*field;

  if ((field = bunny_ini_get_field(ini, forme, "sphere", 0)) == NULL)
    return (1);
  if (my_getnbr_i(field, &geom->nb_sphere))
    return (2);
  if (geom->nb_sphere < 0)
    return (3);
  if (geom->nb_sphere == 0
      && bunny_ini_get_field(ini, forme, "sphere", 1) != NULL)
    return (4);
  if (geom->nb_sphere == 0)
    return (0);
  if ((geom->sphere = bunny_malloc(sizeof(t_info) * geom->nb_sphere)) == NULL)
    return (5);
  if (_my_init_sphere(ini, geom->sphere, forme, geom->nb_sphere))
    return (6);
  return (0);
}
