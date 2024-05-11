# CCD

Rudimentary implementation of the CLI tool [XXD](https://github.com/ckormanyos/xxd) in stdlib C.

## Usage

To view an example hexdump of `17*4` bytes using the included `gen` script:

```sh
$ make
$ ./gen 17 | ./ccd
```

Result:

```
00000000: 4849 dea0 4849 dea0 4849 dea0 4849 dea0  HI..HI..HI..HI..
00000010: 4849 dea0 4849 dea0 4849 dea0 4849 dea0  HI..HI..HI..HI..
00000020: 4849 dea0 4849 dea0 4849 dea0 4849 dea0  HI..HI..HI..HI..
00000030: 4849 dea0 4849 dea0 4849 dea0 4849 dea0  HI..HI..HI..HI..
00000040: 4849 dea0                                HI..
```
