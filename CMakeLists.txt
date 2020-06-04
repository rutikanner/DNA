cmake_minimum_required(VERSION 3.10)
project(DnaSequence)

set(CMAKE_CXX_STANDARD 14)

add_executable(DnaSequence main.cpp dna_sequence.cpp dna_sequence.h nucleotide.cpp nucleotide.h test_dna.cpp test_dna.h val_error.cpp val_error.h)