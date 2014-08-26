/*
 * StackTracePrinter.h
 *
 *  Created on: Aug 26, 2014
 *      Author: kunling
 */

#ifndef STACKTRACEPRINTER_H_
#define STACKTRACEPRINTER_H_

namespace LingccTaichi {

// TODO: This StackTrace Printer currently only perfectly works for C program, not C++.
class StackTracePrinter {
 public:
  StackTracePrinter();
  virtual ~StackTracePrinter();
  void print_trace(FILE *out, const char *file, int line);

};

} /* namespace LingccTaichi */

#endif /* STACKTRACEPRINTER_H_ */
