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

#ifndef SLOPE_LEGEND_H
#define SLOPE_LEGEND_H

#include <slope/item.h>

G_BEGIN_DECLS

#define SLOPE_TYPE_LEGEND (slope_legend_get_type())

typedef enum _SlopeLegendPosition SlopeLegendPosition;

enum _SlopeLegendPosition 
{
  SLOPE_LEGEND_CUSTOM,
  SLOPE_LEGEND_TOP,
  SLOPE_LEGEND_BOTTOM,
  SLOPE_LEGEND_LEFT,
  SLOPE_LEGEND_RIGHT,
  SLOPE_LEGEND_TOPLEFT,
  SLOPE_LEGEND_TOPRIGHT,
  SLOPE_LEGEND_BOTTOMLEFT,
  SLOPE_LEGEND_BOTTOMRIGHT
};

struct _SlopeLegendClass
{
  SlopeItemClass parent_class;
};

G_DECLARE_DERIVABLE_TYPE(SlopeLegend, slope_legend, SLOPE, LEGEND, SlopeItem)

SlopeItem *slope_legend_new(SlopeOrientation orientation);

SlopeColor slope_legend_get_fill_color(SlopeLegend *self);

void slope_legend_set_fill_color(SlopeLegend *self, SlopeColor color);

SlopeColor slope_legend_get_stroke_color(SlopeLegend *self);

void slope_legend_set_stroke_color(SlopeLegend *self, SlopeColor color);

void slope_legend_set_stroke_width(SlopeLegend *self, double width);

double slope_legend_get_stroke_width(SlopeLegend *self);

void slope_legend_set_orientation(SlopeLegend *    self,
                                  SlopeOrientation orientation);

SlopeOrientation slope_legend_get_orientation(SlopeLegend *self);

void slope_legend_set_anchor(SlopeLegend *self, SlopeCorner anchor);

SlopeCorner slope_legend_get_anchor(SlopeLegend *self);

void slope_legend_set_position(SlopeLegend *self, double x, double y);

void slope_legend_get_position(SlopeLegend *self, double *x, double *y);

void slope_legend_set_default_position(SlopeLegend *       self,
                                       SlopeLegendPosition position);

void slope_legend_add_item(SlopeLegend *self, SlopeItem *item);

void slope_legend_clear_items(SlopeLegend *self);

G_END_DECLS

#endif /* SLOPE_LEGEND_H */
