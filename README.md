# A very bad hash algorithm

### Usage
To hash a file:
```
shithash-<bits> [file]
```
To hash `stdin`:
```
echo test | shithash-<bits>
```

### Building
* If you are going to use `cmake`, you need to define `CMAKE_BUILD_TYPE` as `Release`.
* If you are going to use a normal C++ compiler without a build system, just compile `main.cpp` and define the `BITS` or `LENGTH` macro.
