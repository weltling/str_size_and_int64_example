dnl $Id$
dnl config.m4 for extension str_size_and_int64

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(str_size_and_int64, for str_size_and_int64 support,
dnl Make sure that the comment is aligned:
dnl [  --with-str_size_and_int64             Include str_size_and_int64 support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(str_size_and_int64, whether to enable str_size_and_int64 support,
dnl Make sure that the comment is aligned:
[  --enable-str_size_and_int64           Enable str_size_and_int64 support])

if test "$PHP_STR_SIZE_AND_INT64" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-str_size_and_int64 -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/str_size_and_int64.h"  # you most likely want to change this
  dnl if test -r $PHP_STR_SIZE_AND_INT64/$SEARCH_FOR; then # path given as parameter
  dnl   STR_SIZE_AND_INT64_DIR=$PHP_STR_SIZE_AND_INT64
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for str_size_and_int64 files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       STR_SIZE_AND_INT64_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$STR_SIZE_AND_INT64_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the str_size_and_int64 distribution])
  dnl fi

  dnl # --with-str_size_and_int64 -> add include path
  dnl PHP_ADD_INCLUDE($STR_SIZE_AND_INT64_DIR/include)

  dnl # --with-str_size_and_int64 -> check for lib and symbol presence
  dnl LIBNAME=str_size_and_int64 # you may want to change this
  dnl LIBSYMBOL=str_size_and_int64 # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $STR_SIZE_AND_INT64_DIR/lib, STR_SIZE_AND_INT64_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_STR_SIZE_AND_INT64LIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong str_size_and_int64 lib version or lib not found])
  dnl ],[
  dnl   -L$STR_SIZE_AND_INT64_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(STR_SIZE_AND_INT64_SHARED_LIBADD)

  PHP_NEW_EXTENSION(str_size_and_int64, str_size_and_int64.c, $ext_shared)
fi
