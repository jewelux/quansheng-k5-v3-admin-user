# K5 V1 Admin/User RX-only build

This tree targets the original Quansheng UV-K5 V1 with the DP32G030 MCU.
It is not binary-compatible with the V3/K1 PY32F071 build.

Normal power-on enters protected user mode. Hold `MENU` while switching on to
enter administrator mode. User mode keeps ARDF `UP`, `DOWN` and the acoustic
PTT snapshot available while rejecting configuration keys.

Build with Arm GNU Toolchain 13.3.Rel1:

```sh
make ENABLE_LTO=0 AUTHOR_STRING=DO9RE-LX1WJ VERSION_STRING=v1.01
```

For flashing, use only `quansheng.AdminUser_RX_K5v1.packed.bin`. The unpacked
`.bin` is an intermediate file and must not be offered as the V1 download.

Software guards reject transmitter setup and force PA bias and PA enable off.
They do not physically remove the transmitter. Confirm zero RF output with
suitable test equipment before legal or unsupervised use.
