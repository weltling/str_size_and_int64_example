/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2013 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_str_size_and_int64.h"

/* If you declare any globals in php_str_size_and_int64.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(str_size_and_int64)
*/

/* True global resources - no need for thread safety here */
static int le_str_size_and_int64;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("str_size_and_int64.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_str_size_and_int64_globals, str_size_and_int64_globals)
    STD_PHP_INI_ENTRY("str_size_and_int64.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_str_size_and_int64_globals, str_size_and_int64_globals)
PHP_INI_END()
*/
/* }}} */

PHP_FUNCTION(confirm_str_size_and_int64_string_test)
{
	char *arg = NULL;
	php_size_t arg_len, len;
	char *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	len = spprintf(&strg, 0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "str_size_and_int64", arg);
	RETURN_STRINGL(strg, len, 0);
}

PHP_FUNCTION(confirm_str_size_and_int64_int_test)
{
	php_int_t i;
	php_size_t len;
	char *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &i) == FAILURE) {
		return;
	}

	len = spprintf(&strg, 0, ZEND_INT_FMT " is the param", i);
	RETURN_STRINGL(strg, len, 0);
}

PHP_FUNCTION(confirm_str_size_and_int64_array_test)
{
	php_int_t  i, j;
	char	   *str_key;
	php_uint_t num_key;
	zval       **elem = NULL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &i) == FAILURE) {
		return;
	}

	array_init(return_value);

	for (j = 0; j < i; j++) {
		add_next_index_long(return_value, j);
	}

	zend_hash_internal_pointer_reset(Z_ARRVAL_P(return_value));
	while (zend_hash_get_current_data(Z_ARRVAL_P(return_value), (void **)&elem) == SUCCESS) {
		zend_hash_get_current_key(Z_ARRVAL_P(return_value), &str_key, &num_key, 0);

		Z_LVAL_PP(elem) += 42;

		zend_hash_move_forward(Z_ARRVAL_P(return_value));
	}
}

PHP_FUNCTION(confirm_str_size_and_int64_path_test)
{
	php_size_t len;
	char *str;
	php_stat_t st;

#if PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION <= 3
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &str, &len) == FAILURE) {
#else
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "p", &str, &len) == FAILURE) {
#endif
		return;
	}

	zend_stat(str, &st);

	RETURN_LONG(st.st_size);

}

/* {{{ php_str_size_and_int64_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_str_size_and_int64_init_globals(zend_str_size_and_int64_globals *str_size_and_int64_globals)
{
	str_size_and_int64_globals->global_value = 0;
	str_size_and_int64_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(str_size_and_int64)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(str_size_and_int64)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(str_size_and_int64)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(str_size_and_int64)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(str_size_and_int64)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "str_size_and_int64 support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ str_size_and_int64_functions[]
 *
 * Every user visible function must have an entry in str_size_and_int64_functions[].
 */
const zend_function_entry str_size_and_int64_functions[] = {
	PHP_FE(confirm_str_size_and_int64_string_test,	NULL)
	PHP_FE(confirm_str_size_and_int64_int_test, NULL)
	PHP_FE(confirm_str_size_and_int64_array_test, NULL)
	PHP_FE(confirm_str_size_and_int64_path_test, NULL)
	PHP_FE_END	/* Must be the last line in str_size_and_int64_functions[] */
};
/* }}} */

/* {{{ str_size_and_int64_module_entry
 */
zend_module_entry str_size_and_int64_module_entry = {
	STANDARD_MODULE_HEADER,
	"str_size_and_int64",
	str_size_and_int64_functions,
	PHP_MINIT(str_size_and_int64),
	PHP_MSHUTDOWN(str_size_and_int64),
	PHP_RINIT(str_size_and_int64),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(str_size_and_int64),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(str_size_and_int64),
	PHP_STR_SIZE_AND_INT64_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_STR_SIZE_AND_INT64
ZEND_GET_MODULE(str_size_and_int64)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
