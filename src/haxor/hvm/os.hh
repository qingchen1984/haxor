#ifndef HAXOR_OS_HH
#define HAXOR_OS_HH

#include "haxor/common/haxor.hh"
#include <vector>
#include <string>

namespace haxor {
  class vm;

  class os {
    public:
    os(vm &vm);
    void syscall();

    private:
    word_t sc_print();
    word_t sc_printi();
    word_t sc_scan();
    word_t sc_scani();
    word_t sc_rand();

    word_t pop();
    void discard_input();

    word_t sp;
    vm &vm;
  };
}

#endif