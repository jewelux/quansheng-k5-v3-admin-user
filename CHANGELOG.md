# Changelog

## 0.2.1-test

- Build with the upstream-pinned official Arm GNU Toolchain 13.3.Rel1.
- Supersede the non-working 0.2.0 binary built with MSYS2 GCC 13.4.0.
- Keep the Admin/User behaviour unchanged and correct the missing Morse
  declaration for saving the accessibility mode.

## 0.2.0-test

- Rebase the Admin/User build configuration on Richard's hardware-proven
  `ARDF-Morse` preset instead of the freezing experimental SAM preset.
- Restore Richard's normal welcome countdown and retain Morse menu feedback.
- Keep TX prevention disabled only in this controlled Admin/User test build.

## 0.1.3-test

- Bypass the interrupt-driven welcome-screen countdown in Admin/User builds
  and enter the main application loop immediately.
- This isolates the persistent on-device freeze reported with 0.1.1 and
  0.1.2 from keyboard and SAM functionality.

## 0.1.2-test

- Remove the early SAM mode announcement that could block before the main
  application loop and leave the radio frozen on the welcome screen.
- Keep the stabilized MENU sampling and all of Richard's runtime SAM menu
  announcements.

## 0.1.1-test

- Detect held `MENU` with five stable samples after settings initialization.
- Force ARDF user mode before ARDF initialization and radio configuration.
- Announce `ARDF user mode` or `administrator mode` after boot.
- Supersedes 0.1.0-test, whose power-on MENU scan happened too early.

## 0.1.0-test

- Start from Richard's V3 source at commit `d555b2f`.
- Add compile-time `ENABLE_ADMIN_USER_MODE` isolation.
- Enter the administrator interface by holding `MENU` during power-on.
- Restrict the normal user interface to ARDF gain and acoustic snapshot keys.
- Preserve Richard's complete menu, Morse feedback and SAM speech functions.
- Keep test and future RX-only build presets separate.
- Add a dedicated, unambiguous UVTools2 firmware distribution directory.
