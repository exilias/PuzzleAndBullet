###########################################################################
#
#   Makefile for sample
#
###########################################################################

#現在のディレクトリからランタイムルートディレクトリへの相対パス
ROOTDIR = ../../..

# CGROM ディレクトリ
CGROMDIR = .
CGROM = $(CGROMDIR)/export_0.bin

# モジュール群
C_SRC = main.c pad.c game.c field.c export.c

include $(ROOTDIR)/include/makefile.def

## Makefile ends here.
