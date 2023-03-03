CC = g++-12
CFLAGS = -std=c++20 -O2 -Wall -Wshadow -Wno-unused-variable -Wfloat-equal -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=undefined -fno-sanitize-recover -DTSUKI 
TARGET = _a       
SRC = main.cpp       

.PHONY: all 
all: $(TARGET)
	@gtimeout 2s ./$(TARGET) < inputf.in && echo 'Press any key to continue...' && read line && clear 
inp: $(TARGET)
	@echo 'Enter now ...' && ./$(TARGET) && echo 'Press any key to continue...' && read line && clear 


$(TARGET):	$(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(TARGET)
clean:
	rm -f $(TARGET)
