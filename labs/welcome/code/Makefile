CXX = g++

TARGET_OBJ = censor.o

SRCS = censor.cpp

all: $(TARGET_OBJ)

$(TARGET_OBJ): $(SRCS)
	$(CXX) $(CXXFLAGS) -c -o $@ $^

clean:
	rm -f $(TARGET_OBJ)
