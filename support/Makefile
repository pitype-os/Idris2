include ../config.mk

.PHONY: build build-c build-refc build-urefc build-chez

build: build-c build-refc build-urefc build-chez

build-c:
	@${MAKE} -C c

build-refc:
	@${MAKE} -C refc

build-urefc:
	@${MAKE} -C urefc

build-chez:
	@${MAKE} -C chez

.PHONY: clean clean-c clean-refc clean-urefc clean-chez

clean: clean-c clean-refc clean-chez

clean-c:
	@${MAKE} -C c cleandep

clean-refc:
	@${MAKE} -C refc cleandep

clean-chez:
	@${MAKE} -C chez clean

.PHONY: install install-docs install-racket install-gambit install-js install-c install-refc install-urefc install-chez

install: install-docs install-racket install-gambit install-js install-c install-refc install-urefc install-chez

install-docs:
	mkdir -p ${DESTDIR}${PREFIX}/${NAME_VERSION}/support/docs
	install -m 644 docs/*.css ${DESTDIR}${PREFIX}/${NAME_VERSION}/support/docs

install-racket:
	mkdir -p ${DESTDIR}${PREFIX}/${NAME_VERSION}/support/racket
	install -m 644 racket/* ${DESTDIR}${PREFIX}/${NAME_VERSION}/support/racket

install-gambit:
	mkdir -p ${DESTDIR}${PREFIX}/${NAME_VERSION}/support/gambit
	install -m 644 gambit/* ${DESTDIR}${PREFIX}/${NAME_VERSION}/support/gambit

install-js:
	mkdir -p ${DESTDIR}${PREFIX}/${NAME_VERSION}/support/js
	install -m 644 js/* ${DESTDIR}${PREFIX}/${NAME_VERSION}/support/js

install-c:
	@${MAKE} -C c install

install-refc:
	@${MAKE} -C refc install

install-urefc:
	@${MAKE} -C urefc install

install-chez:
	@${MAKE} -C chez install
