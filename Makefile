#make test && ./tests/tests --color_output=true --log_level=message
#apt-get install libgstreamer1.0-0 gstreamer1.0-plugins-base gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly gstreamer1.0-libav gstreamer1.0-doc gstreamer1.0-tools

CC = g++

PKGCONFIG += gtk+-3.0

EXE = TranslateLX

SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = tests

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CPPFLAGS += -I./include 
CFLAGS += -std=c++11 -Wall -pedantic

#LDFLAGS +=\
#	-I$(HOME)/cppLibs/curl-7.60.0/CURL-7.60.0/include/\
#	-L$(HOME)/cppLibs/curl-7.60.0/CURL-7.60.0/lib/\
#	-L$(HOME)/cppLibs/openssl-1.1.1/openssl/lib/

LDLIBS = $(SUBLIBS)\
`pkg-config gtkmm-3.0     --cflags --libs`\
`pkg-config gtk+-3.0      --cflags --libs`\
`pkg-config gstreamer-1.0 --cflags --libs`\
-lcurl -lssl -lcrypto

.PHONY: all clean

all: dirs $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(CPPFLAGS) $^ $(LDLIBS) -o $@

test: $(TEST_DIR)/tests.cpp
$(TEST_DIR)/tests.cpp: obj/wiCurl.o obj/clipboardService.o obj/mainWindow.o  obj/webInterface.o
	 $(CC) $(CFLAGS) \
	-I~/cppLibs/boost_1_61_0/ \
	$(LDFLAGS) \
	$@ $^ \
	$(LDLIBS) \
	-o tests/tests 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -c $< $(LDLIBS) -o $@		

dirs:
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) -R $(OBJ_DIR) $(EXE)
