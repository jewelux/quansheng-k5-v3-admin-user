# Experimental V3 Admin/User SAM build

This directory is intentionally separate from the current V3/K1 and V1 test
artifacts. Nothing here replaces `v0.3.5-rxonly-test` on `development`.

Select only:

`Quansheng-K5V3-AdminUser-SAM-v0.4.1-rxonly-experimental.bin`

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
- `Access = OFF` for operation without acoustic menu output;
- stored voice samples deliberately disabled;
- SAM speed, pitch and mouth/throat settings.
- corrected monotonic V3/BK4829 sensitivity levels 0–12, entirely inside the
  receiver's hardware-tested working `REG_13` range.

The image builds with 92540 bytes flash and 14208 of 16384 bytes RAM. The RAM
figure includes the linker's reserved 1024-byte stack and leaves 2176
additional bytes. Treat this as an experimental hardware test, not a stable
release.

Initial test order:

1. Back up calibration and EEPROM data.
2. Flash only to a V3/K1 and confirm the display advances past `v0.41`.
3. Test normal user startup, `UP`, `DOWN` and the acoustic PTT action.
4. Start with held `MENU`; confirm `Access` offers Morse, SAM and OFF, but no
   Voice.
5. Select SAM and scroll slowly. Stop immediately on a freeze, grey screen,
   restart, missing receiver audio or corrupted display.
6. Test SAM speed, pitch and mouth/throat settings, then power-cycle.
7. Select `Access = OFF`, confirm that menu navigation is silent, then repeat
   menu navigation in Morse mode.
8. With a steady received signal, step through every sensitivity level 0–12.
   Pay particular attention to 4-to-5, 5-to-6 and 6-to-7, then test the same
   transitions in reverse. Reception must remain audible at every level.
9. Do not treat TX prevention as verified until RF output is measured.

Direct UVTools2 link:

```text
https://armel.github.io/uvtools2/?firmwareURL=https://raw.githubusercontent.com/jewelux/quansheng-k5-v3-admin-user/feature/v3-admin-sam/online-flasher/experimental/Quansheng-K5V3-AdminUser-SAM-v0.4.1-rxonly-experimental.bin
```

Direct raw firmware download:

```text
https://raw.githubusercontent.com/jewelux/quansheng-k5-v3-admin-user/feature/v3-admin-sam/online-flasher/experimental/Quansheng-K5V3-AdminUser-SAM-v0.4.1-rxonly-experimental.bin
```

The correct raw file is exactly 92540 bytes. Do not use “Save link as” on a
normal `github.com/.../blob/...` page; that saves GitHub HTML instead of the
firmware. A firmware URL must use `raw.githubusercontent.com`.
