# Quansheng K5 Admin/User ARDF firmware

Experimental Admin/User extension of Richard's talking ARDF firmware for the
Quansheng UV-K5 V3 / UV-K1 (PY32F071) and, in a separate build, the
original UV-K5 V1 (DP32G030).

The first development stage deliberately preserves Richard's complete menu and
Richard's proven Morse accessibility path. It adds a protected user interface without
removing menu entries or audio code:

- normal power-on: protected ARDF user interface;
- hold `MENU` while switching on: complete administrator interface;
- user interface: `UP`/`DOWN` adjust ARDF gain;
- user interface: briefly press `PTT` for Richard's single acoustic ARDF
  signal-strength snapshot;
- user interface: hold `PTT` for a continuous direction-finding tone whose
  pitch follows the received signal strength until `PTT` is released;
- these ARDF `PTT` actions replace normal transmission while ARDF is active;
- other configuration keys are rejected with a low double beep;
- the protection also applies if ARDF is switched off in the administrator
  menu (PTT is then refused too);
- held `MENU` is the only administrator entry: Richard's `PTT` + `SIDE1`
  power-on combination and the Rescue Ops menu lock are disabled.

## Development status

The current development artifact is `v0.3.5-rxonly-test`. It combines
multi-layer software TX prevention with Morse and Richard's stored voice-sample
system. Menu voice playback now replaces an older asynchronous prompt safely
and falls back to Morse if a stored sample cannot be loaded. Held `MENU` is
now the only administrator entry, and the user protection also applies with
ARDF switched off. The image is built by GitHub Actions with the pinned
toolchain and published under Releases, but still requires target-radio
startup, voice-sample, acoustic-regression and RF-output tests. Previous test
images remain in `online-flasher/archive/`.

The current V1 port is `v1.0.1-rxonly-test`. It preserves the V1 Morse and stored
voice code, adds the same normal-user / held-`MENU` administrator split, and
forces the RF power-amplifier controls off. It is built from the independent
`firmware-v1/` source tree and must be flashed only as a `.packed.bin` file.
An on-device smoke test on 2026-09-28 confirmed administrator startup, stable
menu scrolling through the formerly crashing battery entries, audible stored
English prompts and Morse fallback. Full acoustic and RF-output tests remain
pending. SAM text-to-speech is a V3/K1 feature and is not present in V1.

Earlier Admin/User images froze on the welcome screen because their combined
author/version text exceeded the width assumed by Richard's unbounded small-text
renderer and overwrote the framebuffer. Development builds therefore use the
short on-screen identifiers: `DO9RE-LX1WJ` and `v0.35`. This keeps both
contributors together on the first line without recreating the framebuffer
overflow.

## Important test warning

`AdminUser-Morse-RXOnly` enables `ENABLE_PREVENT_TX` and additional guards at
the transmit-state, TX-register and PA-control layers. It does not remove the
transmitter hardware and is not a substitute for RF measurement or legal
certification. Do not distribute this test image for unsupervised children's
use until the hardware checklist has passed.

## Online flasher

The one file selected by UVTools2 is kept in [`online-flasher`](online-flasher/).
See its README for exact flashing instructions, hardware restrictions and the
direct `firmwareURL` link format.

## Build V3 / K1

Required tools: CMake, Ninja and the official Arm GNU Toolchain
**13.3.Rel1** (`arm-none-eabi-gcc 13.3.1`). This version is pinned deliberately:
the locally tested MSYS2 GCC 13.4.0 produced an image which remained stuck on
the welcome screen, while Richard's clean source built with 13.3.Rel1 works on
the target radio.

```sh
cd firmware-v3
cmake --preset AdminUser-Morse-RXOnly
cmake --build --preset AdminUser-Morse-RXOnly
```

Build output:

```text
firmware-v3/build/AdminUser-Morse-RXOnly/quansheng.AU_RX_K5v3_K1.bin
```

## Build V1

The V1 uses the DP32G030 Makefile build. LTO is disabled for deterministic
Windows and CI builds; the resulting image still fits comfortably in flash.

```sh
make -C firmware-v1 ENABLE_LTO=0 AUTHOR_STRING=DO9RE-LX1WJ VERSION_STRING=v1.01
```

Build output:

```text
firmware-v1/quansheng.AdminUser_RX_K5v1.packed.bin
```

## Origin

Base source: `jewelux/quansheng-K5-talking-ardf-rx`, commit
`d555b2fabac6fb4abcde33a840eff12d036784cf`.

The source retains the upstream Apache-2.0 licensing and attribution.
