ACLOCAL_AMFLAGS = --install -I m4 ${ACLOCAL_FLAGS}

DISTCHECK_CONFIGURE_FLAGS = --disable-schemas-install --enable-gtk-doc --disable-scrollkeeper
distuninstallcheck_listfiles = find . -type f -print | grep -v '^\./var/scrollkeeper'

SUBDIRS = lib metadata rhythmdb widgets sources podcast \
	backends shell bindings sample-plugins plugins remote data po help tests doc

# what?
#INCLUDES = rhythmbox.h

EXTRA_DIST = 			\
	autogen.sh		\
	config.h.in		\
	rhythmbox.pc.in		\
	MAINTAINERS		\
	MAINTAINERS.old		\
	DOCUMENTERS		\
	INTERNALS

DISTCLEANFILES =			\
	ChangeLog			\
	intltool-extract		\
	intltool-merge			\
	intltool-update

CLEANFILES = ./po/.intltool-merge-cache

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = rhythmbox.pc

CHANGELOG_START = RHYTHMBOX-0_12_0

ChangeLog:
	@echo Creating $@
	@if test -d "$(srcdir)/.git"; then \
	  (GIT_DIR=$(top_srcdir)/.git ./missing --run git log $(CHANGELOG_START).. --stat) > $@.tmp \
	  && mv -f $@.tmp $@ \
	  || ($(RM) $@.tmp; \
	      echo Failed to generate ChangeLog.  Your ChangeLog may be outdated >&2; \
	      (test -f $@ || echo git-log is required to generate this file >> $@)); \
	else \
	  test -f $@ || \
	  (echo A git checkout and git-log is required to generate ChangeLog >&2 && \
	  echo A git checkout and git-log is required to generate this file >> $@); \
	fi

.PHONY: ChangeLog

