# Quansheng K5 V3 Admin/User ARDF firmware

Experimental Admin/User extension of Richard's talking ARDF firmware for the
Quansheng UV-K5 V3 and UV-K1 (PY32F071).

The first development stage deliberately preserves Richard's complete menu and
Richard's proven Morse accessibility path. It adds a protected user interface without
removing menu entries or audio code:

- normal power-on: protected ARDF user interface;
- hold `MENU` while switching on: complete administrator interface;
- user interface: `UP`/`DOWN` adjust ARDF gain;
- user interface: `PTT` keeps Richard's acoustic ARDF snapshot action;
- other configuration keys are rejected with a low double beep.

## Development status

The current development artifact is `v0.2.4-test`. An initial hardware test on
2026-09-27 confirmed that it boots, receives the test fox, retains the ARDF
`UP`/`DOWN` controls, and provides the menu through the administrator boot.
The complete acoustic-regression checklist remains open.

Earlier Admin/User images froze on the welcome screen because their combined
author/version text exceeded the width assumed by Richard's unbounded small-text
renderer and overwrote the framebuffer. Development builds therefore use the
short on-screen identifier `LX1WJ v0.24`.

## Important test warning

`AdminUser-Morse-Test` is a development build. Its global `ENABLE_PREVENT_TX`
switch is deliberately **off** so Admin/User behaviour can be tested separately
from the later transmitter-removal stage. Do not treat it as a legally certified
receive-only device and do not distribute it for unsupervised children's use.

`AdminUser-Morse-RXOnly` is already defined as a separate build target, but it is
not a substitute for the planned multi-layer TX-path audit and hardware test.

## Online flasher

The one file selected by UVTools2 is kept in [`online-flasher`](online-flasher/).
See its README for exact flashing instructions, hardware restrictions and the
direct `firmwareURL` link format.

## Build

Required tools: CMake, Ninja and the official Arm GNU Toolchain
**13.3.Rel1** (`arm-none-eabi-gcc 13.3.1`). This version is pinned deliberately:
the locally tested MSYS2 GCC 13.4.0 produced an image which remained stuck on
the welcome screen, while Richard's clean source built with 13.3.Rel1 works on
the target radio.

```sh
cmake --preset AdminUser-Morse-Test firmware-v3
cmake --build --preset AdminUser-Morse-Test
```

Build output:

```text
firmware-v3/build/AdminUser-Morse-Test/quansheng.AdminUser_Morse_Test_K5v3_K1.bin
```

## Origin

Base source: `jewelux/quansheng-K5-talking-ardf-rx`, commit
`d555b2fabac6fb4abcde33a840eff12d036784cf`.

The source retains the upstream Apache-2.0 licensing and attribution.
