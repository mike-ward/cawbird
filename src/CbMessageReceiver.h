/*  This file is part of Cawbird, a Gtk+ linux Twitter client forked from Corebird.
 *  Copyright (C) 2017 Timm Bäder (Corebird)
 *
 *  Cawbird is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Cawbird is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with cawbird.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __CB_MESSAGE_RECEIVER_H__
#define __CB_MESSAGE_RECEIVER_H__

#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "CbTypes.h"

#define CB_TYPE_MESSAGE_RECEIVER (cb_message_receiver_get_type())

G_DECLARE_INTERFACE (CbMessageReceiver, cb_message_receiver, CB, MESSAGE_RECEIVER, GObject)

struct _CbMessageReceiverInterface
{
  GTypeInterface base_iface;

  void (*stream_message_received) (CbMessageReceiver   *self,
                                   CbStreamMessageType  type,
                                   JsonNode            *node);
};

void cb_message_receiver_stream_message_received (CbMessageReceiver   *self,
                                                  CbStreamMessageType  type,
                                                  JsonNode            *node);


#endif
