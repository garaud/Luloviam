
Tasks Lists
###########

Source code
===========

* Store the string/char related to a returned Token.

Tests List
==========

List of tests to write:

* Line with no whitespace should return the well token,
  e.g. ``name=12.3``. Should **fail** because I read line by line and word by word
  (instead of char by char).
  Name: ``should_recognize_tokens_in_no_whitespace_line``.

* Check the string/char related to a specific Token (for instance the
  ``Unknown`` token which should be related to a ASCII char, or an other token
  such as ``Identifier`` or ``DefToken``).

* Check the value of the stored float when you have a "number" token.
