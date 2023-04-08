cmake_minimum_required(VERSION 3.22)
project(QICFasta C)

set(CMAKE_C_STANDARD 99)

include_directories(lib programs)

set(CMAKE_C_FLAGS_RELEASE "-O3 -Wall -Wextra -Wcast-qual -Wcast-align -Wshadow -Wstrict-aliasing=1 -Wswitch-enum -Wstrict-prototypes -Wundef")

add_executable(fse programs/bench.c programs/commandline.c programs/fileio.c programs/xxhash.c programs/zlibh.c
        lib/entropy_common.c lib/hist.c
        lib/fse_decompress.c lib/fse_compress.c lib/fseU16.c
        lib/huf_compress.c lib/huf_decompress.c)

add_executable(qic qic/main.c lib/fse_decompress.c lib/fse_compress.c lib/fseU16.c lib/entropy_common.c lib/hist.c)