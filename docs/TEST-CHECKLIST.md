# Hardware test checklist

Record radio model, MCU marking, previous firmware and calibration-backup name
before each test.

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
