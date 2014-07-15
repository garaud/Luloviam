
LuLoviam
########

**LuLoviam** is a version of the LLVM_ tutorial -- just replace each consonant
of "tutorial" by the four following letters: L.L.V.M.

.. _LLVM: http://llvm.org/

About
=====

* This code is a version of the LLVM Kaleidoscope tutorial with **C++11**
  features and TDD_. See http://llvm.org/docs/tutorial/

* A word that I keep in mind after reading books about TDD_ is
  **expressiveness**. I'll try to produce expressive code enough.

* Each tag is related to a tutorial chapter.

* The tests are carried out with the GTest_ unittest framework.

* A reference that I recently read about TDD in C++ is `Modern C++ Programming
  with Test-Driven Development: Code Better, Sleep Better
  <http://pragprog.com/book/lotdd/modern-c-programming-with-test-driven-development>`_
  by Jeff Langr, well written and interesting in my point of view.

.. _TDD: http://en.wikipedia.org/wiki/Test-driven_development
.. _GTest: http://code.google.com/p/googletest

Compile It
==========

* I use CMake_ to compile the code. So just do:

::

  > mkdir mybuild
  > cmake /path/to/source
  > make

* Test on Debian with GCC (4.7, 4.8, 4.9) and Clang (3.2, 3.3) --- I really don't
  care about other compilers. Thus I've not tested.

* I use the Debian package of GTest (where the sources are
  ``/usr/src/gtest``). Thus, the CMakeLists.txt in ``tests`` is supposed to
  find the GTest source at ``/usr/src/gtest``. I could improve the CMake
  ExternalProject configuration in order to find the source with a dedicated
  URL.

.. _CMake: http://www.cmake.org/

Launch It
=========

* You can use CTest to launch the different unittest files. Go to the
  ``tests`` folder in your *build* directory and do:

::

  > ctest
