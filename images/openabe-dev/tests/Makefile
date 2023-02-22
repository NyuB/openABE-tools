CC=g++
CFLAGS=-Wall

googletest/build/gtest-all.o:
    ${CC} -c googletest/src/gtest-all.cc -I googletest/include -I googletest -o googletest/build/gtest-all.o

googletest/build/gtest_main.o:
    ${CC} -c googletest/src/gtest_main.cc -I googletest/include -o googletest/build/gtest_main.o


googletest/build/libgtest.a: googletest/build/gtest-all.o
    ar rs googletest/build/libgtest.a googletest/build/gtest-all.o

googletest/build/libgtest_main.a: googletest/build/gtest_main.o
    ar rs googletest/build/libgtest_main.a googletest/build/gtest_main.o

test-runner: libgtest.a libgtest_main.a oabe_spec.cpp
    ${CC} ${CFLAGS} oabe_spec.cpp -I googletest/include -lgtest_main -lgtest -L googletest/build -o test-runner 
