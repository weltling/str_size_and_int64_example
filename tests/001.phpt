--TEST--
Check for str_size_and_int64 presence
--SKIPIF--
<?php if (!extension_loaded("str_size_and_int64")) print "skip"; ?>
--FILE--
<?php 
echo "str_size_and_int64 extension is available";
/*
	you can add regression tests for your extension here

  the output of your test code has to be equal to the
  text in the --EXPECT-- section below for the tests
  to pass, differences between the output and the
  expected text are interpreted as failure

	see php5/README.TESTING for further information on
  writing regression tests
*/
?>
--EXPECT--
str_size_and_int64 extension is available
