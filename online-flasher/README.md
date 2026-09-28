# UVTools2 online-flasher files

## K5 V3 / K1: select exactly this file

`Quansheng-K5V3-AdminUser-MorseVoice-v0.3.5-rxonly-test.bin`

It is a raw PY32F071 V3/K1 firmware image. Do **not** rename or convert it to a
V1 `.packed.bin` image.

Supported hardware:

- Quansheng UV-K5 V3 with PY32F071;
- Quansheng UV-K1 with PY32F071.

It must not be flashed onto a V1/DP32G030, V2/PY32F030 or GD32 model.

## K5 V1: select exactly this file

`Quansheng-K5V1-AdminUser-MorseVoice-v1.0.1-rxonly-test.packed.bin`

This is the packed DP32G030 image for the original Quansheng UV-K5 V1 only.
Do **not** flash it onto a V3, K1, V2 or GD32 radio. Do not select the unpacked
build-intermediate `.bin` from `firmware-v1/`; UVTools2 needs the file ending
in `.packed.bin` from this directory.

## Flash with UVTools2

1. Back up calibration data first.
2. Open <https://armel.github.io/uvtools2/> in a Web Serial capable browser.
3. Choose `Flash Firmware`.
4. Select the exact hardware-specific file named above: raw `.bin` for V3/K1,
   `.packed.bin` for V1.
5. Verify its SHA-256 value against `SHA256SUMS.txt`.
6. Connect the radio as instructed by UVTools2 and flash it.

After the prepared repository is published as
`jewelux/quansheng-k5-v3-admin-user`, UVTools2 can preload the raw GitHub file:

```text
https://armel.github.io/uvtools2/?firmwareURL=https://raw.githubusercontent.com/jewelux/quansheng-k5-v3-admin-user/development/online-flasher/Quansheng-K5V3-AdminUser-MorseVoice-v0.3.5-rxonly-test.bin
```

V1 direct link:

```text
https://armel.github.io/uvtools2/?firmwareURL=https://raw.githubusercontent.com/jewelux/quansheng-k5-v3-admin-user/development/online-flasher/Quansheng-K5V1-AdminUser-MorseVoice-v1.0.1-rxonly-test.packed.bin
```

## Test warning

These `-rxonly-test` images combine the protected normal-boot keys and the tested
held-`MENU` administrator entry with multi-layer software TX prevention. On
V3/K1, held `MENU` is the only administrator entry (`PTT` + `SIDE1` no longer
opens it), and the user protection also applies when ARDF is switched off.
The V3/K1 `Access` setting selects Morse or stored voice samples. On V1,
available stored English prompts are spoken and entries without a matching
sample fall back to Morse; V1 does not contain SAM text-to-speech. The ARDF
PTT snapshot and compass actions remain
compiled in because they run before the normal radio transmit path.

The V3 image has been exercised on target hardware. V1 `1.0.1` passed an
on-device smoke test on 2026-09-28: administrator startup and scrolling work,
the battery-menu grey screen did not recur, stored English prompts were heard,
and unmapped entries fell back to Morse. Complete acoustic regression and RF
power measurements remain pending. Software TX prevention is not a hardware
removal of the transmitter and is not a legal certification.

V1 `1.0.1` also clamps imported or incompatible EEPROM menu values. This fixes
the grey-screen crash seen when reverse-scrolling from `Step` into the battery
service entries. The faulty V1 `1.0.0` image has been removed.

The binary is the unchanged GitHub Actions build (Arm GNU Toolchain
13.3.Rel1) from the `v0.3.5-rxonly-test` pre-release.

`manifest.json` documents the artifact for humans and release automation;
UVTools2 itself processes the `.bin` file.
