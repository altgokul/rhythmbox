NULL =

plugindir = $(PLUGINDIR)/daap
plugindatadir = $(PLUGINDATADIR)/daap
plugin_LTLIBRARIES = libdaap.la

libdaap_la_SOURCES = \
	rb-daap-container-record.c		  \
	rb-daap-container-record.h		  \
	rb-daap-plugin.c			  \
	rb-daap-plugin.h			  \
	rb-daap-record.c			  \
	rb-daap-record.h			  \
	rb-daap-record-factory.c		  \
	rb-daap-record-factory.h		  \
	rb-daap-sharing.c			  \
	rb-daap-sharing.h			  \
	rb-daap-source.c			  \
	rb-daap-source.h			  \
	rb-daap-src.c				  \
	rb-daap-src.h				  \
	rb-dmap-container-db-adapter.c		  \
	rb-dmap-container-db-adapter.h		  \
	rb-dacp-pairing-page.c			  \
	rb-dacp-pairing-page.h			  \
	rb-dacp-player.c			  \
	rb-dacp-player.h			  \
	rb-rhythmdb-dmap-db-adapter.c             \
	rb-rhythmdb-dmap-db-adapter.h             \
	rb-rhythmdb-query-model-dmap-db-adapter.c \
	rb-rhythmdb-query-model-dmap-db-adapter.h \
	$(NULL)

libdaap_la_LDFLAGS = $(PLUGIN_LIBTOOL_FLAGS)
libdaap_la_LIBTOOLFLAGS = --tag=disable-static
libdaap_la_LIBADD = 					\
	$(top_builddir)/shell/librhythmbox-core.la	\
	$(DMAPSHARING_LIBS)                             \
	$(RHYTHMBOX_LIBS)

AM_CPPFLAGS = 						\
        -DGNOMELOCALEDIR=\""$(datadir)/locale"\"        \
	-DG_LOG_DOMAIN=\"Rhythmbox\"		 	\
	-I$(top_srcdir) 				\
	-I$(top_srcdir)/lib                        	\
	-I$(top_srcdir)/metadata                       	\
	-I$(top_srcdir)/player                       	\
	-I$(top_srcdir)/rhythmdb                       	\
	-I$(top_srcdir)/widgets                    	\
	-I$(top_srcdir)/sources                    	\
	-I$(top_srcdir)/iradio                    	\
	-I$(top_srcdir)/podcast                    	\
	-I$(top_srcdir)/remote				\
	-I$(top_builddir)/remote			\
	-I$(top_builddir)/lib   			\
	-I$(top_srcdir)/plugins				\
	-I$(top_srcdir)/shell				\
	-I$(top_srcdir)/plugins				\
	-DPIXMAP_DIR=\""$(datadir)/pixmaps"\"		\
	-DSHARE_DIR=\"$(pkgdatadir)\"                   \
	-DDATADIR=\""$(datadir)"\"			\
	$(DMAPSHARING_CFLAGS)				\
	$(RHYTHMBOX_CFLAGS)

if USE_LIBSECRET
libdaap_la_LIBADD += $(LIBSECRET_LIBS)
AM_CPPFLAGS += $(LIBSECRET_CFLAGS)
endif

gtkbuilderdir = $(plugindatadir)
gtkbuilder_DATA = daap-prefs.ui daap-toolbar.ui

plugin_in_files = daap.plugin.in

%.plugin: %.plugin.in $(INTLTOOL_MERGE) $(wildcard $(top_srcdir)/po/*po) ; $(INTLTOOL_MERGE) $(top_srcdir)/po $< $@ -d -u -c $(top_builddir)/po/.intltool-merge-cache

plugin_files = $(plugin_in_files:.plugin.in=.plugin)

BUILT_SOURCES = $(plugin_files)

plugin_DATA = $(plugin_files)

plugindata_DATA = 					\
	$(top_srcdir)/plugins/daap/remote-icon.png	\
	$(NULL)

EXTRA_DIST = 						\
	$(gtkbuilder_DATA)				\
	$(top_srcdir)/plugins/daap/remote-icon.png	\
	$(uixml_DATA)		\
	$(plugin_in_files)	\
	$(NULL)

CLEANFILES = 			\
	$(BUILT_SOURCES)	\
	$(NULL)

DISTCLEANFILES =		\
	$(BUILT_SOURCES)	\
	$(NULL)
