## Sublime Text
---
1. install gcc `brew install gcc`.
2. install sublime text `brew install --cask submlie-text`
	1. origami
	2. neovintageous
	3. sublime linter , submlie-linter-gcc
	3. Now clone repository
`git clone https://github.com/Siddhant-sarkar/Senbonzakura.git`
3. Add a new build system.
```Makefile
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
```

## Compiler : GCC

---
* install iterm2 `brew install --cask iterm`
* Precompile bits/stdc++.h for faster compilation time.
```shell
cd bits
g++-12 -std=c++20 -O2 -Wall -Wshadow -Wfloat-equal -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=undefined -fno-sanitize-recover stdc++.h
```

*  Now i will go over my all my compiler flags.
	* `-std=c++20` :  c++20 standards
	* `-O2` : speeds the program with optimizations.
	* `-Wall` : all the warnings
	* `-Wshadow` : considers shadow variable declaration
	* `-Wfloat-equal` : equating the floats
	* `-Wlogical-op` — warns about logical operators in places where GCC expects bitwise operators.
	* `-Wshift-overflow=2` — warns about left shift overflows (GCC 6+).
	-   `-Wduplicated-cond` — warns about repeated conditions in `if (…) else if (…)` (GCC 6+).
	- `-D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC` : STL bounds checking
	- `-D_FORTIFY_SOURCE=2` : check for buffer overflow .(eg : copying vector of larger sizes to smaller sizes.)
	- `-fsanitize=undefined` can also find divisions by zero, undefined integer shifts, signed integer overflows and leaving a function without a return value.
	- `-fno-sanitize-recover` : aborts the program there itself.

* So to compile any program we can do 
	`g++-12 -std=c++20 -O2 -Wall -Wshadow -Wfloat-equal -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=undefined -fno-sanitize-recover -DTSUKI main.cpp -o main`
 
