# UVTools2 online-flasher files

## Select exactly this file

`Quansheng-K5V3-AdminUser-MorseVoice-v0.3.5-rxonly-test.bin`

It is a raw PY32F071 V3/K1 firmware image. Do **not** rename or convert it to a
V1 `.packed.bin` image.

Supported hardware:

- Quansheng UV-K5 V3 with PY32F071;
- Quansheng UV-K1 with PY32F071.

It must not be flashed onto a V1/DP32G030, V2/PY32F030 or GD32 model.

## Flash with UVTools2

1. Back up calibration data first.
2. Open <https://armel.github.io/uvtools2/> in a Web Serial capable browser.
3. Choose `Flash Firmware`.
4. Select the `.bin` file named above.
5. Verify its SHA-256 value against `SHA256SUMS.txt`.
6. Connect the radio as instructed by UVTools2 and flash it.

After the prepared repository is published as
`jewelux/quansheng-k5-v3-admin-user`, UVTools2 can preload the raw GitHub file:

```text
https://armel.github.io/uvtools2/?firmwareURL=https://raw.githubusercontent.com/jewelux/quansheng-k5-v3-admin-user/development/online-flasher/Quansheng-K5V3-AdminUser-MorseVoice-v0.3.5-rxonly-test.bin
```

## Test warning

This `-rxonly-test` image combines the protected normal-boot keys and the tested
held-`MENU` administrator entry with multi-layer software TX prevention. Held
`MENU` is the only administrator entry (`PTT` + `SIDE1` no longer opens it),
and the user protection also applies when ARDF is switched off. Morse
and Richard's stored voice-sample system are compiled in; choose `Morse` or
`Voice` under `Access`. The separate `Voice` menu controls stored prompts with
`Off`, `Chinese` and `English`. A newly selected menu voice now replaces an
older clip, with Morse as the fallback for a missing stored sample. The ARDF
PTT snapshot and compass actions remain
compiled in because they run before the normal radio transmit path.

The image has built successfully but has not yet passed the target-radio
acoustic regression or RF power measurements. Treat it as experimental until
those tests are recorded. Software TX prevention is not a hardware removal of
the transmitter and is not a legal certification.

The binary is the unchanged GitHub Actions build (Arm GNU Toolchain
13.3.Rel1) from the `v0.3.5-rxonly-test` pre-release.

`manifest.json` documents the artifact for humans and release automation;
UVTools2 itself processes the `.bin` file.
