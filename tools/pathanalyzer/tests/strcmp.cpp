// Copyright 2019 Carnegie Mellon University.  See LICENSE file for terms.

#include "test.hpp"

int main () {
  path_start ();
  char str[20];

// str is intentionally uninitialized; this tests path analysis on uninit memory.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuninitialized"
  if (__builtin_strcmp (str, "Hello world!") == 0) {
    path_goal ();
  }
#pragma GCC diagnostic pop

  str[4] = 0;

  if (__builtin_strcmp (str, "Hello world!") == 0) {
    path_nongoal ();
  }
  return 0;
}
