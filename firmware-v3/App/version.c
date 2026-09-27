
#ifdef VERSION_STRING
    #define VER     " "VERSION_STRING
#else
    #define VER     ""
#endif

#ifdef ENABLE_FEAT_F4HWN
#ifdef ENABLE_ADMIN_USER_MODE
    // Keep the shared authorship and version on separate short welcome lines.
    // Combining both callsigns and the version previously exceeded the
    // unbounded small-text renderer and corrupted the framebuffer.
    const char Version[]      = "DO9RE-LX1WJ";
    const char Edition[]      = VERSION_STRING_2;
#else
    const char Version[]      = AUTHOR_STRING_2 " " VERSION_STRING_2;
    const char Edition[]      = EDITION_STRING;
#endif
#else
    const char Version[]      = AUTHOR_STRING VER;
#endif

const char UART_Version[] = "UV-K5 Firmware, " AUTHOR_STRING VER "\r\n";
