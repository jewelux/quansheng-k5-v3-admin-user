# Changelog

## V3/K1 0.4.3-rxonly-experimental

- Shorten SAM sensitivity announcements to the displayed index: normal
  levels now speak only `zero` through `twelve`.
- Preserve an unmistakable acoustic boundary below level 00 by speaking
  `minus one` through `minus nine` for Richard's close-range zone.
- Restore the missing V3 hardware application of Richard's close-range table.
  Minus 1–6 apply progressive AF attenuation; minus 7–9 additionally narrow
  the IF bandwidth. Normal bandwidth and AF gain are restored when returning
  to level 00, including the transition back from the narrow-band levels.
- Retain the v0.4.2 SAM-only volume control and all RX-only/Admin-User guards.
- Functional hardware testing reported successful on 2026-10-08; independent
  RF-output measurement remains required before declaring a stable release.
- Preserve the published v0.3.5 artifact from the canonical tracked binary.
  Development builds can no longer silently replace it under the old version
  number; the workflow repairs a mismatch and otherwise leaves it unchanged.
- Build successfully with GCC 13.3.1: 92904 bytes flash and 14208 of 16384
  bytes RAM including the linker's reserved 1 KiB stack.

## V3/K1 0.4.2-rxonly-experimental

- Add SAM-only volume levels 1–9. Level 9 is exactly the previous full SAM
  amplitude; levels 1–8 only attenuate the synthesized PCM signal and do not
  alter receiver, Morse or beep audio.
- Add the administrator-menu item `SamVol` and persist its value without
  changing the EEPROM layout. Older saved settings default safely to level 9.
- In protected user mode with `Access = SAM`, use the upper side key to raise
  SAM volume and the lower side key to lower it. The firmware intercepts only
  these volume actions and does not expose the normal side-key functions.
- Build successfully with GCC 13.3.1: 92840 bytes flash and 14208 of 16384
  bytes RAM including the linker's reserved 1 KiB stack.

## 0.3.5-rxonly-test (source only; release binary not yet built)

- Make held `MENU` the only administrator entry. Richard's `PTT` + `SIDE1`
  power-on combination no longer opens the administrator interface.
- Keep the user-mode key filter active even when ARDF has been switched off
  in the administrator menu; PTT is then refused as well.
- Disable Rescue Ops in both Admin/User presets so its menu lock cannot block
  the held-`MENU` administrator entry.
- Disable the UART BK4829 register read/write commands in the RX-only preset,
  which could otherwise bypass every software TX guard from a connected PC.
- Restore receiver audio when a cancelled voice clip falls back to Morse.
- Declare `SETTINGS_SaveAccessibilityMode()` for Morse-only builds.
- Fix the README build commands and upload the RX-only CI artifact.

## V3/K1 0.4.1-rxonly-experimental

- Add a separate `AdminUser-SAM-RXOnly` preset without changing the tested
  `AdminUser-Morse-RXOnly` preset or its v0.3.5 artifact.
- Enable Richard's SAM speech synthesis together with Morse. Stored voice
  samples are deliberately disabled because they are not part of his working
  speech path.
- Add `OFF` to the `Access` menu for sighted users. It is appended after Morse
  and SAM so existing saved accessibility settings keep their meaning.
- Enforce `Access = OFF` at both audio backends: direct ARDF SAM announcements
  are now suppressed and the menu no longer treats every non-SAM mode as
  Morse.
- Correct the fixed ARDF gain ladder after hardware testing of v0.4.0 showed
  that `REG_13` values using bits 9:8 mute this V3/K1 receiver (`0x007B`
  works, while `0x017B` does not). All sensitivity levels 0–12 now keep those
  bits clear and increase only the proven LNA/PGA fields from `0x0019` through
  `0x00FF`.
- Disable FM radio, spectrum, VOX, games, screenshots and regional channel
  helpers in this experimental preset, matching Richard's lean SAM preset and
  leaving all ARDF receiver functions intact.
- Retain Admin/User separation, held-`MENU` administrator entry and all
  RX-only guards, including disabled UART BK4829 register access.
- Build successfully with GCC 13.3.1: 92540 bytes flash and 14208 of 16384
  bytes RAM including the linker's reserved 1 KiB stack, leaving 2176 bytes
  additional RAM headroom.

## K5 V1 1.0.1-rxonly-test

- Clamp every menu setting with declared limits before the display uses it.
- Protect `BatTyp` against invalid EEPROM array indexes.
- Protect `BatCal` against invalid calibration values and division by zero.
- Replace the faulty V1 1.0.0 online-flasher artifact.
- Hardware smoke-tested on a K5 V1 on 2026-09-28: administrator startup and
  menu navigation work, reverse scrolling from `Step` through the battery
  service entries no longer produces a grey screen, stored English prompts
  are audible, and entries without a prompt fall back to Morse.
- Complete key-by-key acoustic regression and measured RF-output verification
  remain pending.

## K5 V1 1.0.0-rxonly-test

- Add a separate DP32G030 firmware tree for the original Quansheng UV-K5 V1.
- Normal power-on starts the protected user mode; holding `MENU` during power-on
  starts the complete administrator menu.
- Keep `UP`, `DOWN` and the acoustic ARDF PTT action available in user mode.
- Compile Richard's Morse and stored voice-sample paths with the full menu.
- Reject transmitter setup and force both PA bias and PA-enable controls off.
- Show `DO9RE-LX1WJ` and the abbreviated V1 version on the welcome screen.
- Publish only the required `.packed.bin` artifact for V1 online flashing.
- Build successfully with Arm GNU Toolchain 13.3.Rel1; target-radio and RF
  measurements remain required.

## 0.3.4-rxonly-test

- Stop an older asynchronous voice clip before announcing the newly selected
  menu item, preventing stale DMA buffers from causing sporadic silence.
- Discard a pending confirmation prompt when a menu announcement takes
  priority, so it cannot overwrite the selected item.
- Fall back to Morse when a mapped stored-voice sample is missing or invalid.
- Retain the `DO9RE-LX1WJ` credit, Admin/User separation and RX-only guards.

## 0.3.3-rxonly-test

- Refresh the menu display immediately after a short arrow press interrupts
  Morse, so the newly selected item is visible before it is announced.
- Slow held-arrow browsing to a 450 ms initial delay and 350 ms per following
  item, allowing sighted users to read menu labels.
- Retain the `DO9RE-LX1WJ` credit, accessibility modes and RX-only guards.

## 0.3.2-rxonly-test

- Show the shared credit `DO9RE-LX1WJ` on the first firmware line and the
  abbreviated `v0.32` on the line below.
- Preserve the safe two-line welcome layout that avoids framebuffer overflow.
- Let `UP` or `DOWN` interrupt a running Morse announcement immediately.
- Add held-arrow fast scrolling: after 280 ms, move every 100 ms without
  announcing intermediate entries; announce only the final entry on release.
- Retain Morse, stored voice samples, Admin/User mode and all RX-only guards.

## 0.3.1-rxonly-test

- Restore DO9RE visibly on the welcome screen as `DO9RE-RX Edition`, on a
  separate safe-width line below `LX1WJ v0.31`.
- Compile Richard's stored voice-sample engine and expanded ARDF voice prompts
  alongside Morse.
- Provide `Morse` and `Voice` choices in the `Access` menu.
- Restore the separate `Voice` setting with `Off`, `Chinese` and `English`.
- Keep SAM text-to-speech disabled and retain all five RX-only guard layers.
- Build successfully with Arm GNU Toolchain 13.3.Rel1; hardware testing is
  pending.

## 0.3.0-rxonly-test

- Build on the hardware-tested v0.2.4 Admin/User behaviour without changing
  the ARDF PTT snapshot/compass or Morse accessibility paths.
- Enable the existing global `ENABLE_PREVENT_TX` frequency and prepare-TX
  checks.
- Refuse `FUNCTION_TRANSMIT` centrally.
- Return from `RADIO_SetTxParameters()` before any TX register setup.
- Force PA bias and the external PA-enable GPIO off in both RF drivers.
- Use the short startup identifier `LX1WJ v0.30` to remain within the welcome
  renderer's safe width.
- Build successfully with Arm GNU Toolchain 13.3.Rel1; hardware and RF-output
  tests are still pending.

## 0.2.4-user-test

- Initial on-device smoke test reported successful on 2026-09-27; the full
  acoustic and transmit-path checklists are still pending.
- Build on the hardware-tested 0.2.3 administrator entry.
- Add only the protected normal-boot key filter while ARDF mode is active:
  allow `UP`, `DOWN`, and PTT; reject the other keys with a double beep.
- Keep Richard's original arrow direction handling and do not yet force ARDF
  mode or enable global TX prevention.

## 0.2.3-entry-test

- Hardware-tested successfully: normal boot, `UP`, `DOWN`, menu and audible
  test-fox reception work.
- Return to Richard's behaviour for normal operation.
- Retain only one Admin/User change: held `MENU` maps to Richard's existing
  `BOOT_MODE_F_LOCK` path.
- Temporarily remove user-key filtering, forced ARDF mode, and modified arrow
  handling so the administrator entry can be tested in isolation.
- Shorten the startup strings to fit the unbounded 128-pixel welcome-screen
  renderer; the earlier long strings wrote beyond the framebuffer.

## 0.2.2-test

- Remove Admin/User keypad polling and ARDF forcing from the early startup
  path after hardware testing showed that 0.2.1 still stopped on the welcome
  screen.
- Detect held `MENU` inside Richard's existing late boot-mode stage.
- Reuse the existing boot-lifetime `gF_LOCK` flag instead of adding another
  global variable.

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
