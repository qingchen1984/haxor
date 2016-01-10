#include "haxor/haxor.hh"
#include "haxor/mem.hh"
#include <cstdlib>
#include <cstring>
#include <string>

namespace haxor {
  mem::mem() {
    data = NULL;
    size = 0;
  }

  mem::~mem() {
    free(data);
  }

  word_t mem::read_word(const uint64_t addr) const {
    validate_addr(addr);
    word_t temp;
    memcpy(&temp, data + addr, word_size_t);
    return temp;
  }

  void mem::write_word(const uint64_t addr, const word_t value) {
    validate_addr(addr);
    memcpy(data + addr, &value, word_size_t);
  }

  std::string mem::read_string(const uint64_t addr) const {
    std::string result = "";

    for (uint64_t offset = 0; ; offset += sizeof(word_t)) {
      word_t item = read_word(addr + offset);
      if (item == 0) {
        break;
      }

      result += item;
    }

    return result;
  }

  void mem::write_string(const uint64_t addr, const std::string value) {
    size_t offset = 0;
    for (size_t i = 0; i < value.size(); i++) {
      write_word(addr + offset, value[i]);
      offset += sizeof(word_t);
    }
    write_word(addr + offset, 0); // ending '\0'
  }

  void mem::alloc(const uint64_t space) {
    if (space % word_size_t != 0) {
      throw mem_misalign_error();
    }

    data = (int8_t*)realloc(data, size + space);
    memset(data + size, 0, space);
    size += space;
  }

  uint64_t mem::get_size() {
    return size;
  }

  void mem::validate_addr(const uint64_t addr) const {
    if (addr > size - word_size_t) {
      throw mem_range_error();
    }
  }
}