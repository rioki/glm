
AC_INIT([glm], [0.1.0], [https://github.com/rioki/glm/issues])
AC_CONFIG_MACRO_DIR([m4])
AC_CANONICAL_HOST

AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AM_SILENT_RULES([yes])

AC_LANG([C++])
AC_PROG_CXX

AC_CHECK_HEADER([rtest.h])
AC_CHECK_LIB([rtest], [main], [TEST_LIBS="$TEST_LIBS -lrtest"], AC_MSG_WARN([rtest not found]))

AC_SUBST(TEST_LIBS)

AC_CONFIG_FILES([Makefile])

AC_OUTPUT
