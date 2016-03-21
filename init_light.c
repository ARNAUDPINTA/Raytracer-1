/*
** init_light.c for init_light in /home/pinta_a/rendu/INFOGRAPHIE/gfx_raytracer1
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Sun Feb 28 12:13:50 2016 pinta_a
** Last update Sun Mar 13 18:59:31 2016 pinta_a
*/

#include <lapin.h>
#include "struct.h"
#include "proto.h"

int		my_copy_field_light(const char *field[3],
				    t_info *light,
				    int i)
{
  if (my_getnbr_d(field[0], &light[i].pos.x)
      || my_getnbr_d(field[1], &light[i].pos.y)
      || my_getnbr_d(field[2], &light[i].pos.z))
    return (1);
  return (0);
}

int		_my_init_light(t_bunny_ini *ini,
			       t_info *light,
			       char *forme,
			       int nb)
{
  const char	*field[3];
  t_pars	pars;

  pars.i = 0;
  pars.j = 1;
  while (pars.i < nb)
    {
      pars.k = 0;
      while (pars.k < 3)
	{
	  field[pars.k] = bunny_ini_get_field(ini, forme, "light", pars.j);
	  if (field[pars.k] == NULL)
	    return (1);
	  pars.k = pars.k + 1;
	  pars.j = pars.j + 1;
	}
      if (my_copy_field_light(field, light, pars.i))
	return (2);
      pars.i = pars.i + 1;
    }
  if (bunny_ini_get_field(ini, forme, "light", pars.j) != NULL)
    return (3);
  return (0);
}

int		my_init_light(t_bunny_ini *ini,
			      t_geom *geom,
			      char *forme)
{
  const char	*field;

  if ((field = bunny_ini_get_field(ini, forme, "light", 0)) == NULL)
    return (1);
  if (my_getnbr_i(field, &geom->nb_light))
    return (2);
  if (geom->nb_light < 0)
    return (3);
  if (geom->nb_light == 0
      && bunny_ini_get_field(ini, forme, "light", 1) != NULL)
    return (4);
  if (geom->nb_light == 0)
    return (0);
  if ((geom->light = bunny_malloc(sizeof(t_info) * geom->nb_light)) == NULL)
    return (5);
  if (_my_init_light(ini, geom->light, forme, geom->nb_light))
    return (6);
  return (0);
}
