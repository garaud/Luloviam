
Tasks Lists
###########

* Store the string/char related to a returned Token.

* Store the number (float) related to the token "number".

* Rename a few attributes of the enum class ``KaToken`` ? The name 'token' is
  already in the name of the class. Maybe it's not necessary to use this word as
  part of the attributes such as ``DefToken`` or ``IdentifierToken``.

* Refactoring: read char by char instead of word by word? Or keep static
  attributes to store the line and the stream cursor?


Tests List
==========

List of tests to write:

* Consecutive 'nextToken' should work (for now fail because we read a full line
  for a single 'nextToken' call).

* Line with no whitespace should return the well token,
  e.g. ``name=12.3``. Should **fail** because I read line by line and word by word
  (instead of char by char).
  Name: ``should_recognize_tokens_in_no_whitespace_line``.

* Check the string/char related to a specific Token (for instance the
  ``Unknown`` token which should be related to a ASCII char, or an other token
  such as ``Identifier`` or ``DefToken``).

* Check the value of the stored float when you have a "number" token.
