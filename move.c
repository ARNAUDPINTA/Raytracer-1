/*
** move.c for raytracer in /home/pinta_a/rendu/INFOGRAPHIE/gfx_raytracer1
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Sun Mar 13 19:04:03 2016 pinta_a
** Last update Sun Mar 13 19:58:41 2016 pinta_a
*/

#include <lapin.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "include.h"
#include "struct.h"
#include "proto.h"

void			my_move(t_loop *loop)
{
  if (loop->move.left == 1)
    loop->view.pos.x = loop->view.pos.x - X_SPEED;
  if (loop->move.right == 1)
    loop->view.pos.x = loop->view.pos.x + X_SPEED;
  if (loop->move.up == 1)
    loop->view.pos.y = loop->view.pos.y - Y_SPEED;
  if (loop->move.down == 1)
    loop->view.pos.y = loop->view.pos.y + Y_SPEED;
  if (loop->move.back == 1)
    loop->view.pos.z = loop->view.pos.z - Z_SPEED;
  if (loop->move.front == 1)
    loop->view.pos.z = loop->view.pos.z + Z_SPEED;
  if (loop->move.rot_l == 1)
    loop->view.angle = loop->view.angle + ROT_SPEED;
  if (loop->move.rot_r == 1)
    loop->view.angle = loop->view.angle - ROT_SPEED;
}
