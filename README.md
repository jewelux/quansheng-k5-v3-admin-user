# Quansheng K5 V3 Admin/User ARDF firmware

Experimental Admin/User extension of Richard's talking ARDF firmware for the
Quansheng UV-K5 V3 and UV-K1 (PY32F071).

The first development stage deliberately preserves Richard's complete menu and
all Morse/SAM accessibility paths. It adds a protected user interface without
removing menu entries or audio code:

- normal power-on: protected ARDF user interface;
- hold `MENU` while switching on: complete administrator interface;
- user interface: `UP`/`DOWN` adjust ARDF gain;
- user interface: `PTT` keeps Richard's acoustic ARDF snapshot action;
- other configuration keys are rejected with a low double beep.

## Important test warning

`AdminUser-SAM-Test` is a development build. Its global `ENABLE_PREVENT_TX`
switch is deliberately **off** so Admin/User behaviour can be tested separately
from the later transmitter-removal stage. Do not treat it as a legally certified
receive-only device and do not distribute it for unsupervised children's use.

`AdminUser-SAM-RXOnly` is already defined as a separate build target, but it is
not a substitute for the planned multi-layer TX-path audit and hardware test.

## Online flasher

The one file selected by UVTools2 is kept in [`online-flasher`](online-flasher/).
See its README for exact flashing instructions, hardware restrictions and the
direct `firmwareURL` link format.

## Build

Required tools: CMake, Ninja and the `arm-none-eabi` GCC toolchain.

```sh
cmake --preset AdminUser-SAM-Test firmware-v3
cmake --build --preset AdminUser-SAM-Test
```

Build output:

```text
firmware-v3/build/AdminUser-SAM-Test/quansheng.AdminUser_SAM_Test_K5v3_K1.bin
```

## Origin

Base source: `jewelux/quansheng-K5-talking-ardf-rx`, commit
`d555b2fabac6fb4abcde33a840eff12d036784cf`.

The source retains the upstream Apache-2.0 licensing and attribution.
