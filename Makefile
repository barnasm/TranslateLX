CC = clang++#g++

PKGCONFIG += gtk+-3.0

EXE = TranslateLX

SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = tests

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CPPFLAGS += -I./include 
CFLAGS += -std=c++11 -Wall `pkg-config --cflags gtk+-3.0`
LDFLAGS += -L./lib \
	   -I/home/michal/cppLibs/curl-7.49.1/curl/include/ \
	   -L/home/michal/cppLibs/curl-7.49.1/curl/lib/ \
	   -L/home/michal/cppLibs/openssl-master/openssl/lib

LDLIBS += `pkg-config --libs gtk+-3.0` -lcurl -lssl -lcrypto

export LD_LIBRARY_PATH=/home/michal/cppLibs/curl-7.49.1/curl/lib/:/home/michal/cppLibs/openssl-master/openssl/lib

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(CPPFLAGS) $^ $(LDLIBS) -o $@

test: $(TEST_DIR)/tests.cpp

$(TEST_DIR)/tests.cpp: obj/diByGlosbe.o obj/wiByCurl.o
	LD_LIBRARY_PATH=/home/michal/cppLibs/curl-7.49.1/curl/lib/ \
	$(CC) $(CFLAGS) \
			-I/home/michal/cppLibs/boost_1_61_0/ \
			-I/home/michal/cppLibs/curl-7.49.1/curl/include/ \
			-L/home/michal/cppLibs/curl-7.49.1/curl/lib/ \
			-L/home/michal/cppLibs/openssl-master/openssl/lib \
			$@ $^ \
			$(LDLIBS) \
			-o tests/tests
#g++ -I/home/michal/Pulpit/boost_1_61_0/ tests/tests.cpp -L/home/michal/Pulpit/boost_1_61_0/stage/lib/libboost_unit_test_framework.so -o hello

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -c $< $(LDLIBS) -o $@		

clean:
	$(RM) $(OBJ)
