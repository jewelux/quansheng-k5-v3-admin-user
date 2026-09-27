# Hardware test checklist

Record radio model, MCU marking, previous firmware and calibration-backup name
before each test.

## Recorded development tests

- 2026-09-27, `v0.2.3-entry-test`: normal boot, `UP`, `DOWN`, menu, and audible
  test-fox reception passed on the target radio.
- 2026-09-27, `v0.2.4-user-test`: initial Admin/User smoke test reported as
  working. Complete item-by-item acoustic regression remains pending.
- 2026-09-27, `v0.3.0-rxonly-test`: multi-layer TX-prevention image built with
  GCC 13.3.1. Target-radio and RF-output tests are pending.
- 2026-09-27, `v0.3.1-rxonly-test`: Morse plus stored voice samples and the
  two-line LX1WJ/DO9RE attribution built with GCC 13.3.1. Hardware testing is
  pending.
- 2026-09-27, `v0.3.2-rxonly-test`: shared `DO9RE-LX1WJ` credit plus
  interruptible Morse and held-arrow fast scrolling built with GCC 13.3.1.
  Hardware testing is pending.

## Admin/User separation

- Normal power-on enters the protected user interface.
- `MENU` held during power-on enters the complete administrator interface.
- User `UP` increases ARDF sensitivity.
- User `DOWN` decreases ARDF sensitivity.
- User `PTT` produces the expected acoustic ARDF snapshot.
- Menu, digits, function keys and frequency entry are rejected in user mode.
- All keys behave as Richard intended in administrator mode.

## Acoustic regression

- Every supported main-menu item is output in Morse.
- Every supported submenu value is output in Morse.
- UP/DOWN navigation produces the corresponding Morse feedback.
- ARDF gain feedback works.
- Frequency feedback works where supported by Richard's Morse mode.
- ARDF snapshot and compass/level sonification work.
- Beeps remain audible at strongly reduced ARDF gain.
- Receiver audio returns after each generated announcement.
- Power cycling preserves the configured Morse accessibility settings.

## Transmission warning for development test builds

This phase intentionally does not claim receive-only operation. Test only on a
dummy load or under controlled, licensed conditions. Record RF output checks for
PTT, VOX, alarm, DTMF, 1750 Hz, scanner and serial-control paths before any
public field release.

The later RX-only release requires a separate multi-layer software audit and an
RF power measurement; a successful compile is not sufficient certification.

## RX-only v0.3.0 test

- Confirm the display advances beyond `LX1WJ v0.30` at normal startup.
- Repeat every Admin/User and acoustic-regression item above.
- Verify short PTT produces the audible ARDF snapshot without RF output.
- Verify held PTT produces compass/level sonification without RF output.
- Measure RF output for normal PTT outside ARDF, VOX, alarm, 1750 Hz, DTMF,
  Aircopy, scanner and serial-control requests.
- Confirm the red TX LED never lights and the UI never remains in TX state.
- Repeat RF measurement in both normal User and held-`MENU` Admin boots.

## Morse and voice-sample v0.3.1 test

- Confirm the welcome screen shows `LX1WJ v0.31` and `DO9RE-RX Edition` and
  advances normally.
- In Admin mode, confirm `Access` offers both `Morse` and `Voice`.
- Confirm `Voice` offers `Off`, `Chinese` and `English`.
- Select `Access: Morse` and repeat the complete Morse regression above.
- Select `Access: Voice` with `Voice: English`; check every available menu
  announcement and note missing or incorrect stored samples.
- Confirm an unmapped voice item falls back to Morse.
- Repeat PTT snapshot, held-PTT compass and RF-output checks in both access
  modes.

## Fast menu navigation v0.3.2 test

- Confirm the first firmware line is `DO9RE-LX1WJ` and the next is `v0.32`.
- During Morse playback, tap `UP` and `DOWN`; the tone must stop immediately
  and the adjacent entry must be selected.
- Hold `UP` or `DOWN`; after a short delay the display must scroll quickly
  without speaking every intermediate entry.
- Release the arrow; only the final selected entry should be announced.
- Repeat inside a submenu and confirm values change in the correct direction.
