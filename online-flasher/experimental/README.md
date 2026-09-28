# Experimental V3 Admin/User SAM build

This directory is intentionally separate from the current V3/K1 and V1 test
artifacts. Nothing here replaces `v0.3.5-rxonly-test` on `development`.

Select only:

`Quansheng-K5V3-AdminUser-SAM-v0.3.7-rxonly-experimental.bin`

Supported hardware:

- Quansheng UV-K5 V3 with PY32F071;
- Quansheng UV-K1 with PY32F071.

Never flash this raw image onto a V1/DP32G030, V2/PY32F030 or GD32 radio.

The build contains:

- normal-boot protected user mode;
- held-`MENU` administrator mode;
- multi-layer software TX prevention;
- disabled UART BK4829 register read/write commands;
- Morse and Richard's on-device SAM text-to-speech;
- stored voice samples deliberately disabled;
- SAM speed, pitch and mouth/throat settings.

The image builds with 92516 bytes flash and 14208 of 16384 bytes RAM. The RAM
figure includes the linker's reserved 1024-byte stack and leaves 2176
additional bytes. Treat this as an experimental hardware test, not a stable
release.

Initial test order:

1. Back up calibration and EEPROM data.
2. Flash only to a V3/K1 and confirm the display advances past `v0.37`.
3. Test normal user startup, `UP`, `DOWN` and the acoustic PTT action.
4. Start with held `MENU`; confirm `Access` offers Morse and SAM, but no Voice.
5. Select SAM and scroll slowly. Stop immediately on a freeze, grey screen,
   restart, missing receiver audio or corrupted display.
6. Test SAM speed, pitch and mouth/throat settings, then power-cycle.
7. Repeat menu navigation in Morse mode.
8. Do not treat TX prevention as verified until RF output is measured.

Direct UVTools2 link:

```text
https://armel.github.io/uvtools2/?firmwareURL=https://raw.githubusercontent.com/jewelux/quansheng-k5-v3-admin-user/feature/v3-admin-sam/online-flasher/experimental/Quansheng-K5V3-AdminUser-SAM-v0.3.7-rxonly-experimental.bin
```
