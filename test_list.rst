
Tests List
==========

* Line with no whitespace should return the well token,
  e.g. ``name=12.3``. Should **fail** because I read line by line and word by word
  (instead of char by char).

* Three successive ``nextToken`` should work for a line such as ``value = 2.``:
  the identifier token, ASCII code for '=' and the number token. Should **fail**
  (for the quite same reasons as above).
