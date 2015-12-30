module Haxor
  class Consts
    MAJOR = 0
    MINOR = 2
    PATCH = 0
    GEM_VERSION = "#{MAJOR}.#{MINOR}.#{PATCH}"
    VERSION = (MAJOR << 16) | (MINOR << 8) | PATCH

    ROOT_PATH = __dir__ + '/../..'

    WORD_SIZE = 8 # 64bit
    WORD_UNPACK = 'q<'

    RESERVED_MEM = 2048 # 1024 for CPU, 1024 for IVT
    IVT_ADDR     = 1024

    # OpCode
    OPCODE_CMD_MASK = 0x0000_0000_0000_00ff
    OPCODE_FLG_MASK = 0xffff_ffff_ffff_ff00
    OPCODE_FLG_OFFSET = 8
    OPCODE_FLG_DA = 1 << OPCODE_FLG_OFFSET # dereference A operand
    OPCODE_FLG_DB = 2 << OPCODE_FLG_OFFSET # dereference B operand

    # Flags Registry Flags
    FR_ZERO    = 1 << 0 # a-b == 0
    FR_SIGN    = 1 << 1 # a-b < 0
  end
end
