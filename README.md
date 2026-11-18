# LinUtils
Small set of Linux command line utilities.

## About LinUtils
LinUtils is a set of various terminal utilities made primarily for educational purposes.

### Included utilities
Here is a list of utilities present in this repository down bellow:

|Utility|Description|
|-------|-----------|
|[lcat](/lcat/)|Simple cat program with a line counter.|
|[passgen](/passgen/)|Simple password generator utility.|
|[touch](/touch/)|Simple implementation of the touch command.|

## Prerequisites
In order to build those utilities, you'll only need any C compiler.
I used `gcc` during the development and testing.

If you pick the `gcc` compiler, the compilation is as easy as:

```bash
gcc source.c -o bin/target.out
```

## License
LinUtils is licensed under the MIT license - available [here](LICENSE.md).