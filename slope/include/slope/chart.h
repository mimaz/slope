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

#ifndef SLOPE_CHART_H
#define SLOPE_CHART_H

#include <slope/view.h>

G_BEGIN_DECLS

#define SLOPE_TYPE_CHART (slope_chart_get_type())

struct _SlopeChartClass
{
  GtkWindowClass parent_class;
};

G_DECLARE_DERIVABLE_TYPE(SlopeChart, slope_chart, SLOPE, CHART, GtkWindow)

GtkWidget *slope_chart_new();

GtkWidget *slope_chart_new_detailed(const gchar *title, int width, int height);

SlopeFigure *slope_chart_get_figure(SlopeChart *self);

GtkWidget *slope_chart_get_header(SlopeChart *self);

GtkWidget *slope_chart_get_view(SlopeChart *self);

void slope_chart_redraw(SlopeChart *self);

void slope_chart_add_scale(SlopeChart *self, SlopeScale *scale);

void slope_chart_write_to_png(SlopeChart *self,
                              const char *filename,
                              int         width,
                              int         height);

G_END_DECLS

#endif /* SLOPE_CHART_H */
