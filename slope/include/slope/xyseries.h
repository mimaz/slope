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

#ifndef SLOPE_XYSERIES_H
#define SLOPE_XYSERIES_H

#include <slope/item.h>

G_BEGIN_DECLS

#define SLOPE_TYPE_XYSERIES (slope_xyseries_get_type())

typedef enum _SlopeXySeriesMode SlopeXySeriesMode;

enum _SlopeXySeriesMode 
{
  SLOPE_SERIES_LINE       = 0x00000001,
  SLOPE_SERIES_CIRCLES    = 0x00000002,
  SLOPE_SERIES_SQUARES    = 0x00000004,
  SLOPE_SERIES_AREAUNDER  = 0x00000008,
  SLOPE_SERIES_BIGSYMBOL  = 0x00000010,
  SLOPE_SERIES_BIGSQUARES = SLOPE_SERIES_SQUARES | SLOPE_SERIES_BIGSYMBOL,
  SLOPE_SERIES_BIGCIRCLES = SLOPE_SERIES_CIRCLES | SLOPE_SERIES_BIGSYMBOL
};

struct _SlopeXySeriesClass
{
  SlopeItemClass parent_class;
};

G_DECLARE_DERIVABLE_TYPE(SlopeXySeries, slope_xyseries, SLOPE, XYSERIES, SlopeItem)

SlopeItem *slope_xyseries_new(void);

SlopeItem *slope_xyseries_new_filled(const char *  name,
                                     const double *x_vec,
                                     const double *y_vec,
                                     long          n_pts,
                                     const char *  style);

void slope_xyseries_set_data(SlopeXySeries *self,
                             const double * x_vec,
                             const double * y_vec,
                             long           n_pts);

void slope_xyseries_update_data(SlopeXySeries *self,
                                const double * x_vec,
                                const double * y_vec,
                                long           n_pts);

void slope_xyseries_set_style(SlopeXySeries *self, const char *style);

void slope_xyseries_update(SlopeXySeries *self);

G_END_DECLS

#endif /* SLOPE_XYSERIES_H */
