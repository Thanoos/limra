#!/usr/bin/env bash

export LC_ALL=C
TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
BUILDDIR=${BUILDDIR:-$TOPDIR}

BINDIR=${BINDIR:-$BUILDDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

LIMRACOIND=${LIMRACOIND:-$BINDIR/limracoind}
LIMRACOINCLI=${LIMRACOINCLI:-$BINDIR/limracoin-cli}
LIMRACOINTX=${LIMRACOINTX:-$BINDIR/limracoin-tx}
LIMRACOINQT=${LIMRACOINQT:-$BINDIR/qt/limracoin-qt}

[ ! -x $LIMRACOIND ] && echo "$LIMRACOIND not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
LIMVER=($($LIMRACOINCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for limracoind if --version-string is not set,
# but has different outcomes for limracoin-qt and limracoin-cli.
echo "[COPYRIGHT]" > footer.h2m
$LIMRACOIND --version | sed -n '1!p' >> footer.h2m

for cmd in $LIMRACOIND $LIMRACOINCLI $LIMRACOINTX $LIMRACOINQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${LIMVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${LIMVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
