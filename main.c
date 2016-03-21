
/*
** main.c for raytracer in /home/pinta/rendu/INFOGRAPHIE/gfx_raytracer1
**
** Made by pinta_a
** Login   <pinta_a@epitech.net>
**
** Started on  Wed Feb 17 01:25:16 2016 pinta_a
** Last update Sun Mar 13 23:38:09 2016 pinta_a
*/

#include <lapin.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "include.h"
#include "struct.h"
#include "proto.h"

void			my_init_move(t_loop *loop)
{
  loop->move.left = 0;
  loop->move.right = 0;
  loop->move.up = 0;
  loop->move.down = 0;
  loop->move.front = 0;
  loop->move.back = 0;
  loop->move.rot_r = 0;
  loop->move.rot_l = 0;
}

t_bunny_response	main_loop(t_loop *loop)
{
  bunny_set_key_response(key_rsp);
  if (loop->move.actu == 1)
    {
      my_move(loop);
      my_raytracer(loop);
      bunny_blit(&loop->win->buffer, &loop->pix->clipable, NULL);
      bunny_display(loop->win);
      loop->move.actu = 0;
    }
  return (GO_ON);
}

int			main(int argc, char **argv)
{
  t_loop		loop;

  if (argc != 3)
    {
      write(2, "usage: ./raytracer [.ini] [forme]\n", 34);
      return (1);
    }
  loop.move.actu = 1;
  if ((loop.win = bunny_start(WIDTH, HEIGHT, false, "RAYTRACER")) == NULL
      || (loop.pix = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)
    return (2);
  if (my_init_geom(&loop, argv[1], argv[2]))
    return (3);
  my_init_palette(&loop);
  my_init_move(&loop);
  bunny_set_loop_main_function((t_bunny_loop)main_loop);
  bunny_loop(loop.win, 30, &loop);
  my_free(&loop);
  return (0);
}
