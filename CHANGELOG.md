# Changelog

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
