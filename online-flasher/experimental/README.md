# Experimental V3 Admin/User SAM build

This directory is intentionally separate from the V3/K1 and V1 Morse/voice
test artifacts. Nothing here replaces `v0.3.5-rxonly-test`.

Select only:

`Quansheng-K5V3-AdminUser-SAM-v0.4.3-rxonly-experimental.bin`

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
- SAM-only volume levels 1–9 (`SamVol`), with level 9 equal to the original
  full level and levels 1–8 providing attenuation only;
- protected user-mode SAM volume control: upper side key louder, lower side
  key quieter;
- concise SAM sensitivity announcements: `zero` through `twelve`, followed
  below level 00 by `minus one` through `minus nine`;
- Richard's close-range zone restored on V3: minus 1–6 progressively attenuate
  receiver audio and minus 7–9 additionally narrow the IF bandwidth;
- corrected monotonic V3/BK4829 sensitivity levels 0–12, entirely inside the
  receiver's hardware-tested working `REG_13` range.

The image builds with 92904 bytes flash and 14208 of 16384 bytes RAM. The RAM
figure includes the linker's reserved 1024-byte stack and leaves 2176
additional bytes. Functional hardware testing was reported successful on
2026-10-08, but RF-output measurement is still required. Treat this as an
experimental build, not a stable release.

Initial test order:

1. Back up calibration and EEPROM data.
2. Flash only to a V3/K1 and confirm the display advances past `v0.43`.
3. Test normal user startup, `UP`, `DOWN` and the acoustic PTT action.
4. Start with held `MENU`; confirm `Access` offers Morse, SAM and OFF, but no
   Voice.
5. Select SAM and scroll slowly. Stop immediately on a freeze, grey screen,
   restart, missing receiver audio or corrupted display.
6. Test SAM speed, pitch, mouth/throat and `SamVol` settings. In protected
   user mode, verify upper side key = louder and lower side key = quieter.
   Confirm that level 9 is the old/full level and that power-cycling preserves
   the selected level.
7. Select `Access = OFF`, confirm that menu navigation is silent, then repeat
   menu navigation in Morse mode.
8. With a steady received signal, step through every sensitivity level 0–12.
   Pay particular attention to 4-to-5, 5-to-6 and 6-to-7, then test the same
   transitions in reverse. Reception must remain audible at every level.
9. Continue downward from 00 through minus 1–9. Confirm progressive close-range
   attenuation, the additional narrow-band effect at minus 7–9, and correct
   restoration while returning through minus 6 to 00. SAM must speak only the
   number at 0–12 and `minus` plus the number below 00.
10. Do not treat TX prevention as verified until RF output is measured.

Direct UVTools2 link:

```text
https://armel.github.io/uvtools2/?firmwareURL=https://raw.githubusercontent.com/jewelux/quansheng-k5-v3-admin-user/main/online-flasher/experimental/Quansheng-K5V3-AdminUser-SAM-v0.4.3-rxonly-experimental.bin
```

Direct raw firmware download:

```text
https://raw.githubusercontent.com/jewelux/quansheng-k5-v3-admin-user/main/online-flasher/experimental/Quansheng-K5V3-AdminUser-SAM-v0.4.3-rxonly-experimental.bin
```

The correct raw file is exactly 92904 bytes. Do not use “Save link as” on a
normal `github.com/.../blob/...` page; that saves GitHub HTML instead of the
firmware. A firmware URL must use `raw.githubusercontent.com`.
