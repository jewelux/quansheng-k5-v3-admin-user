# Diagnostic reference firmware

`Richard-source-ARDF-Morse-GCC13.3-reference.bin` is an unchanged build of
Richard's `ARDF-Morse` preset at upstream commit
`d555b2fabac6fb4abcde33a840eff12d036784cf`, compiled with the official Arm GNU
Toolchain 13.3.Rel1.

It was tested successfully on the target radio (boot, `UP`, `DOWN`, and menu)
and is retained only as a known-good diagnostic baseline. It is not the
Admin/User release and is intentionally kept outside `online-flasher/`.
