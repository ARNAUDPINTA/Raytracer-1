/*
** key_rsp.c for raytracer in /home/pinta_a/rendu/INFOGRAPHIE/gfx_raytracer1
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Sun Mar 13 19:05:25 2016 pinta_a
** Last update Sun Mar 13 19:05:57 2016 pinta_a
*/

#include <lapin.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "include.h"
#include "struct.h"
#include "proto.h"

void			move_x_rsp(t_bunny_event_state state,
				   t_bunny_keysym key,
				   t_loop *loop)
{
  if (state == GO_DOWN && key == BKS_LEFT)
    loop->move.left = 1;
  if (state == GO_UP && key == BKS_LEFT)
    loop->move.left = 0;
  if (state == GO_DOWN && key == BKS_RIGHT)
    loop->move.right = 1;
  if (state == GO_UP && key == BKS_RIGHT)
    loop->move.right = 0;  
}

void			move_z_rsp(t_bunny_event_state state,
				   t_bunny_keysym key,
				   t_loop *loop)
{
  if (state == GO_DOWN && key == BKS_UP)
    loop->move.front = 1;
  if (state == GO_UP && key == BKS_UP)
    loop->move.front = 0;
  if (state == GO_DOWN && key == BKS_DOWN)
    loop->move.back = 1;
  if (state == GO_UP && key == BKS_DOWN)
    loop->move.back = 0;
}

void			move_y_rsp(t_bunny_event_state state,
				   t_bunny_keysym key,
				   t_loop *loop)
{
  if (state == GO_DOWN && key == BKS_SPACE)
    loop->move.up = 1;
  if (state == GO_UP && key == BKS_SPACE)
    loop->move.up = 0;
  if (state == GO_DOWN && key == BKS_Z)
    loop->move.down = 1;
  if (state == GO_UP && key == BKS_Z)
    loop->move.down = 0;
}

void			move_angle_rsp(t_bunny_event_state state,
				       t_bunny_keysym key,
				       t_loop *loop)
{
  if (state == GO_DOWN && key == BKS_O)
    loop->move.rot_l = 1;
  if (state == GO_UP && key == BKS_O)
    loop->move.rot_l = 0;
  if (state == GO_DOWN && key == BKS_P)
    loop->move.rot_r = 1;
  if (state == GO_UP && key == BKS_P)
    loop->move.rot_r = 0;
}


t_bunny_response	key_rsp(t_bunny_event_state state,
				t_bunny_keysym key,
				void *data)
{
  t_loop		*loop;

  loop = data;
  if (state == GO_DOWN)
    loop->move.actu = 1;
  move_x_rsp(state, key, loop);
  move_y_rsp(state, key, loop);
  move_z_rsp(state, key, loop);
  move_angle_rsp(state, key, loop);
  if (state == GO_DOWN && key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}
