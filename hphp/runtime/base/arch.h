/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-2015 Facebook, Inc. (http://www.facebook.com)     |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/
#ifndef incl_HPHP_ARCH_H
#define incl_HPHP_ARCH_H

#include "hphp/runtime/base/runtime-option.h"

namespace HPHP {

///////////////////////////////////////////////////////////////////////////////

enum class Arch {
  X64,
  ARM,
};

inline Arch arch() {
  if (RuntimeOption::EvalSimulateARM) return Arch::ARM;
  return Arch::X64;
}

/*
 * Macro for defining easy arch-dispatch wrappers.
 */
#define ARCH_SWITCH_CALL(func, ...)  \
  switch (arch()) {                       \
    case Arch::X64:                       \
      return x64::func(__VA_ARGS__);      \
    case Arch::ARM:                       \
      return arm::func(__VA_ARGS__);      \
  }                                       \
  not_reached();

///////////////////////////////////////////////////////////////////////////////

}

#endif
