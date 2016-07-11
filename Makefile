CC = clang++#g++

#CONFIG += link_pkgconfig

#PKGCONFIG += gtk+-3.0
#CPPFLAGS="-I/opt/gtk/include"
#LDFLAGS="-L/opt/gtk/lib"
#PKG_CONFIG_PATH="/opt/gtk/lib/pkgconfig"
#export CPPFLAGS LDFLAGS PKG_CONFIG_PATH

#X_CFLAGS= -std=c++11 -Werror `pkg-config --cflags gtk+-3.0`
#X_LDFLAGS=`pkg-config --libs gtk+-3.0` -lm


EXE = TranslateLX

SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = tests

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CPPFLAGS += -I./include
CFLAGS += --std=c++11 -Wall `pkg-config --cflags gtk+-3.0`
LDFLAGS += -L./lib
LDLIBS += `pkg-config --libs gtk+-3.0` -lm

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(CPPFLAGS) $^ $(LDLIBS) -o $@

test: $(TEST_DIR)/tests.cpp

$(TEST_DIR)/tests.cpp: obj/byGlosbe.o
	$(CC) -std=c++11 -I/home/michal/Pulpit/boost_1_61_0/ -I/home/michal/Pulpit/curl-7.49.1/include/ -L/home/michal/Pulpit/curl-7.49.1/lib/ $@ $^ -lcurl -o tests/tests
#g++ -I/home/michal/Pulpit/boost_1_61_0/ tests/tests.cpp -L/home/michal/Pulpit/boost_1_61_0/stage/lib/libboost_unit_test_framework.so -o hello

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@		

clean:
	$(RM) $(OBJ)
