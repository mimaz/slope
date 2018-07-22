/*
 * Copyright (C) 2017  Elvis Teixeira
 *
 * This source code is free software: you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General
 * Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any
 * later version.
 *
 * This source code is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU Lesser General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Lesser General
 * Public License along with this program.
 * If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SLOPE_FIGURE_H
#define SLOPE_FIGURE_H

#include <glib-object.h>
#include <slope/legend.h>

G_BEGIN_DECLS

#define SLOPE_TYPE_FIGURE (slope_figure_get_type())

typedef enum _SlopeFigureFrameMode SlopeFigureFrameMode;

enum _SlopeFigureFrameMode 
{
  SLOPE_FIGURE_RECTANGLE,
  SLOPE_FIGURE_ROUNDRECTANGLE,
};

struct _SlopeFigureClass
{
  GObjectClass parent_class;

  void (*draw)(SlopeFigure *self, const SlopeRect *rect, cairo_t *cr);
  void (*add_scale)(SlopeFigure *self, SlopeScale *scale);
};

G_DECLARE_DERIVABLE_TYPE(SlopeFigure, slope_figure, SLOPE, FIGURE, GObject)

SlopeFigure *slope_figure_new(void);

GList *slope_figure_get_scale_list(SlopeFigure *self);

void slope_figure_add_scale(SlopeFigure *self, SlopeScale *scale);

SlopeColor slope_figure_get_background_color(SlopeFigure *self);

void slope_figure_set_background_color(SlopeFigure *self, SlopeColor color);

gboolean slope_figure_get_is_managed(SlopeFigure *self);

void slope_figure_set_is_managed(SlopeFigure *self, gboolean managed);

void slope_figure_draw(SlopeFigure *self, const SlopeRect *rect, cairo_t *cr);

void slope_figure_write_to_png(SlopeFigure *self,
                               const char * filename,
                               int          width,
                               int          height);

SlopeView *slope_figure_get_view(SlopeFigure *self);

SlopeItem *slope_figure_get_legend(SlopeFigure *self);

G_END_DECLS

#endif /* SLOPE_FIGURE_H */
