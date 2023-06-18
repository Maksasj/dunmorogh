# Dunmorogh
Dunmorogh - simple c++ library, that implements some sorting algorithms such as insertion sort, merge sort, gnome sort, as well as introduces new hybrid sorting algortim named **dunmorogh sort**, that combines these three sorting algorithms. 

> Note: This repository is not actively maintained, repository where made only for educational purposes.

## Building
### Requirments
- Cmake (probably any version)
- Any c++ compiler, but clang is preferable.

```bash
cmake -B build -G Ninja

cmake --build build
```

But for convenience there is bash `make` script
```bash
make.bat
```

## Testing
For testing this project is using Ctest framework, so probably you need to install cmake :). Also there is a simple bash script, created for testing convenience.
```bash
test.bat
```

## License
Dunmorogh is free, open source library. All code in this repository is licensed under
- MIT License ([LICENSE.md](https://github.com/Maksasj/graph/blob/master/LICENSE.md) or https://opensource.org/license/mit/)
