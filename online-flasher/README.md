# UVTools2 online-flasher files

## Select exactly this file

`Quansheng-K5V3-AdminUser-Morse-v0.2.4-test.bin`

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
https://armel.github.io/uvtools2/?firmwareURL=https://raw.githubusercontent.com/jewelux/quansheng-k5-v3-admin-user/development/online-flasher/Quansheng-K5V3-AdminUser-Morse-v0.2.4-test.bin
```

## Test warning

This `-test` image adds protected normal-boot keys to the tested held-`MENU`
administrator entry. Global TX prevention is not enabled in this build. It is
not the final receive-only children's firmware.

`manifest.json` documents the artifact for humans and release automation;
UVTools2 itself processes the `.bin` file.
