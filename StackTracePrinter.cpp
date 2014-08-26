/*
 * StackTracePrinter.cpp
 *
 *  Created on: Aug 26, 2014
 *      Author: kunling
 */

#if defined(__linux__)
#include <execinfo.h>
#endif

#include "StackTracePrinter.h"

namespace LingccTaichi {

StackTracePrinter::StackTracePrinter() {
  // TODO Auto-generated constructor stub

}

StackTracePrinter::~StackTracePrinter() {
  // TODO Auto-generated destructor stub
}


void StackTracePrinter::print_trace(FILE *out, const char *file, int line) {
  const size_t max_depth = 100;
  size_t stack_depth;
  void *stack_addrs[max_depth];
  char **stack_strings;

#if defined(__linux__) // These two function call only works on Unix/Linux platform
  stack_depth = backtrace(stack_addrs, max_depth);
  stack_strings = backtrace_symbols(stack_addrs, stack_depth);
#endif

  fprintf(out, "Call stack from %s:%d:\n", file, line);

  for (size_t i = 1; i < stack_depth; i++) {
    fprintf(out, "    %s\n", stack_strings[i]);
  }
  free(stack_strings); // malloc()ed by backtrace_symbols
  fflush(out);

}

} /* namespace LingccTaichi */
