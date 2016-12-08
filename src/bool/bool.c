/*
** bool.c for bool in /home/zeng_d/test/tekpaint
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Jan 27 04:09:54 2016 David Zeng
** Last update Wed Jan 27 06:37:35 2016 Jamy Bailly
*/

#include "tekpaint.h"

int		event_square(void *tekpaint, t_event_mouse *action)
{
  t_tek		*tp;

  (void)action;
  tp = tekpaint;
  tp->bool_data.square = 1;
  tp->bool_data.circle = 0;
  tp->bool_data.line = 0;
  tp->bool_data.bucket = 0;
  return (0);
}

int		event_circle(void *tekpaint, t_event_mouse *action)
{
  t_tek		*tp;

  (void)action;
  tp = tekpaint;
  tp->bool_data.square = 0;
  tp->bool_data.circle = 1;
  tp->bool_data.line = 0;
  tp->bool_data.bucket = 0;
  return (0);
}

int		event_line(void *tekpaint, t_event_mouse *action)
{
  t_tek		*tp;

  (void)action;
  tp = tekpaint;
  tp->bool_data.square = 0;
  tp->bool_data.circle = 0;
  tp->bool_data.line = 1;
  tp->bool_data.bucket = 0;
  return (0);
}

int		event_eraser(void *tekpaint, t_event_mouse *action)
{
  t_tek		*tp;

  (void)action;
  tp = tekpaint;
  tp->bool_data.eraser = 1;
  tp->bool_data.brush = 0;
  tp->bool_data.bucket = 0;
  tp->bool_data.color = WHITE;
  return (0);
}

int		event_brush(void *tekpaint, t_event_mouse *action)
{
  t_tek		*tp;

  (void)action;
  tp = tekpaint;
  if (tp->bool_data.eraser == 1)
    tp->bool_data.color = BLACK;
  tp->bool_data.eraser = 0;
  tp->bool_data.brush = 1;
  tp->bool_data.bucket = 0;
  return (0);
}
