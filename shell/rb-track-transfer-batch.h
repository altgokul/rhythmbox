/*
 *  Copyright (C) 2010 Jonathan Matthew  <jonathan@d14n.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  The Rhythmbox authors hereby grants permission for non-GPL compatible
 *  GStreamer plugins to be used and distributed together with GStreamer
 *  and Rhythmbox. This permission is above and beyond the permissions granted
 *  by the GPL license by which Rhythmbox is covered. If you modify this code
 *  you may extend this exception to your version of the code, but you are not
 *  obligated to do so. If you do not wish to do so, delete this exception
 *  statement from your version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA.
 *
 */

#ifndef __RB_TRACK_TRANSFER_BATCH_H
#define __RB_TRACK_TRANSFER_BATCH_H

#include <rhythmdb/rhythmdb.h>
#include <sources/rb-source.h>

G_BEGIN_DECLS

#define RB_TYPE_TRACK_TRANSFER_BATCH           (rb_track_transfer_batch_get_type ())
#define RB_TRACK_TRANSFER_BATCH(o)             (G_TYPE_CHECK_INSTANCE_CAST ((o), RB_TYPE_TRACK_TRANSFER_BATCH, RBTrackTransferBatch))
#define RB_TRACK_TRANSFER_BATCH_CLASS(k)       (G_TYPE_CHECK_CLASS_CAST((k), RB_TYPE_TRACK_TRANSFER_BATCH, RBTrackTransferBatchClass))
#define RB_IS_TRACK_TRANSFER_BATCH(o)          (G_TYPE_CHECK_INSTANCE_TYPE ((o), RB_TYPE_TRACK_TRANSFER_BATCH))
#define RB_IS_TRACK_TRANSFER_BATCH_CLASS(k)    (G_TYPE_CHECK_CLASS_TYPE ((k), RB_TYPE_TRACK_TRANSFER_BATCH))
#define RB_TRACK_TRANSFER_BATCH_GET_CLASS(o)   (G_TYPE_INSTANCE_GET_CLASS ((o), RB_TYPE_TRACK_TRANSFER_BATCH, RBTrackTransferBatchClass))

typedef struct _RBTrackTransferBatch RBTrackTransferBatch;
typedef struct _RBTrackTransferBatchClass RBTrackTransferBatchClass;
typedef struct _RBTrackTransferBatchPrivate RBTrackTransferBatchPrivate;

struct _RBTrackTransferBatch
{
	GObject parent;
	RBTrackTransferBatchPrivate *priv;
};

struct _RBTrackTransferBatchClass
{
	GObjectClass parent_class;

	/* signals */
	void	(*started)		(RBTrackTransferBatch *batch);
	void	(*cancelled)		(RBTrackTransferBatch *batch);
	void	(*complete)		(RBTrackTransferBatch *batch);

	char *  (*get_dest_uri)		(RBTrackTransferBatch *batch,
					 RhythmDBEntry *entry,
					 const char *mediatype,
					 const char *extension);
	gboolean (*overwrite_prompt)	(RBTrackTransferBatch *batch,
					 GFile *dest_file);
	void	(*track_started)	(RBTrackTransferBatch *batch,
					 RhythmDBEntry *entry,
					 const char *dest);
	void	(*track_progress)	(RBTrackTransferBatch *batch,
					 RhythmDBEntry *entry,
					 const char *dest,
					 int done,
					 int total,
					 double fraction);
	void	(*track_done)		(RBTrackTransferBatch *batch,
					 RhythmDBEntry *entry,
					 const char *dest,
					 guint64 dest_size,
					 GError *error);
};

GType			rb_track_transfer_batch_get_type	(void);

RBTrackTransferBatch *	rb_track_transfer_batch_new		(GList *media_type_list,
								 const char * const *media_types,
								 RBSource *source,
								 RBSource *destination);
void			rb_track_transfer_batch_add		(RBTrackTransferBatch *batch,
								 RhythmDBEntry *entry);

guint			rb_track_transfer_batch_check_media_types (RBTrackTransferBatch *batch);
void			rb_track_transfer_batch_start		(RBTrackTransferBatch *batch,
								 GObject *queue);	/* eh */
void			rb_track_transfer_batch_cancel		(RBTrackTransferBatch *batch);
gboolean		rb_track_transfer_batch_next		(RBTrackTransferBatch *batch);

G_END_DECLS

#endif /* __RB_TRACK_TRANSFER_BATCH_H */