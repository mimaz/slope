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

#ifndef SLOPE_ITEM_H
#define SLOPE_ITEM_H

#include <glib-object.h>
#include <slope/drawing.h>

G_BEGIN_DECLS

#define SLOPE_TYPE_ITEM (slope_item_get_type())

struct _SlopeItemClass
{
  GObjectClass parent_class;

  void (*draw)(SlopeItem *self, cairo_t *cr);
  void (*draw_thumb)(SlopeItem *self, cairo_t *cr, const SlopePoint *pos);
  void (*get_figure_rect)(SlopeItem *self, SlopeRect *rect);
  void (*get_data_rect)(SlopeItem *self, SlopeRect *rect);
  void (*mouse_event)(SlopeItem *self, SlopeMouseEvent *event);
};

G_DECLARE_DERIVABLE_TYPE(SlopeItem, slope_item, SLOPE, ITEM, GObject)

void slope_item_get_figure_rect(SlopeItem *self, SlopeRect *rect);

void slope_item_get_data_rect(SlopeItem *self, SlopeRect *rect);

SlopeFigure *slope_item_get_figure(SlopeItem *self);

SlopeScale *slope_item_get_scale(SlopeItem *self);

void slope_item_add_subitem(SlopeItem *self, SlopeItem *subitem);

GList *slope_item_get_subitem_list(SlopeItem *self);

SlopeItem *slope_item_get_sub_item(SlopeItem *self, const char *name);

gboolean slope_item_get_is_managed(SlopeItem *self);

void slope_item_set_is_managed(SlopeItem *self, gboolean managed);

gboolean slope_item_get_is_visible(SlopeItem *self);

void slope_item_set_is_visible(SlopeItem *self, gboolean visible);

char *slope_item_get_name(SlopeItem *self);

SlopeView *slope_item_get_view(SlopeItem *self);

void slope_item_set_name(SlopeItem *self, const char *name);

void slope_item_detach(SlopeItem *self);

G_END_DECLS

#endif /* SLOPE_ITEM_H */
