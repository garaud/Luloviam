
Tasks Lists
###########

Source code
===========

Tests List
==========

List of tests to write:

* A line such as ``def func(value, name)`` should return the following tokens:
  'def', 'unknown', 'identifier', 'unknown', 'identifier', 'unknown' with the
  related string value. Name:
  ``list_of_tokens_and_str_values_for_function_declaration``

* Line with no whitespace should return the well token,
  e.g. ``name=12.3``. Should **fail** because I read word by word (instead of char
  by char).  Name: ``should_recognize_tokens_in_no_whitespace_line``.
