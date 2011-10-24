.PHONY: distclean clean libmsdoc libmsdoc-php man
all: libmsdoc

libmsdoc:
	make -C src

libmsdoc-php:
	make -C php

man:
	make -C man

distclean:
	make -C src distclean
	make -C php distclean
	make -C man distclean
	rm -r Makefile autom4te.cache config.log config.status

clean:
	make -C src clean
	make -C php clean
	make -C man clean

