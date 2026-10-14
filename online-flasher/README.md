# Current firmware on main

## K5 V3 / K1: SAM v0.4.3

Current firmware: `Quansheng-K5V3-AdminUser-SAM-v0.4.3-rxonly.bin`

[Open the online flasher](https://armel.github.io/uvtools2/?firmwareURL=https://raw.githubusercontent.com/jewelux/quansheng-k5-v3-admin-user/main/online-flasher/Quansheng-K5V3-AdminUser-SAM-v0.4.3-rxonly.bin)

[Download the BIN file](https://raw.githubusercontent.com/jewelux/quansheng-k5-v3-admin-user/main/online-flasher/Quansheng-K5V3-AdminUser-SAM-v0.4.3-rxonly.bin)

For UV-K5 V3 / UV-K1 with PY32F071 only. Never flash onto V1/DP32G030,
V2/PY32F030 or GD32. This raw image is exactly 92904 bytes; its checksum is
in `SHA256SUMS.txt`.

SAM v0.4.3 provides Morse, SAM and OFF, SAM volume control, protected normal
startup, held-MENU administrator startup, sensitivity 0–12 and close-range
attenuation minus 1–9. Stored voice samples are disabled.

Functional testing was reported successful on 2026-10-08. On 2026-10-14 the
user reported that the radio no longer transmits during operation. RF-output
measurement remains pending; this remains an experimental build.
See `experimental/README.md` for the detailed test checklist.

The previous V3 MorseVoice v0.3.5 image is retained in `archive/`.
The identical SAM file under `experimental/` remains for existing links.
`manifest.json` identifies the current V3/K1 main firmware.

## K5 V1: MorseVoice v1.0.1

`Quansheng-K5V1-AdminUser-MorseVoice-v1.0.1-rxonly-test.packed.bin`

[Open the V1 online flasher](https://armel.github.io/uvtools2/?firmwareURL=https://raw.githubusercontent.com/jewelux/quansheng-k5-v3-admin-user/main/online-flasher/Quansheng-K5V1-AdminUser-MorseVoice-v1.0.1-rxonly-test.packed.bin)

For the original UV-K5 V1 / DP32G030 only. V1 provides stored voice samples
and Morse fallback, with no SAM. The smoke test passed on 2026-09-28;
complete acoustic regression and RF-output measurements remain pending.

## Flashing

1. Back up calibration and EEPROM data.
2. Open the link for your hardware in a Web Serial capable browser.
3. Choose `Flash Firmware`, connect as instructed and flash.

Manual downloads must use the direct BIN link or GitHub's raw download button.
Saving the GitHub file-view page saves HTML instead of firmware.
UVTools2 consumes the BIN file, not the manifest.
