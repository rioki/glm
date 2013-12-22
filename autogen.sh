#!/bin/sh

set -x

aclocal
autoconf
automake --add-missing --copy
