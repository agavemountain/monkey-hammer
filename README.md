# monkey-hammer

Over the years, I have written many hackis-quick-and-dirty utilities to 
generate code, and automate various development tasks.  This is a collection
of those tools, completely rewritten.

This project is always under construction, and this isn't production quality code, so don't expect great design patterns or idioms -- this is just a collection of hackish scripts, utilities, and idoms to get work done faster.

### Utilities

- [Code commenting formatter utility](https://github.com/agavemountain/monkey-hammer/blob/master/doc/monkey-comment.md).  This is a simple
  utility for formatting text as a comment.  It can take standard input or a file and generate comments for whatever computer language
  desired.

### Requirements

    * Doxygen 1.8.0+ (for markdown support) and GraphViz.
    * GNU GCC toolchain
    * Git (obviously)
    * CPPUNIT (for unit tests)
     
### Building and Installing

To build the software:

```bash
  $ mkdir build
  $ cd build
  $ cmake ..
  $ make
```

To make the doxygen documentation: 

```bash
  $ make doc
```

To install:
```bash
  $ make install
```

To uninstall:
```bash
   $ make uninstall
```

### Running Unit Tests

This project contains some unit tests.  To execute, use the cmake
test harness.

```bash
  $ ctest -V
```
    