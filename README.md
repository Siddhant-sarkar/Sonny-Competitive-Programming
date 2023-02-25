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
```javascript
{
    "shell_cmd": " g++-12 -std=c++20 -O2 -Wall -Wshadow -Wfloat-equal -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=undefined -fno-sanitize-recover -DTSUKI -H '${file}' -o '${file_base_name}' && echo 'cd \"${file_path}/\"' > '/tmp/${file_base_name}' && echo './\"${file_base_name}\"' >> '/tmp/${file_base_name}' && echo read >> '/tmp/${file_base_name}' && chmod +x '/tmp/${file_base_name}' && open -a iterm.app '/tmp/${file_base_name}'",

    "file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
    "working_dir": "${file_path}",
    "selector": "source.c++",
}
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
 
