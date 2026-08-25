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

- Every visible main-menu item is announced.
- Every visible submenu value is announced.
- Fast UP/DOWN navigation interrupts and restarts speech correctly.
- ARDF gain is announced.
- Frequency readout works.
- ARDF snapshot and compass/level sonification work.
- Beeps remain audible at strongly reduced ARDF gain.
- Receiver audio returns after each generated announcement.
- Power cycling preserves accessibility speed, pitch and mouth parameters.

## Transmission warning for 0.1.0-test

This phase intentionally does not claim receive-only operation. Test only on a
dummy load or under controlled, licensed conditions. Record RF output checks for
PTT, VOX, alarm, DTMF, 1750 Hz, scanner and serial-control paths before any
public field release.

The later RX-only release requires a separate multi-layer software audit and an
RF power measurement; a successful compile is not sufficient certification.
