#!/usr/bin/env bash
./configure --prefix=/usr --sysconfdir=/etc \
      --libexecdir=/usr/lib/rhythmbox \
      --localstatedir=/var --disable-static \
      --disable-daap --enable-python --enable-vala --disable-visualizer --disable-fm-radio \
      --without-mtp --without-brasero --without-webkit --disable-grilo --disable-mpid --enable-debug

