
Tasks Lists
###########

* use C++11 feature ``enum class`` instead of ``enum``. **Problem**: you can not
  convert the enum to an integer. **Question**: what kind of token should I
  return if a read character which is not recognize as a toke. For now, I
  decided to return the int ASCII code.

* Refactoring: read char by char instead of word by word? Or keep static
  attributes to store the line and the stream cursor?


Tests List
==========

List of tests to write:

* Line with no whitespace should return the well token,
  e.g. ``name=12.3``. Should **fail** because I read line by line and word by word
  (instead of char by char).
  Name: ``should_recognize_tokens_in_no_whitespace_line``.
