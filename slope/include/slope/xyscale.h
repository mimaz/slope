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

#ifndef SLOPE_XYSCALE_H
#define SLOPE_XYSCALE_H

#include <slope/scale.h>
#include <slope/xyaxis.h>

G_BEGIN_DECLS

#define SLOPE_TYPE_XYSCALE (slope_xyscale_get_type())

typedef enum _SlopeXyScaleInteracion SlopeXyScaleInteracion;
typedef enum _SlopeXyScaleAxis SlopeXyScaleAxis;
typedef enum _SlopeXyScaleAxisFlag SlopeXyScaleAxisFlag;

enum _SlopeXyScaleInteracion 
{
  SLOPE_XYSCALE_INTERACTION_ZOOM      = 0,
  SLOPE_XYSCALE_INTERACTION_TRANSLATE = 1
};

enum _SlopeXyScaleAxis 
{
  SLOPE_XYSCALE_AXIS_BOTTOM = 0,
  SLOPE_XYSCALE_AXIS_TOP    = 1,
  SLOPE_XYSCALE_AXIS_LEFT   = 2,
  SLOPE_XYSCALE_AXIS_RIGHT  = 3,
  SLOPE_XYSCALE_AXIS_X      = 4,
  SLOPE_XYSCALE_AXIS_Y      = 5
};

enum _SlopeXyScaleAxisFlag 
{
  SLOPE_XYSCALE_NO_AXIS,
  SLOPE_XYSCALE_FRAME_AXIS,
  SLOPE_XYSCALE_FRAME_AXIS_GRID,
  SLOPE_XYSCALE_ZERO_AXIS,
  SLOPE_XYSCALE_FRAME_LINE
};

struct _SlopeXyScaleClass
{
  SlopeScaleClass parent_class;
};

G_DECLARE_DERIVABLE_TYPE(SlopeXyScale, slope_xyscale, SLOPE, XYSCALE, SlopeScale)

SlopeScale *slope_xyscale_new(void);

SlopeScale *slope_xyscale_new_axis(const char *x_title,
                                   const char *y_title,
                                   const char *top_title);

SlopeItem *slope_xyscale_get_axis(SlopeXyScale *self, int axis_id);

void slope_xyscale_set_axis(SlopeXyScale *self, int axis_flag);

void slope_xyscale_set_x_range(SlopeXyScale *self, double min, double max);

void slope_xyscale_set_y_range(SlopeXyScale *self, double min, double max);

void slope_xyscale_set_interaction(SlopeXyScale *self, int interaction);

G_END_DECLS

#endif /* SLOPE_XYSCALE_H */
