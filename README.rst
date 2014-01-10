
About
=====

* This code is a try to do the LLVM Kaleidoscope tutorial with C++11 features
and TDD. See http://llvm.org/docs/tutorial/

* Each tag is related to a tutorial chapter.

* The tests are carried out with the GTest_ unittest framework.

* A reference that I recently read about TDD in C++ is `Modern C++ Programming
  with Test-Driven Development: Code Better, Sleep Better
  <http://pragprog.com/book/lotdd/modern-c-programming-with-test-driven-development>`_
  by Heff Langr, well written and interesting in my point of view.

.. _GTest: http://code.google.com/p/googletest

Compile It
==========

* I use CMake to compile the code. So just do:

::

  > mkdir mybuild
  > cmake /path/to/source
  > make

* Test on Debian with GCC (4.7, 4.8) and Clang (3.2, 3.3) --- I really don't
  care about other compilers. Thus I've not tested.

Launch It
=========

* I use CTest to launch the different unittest files. Go to the ``tests`` folder
  in your *build* directory and do:

::

  > ctest
