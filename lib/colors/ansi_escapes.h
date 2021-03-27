#pragma once

#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <strings.h>

enum Colors {
    RESET_COLOR,
    BLACK_TXT = 30,
    RED_TXT,
    GREEN_TXT,
    YELLOW_TXT,
    BLUE_TXT,
    MAGENTA_TXT,
    CYAN_TXT,
    WHITE_TXT,
    BLACK_BKG = 40,
    RED_BKG,
    GREEN_BKG,
    YELLOW_BKG,
    BLUE_BKG,
    MAGENTA_BKG,
    CYAN_BKG,
    WHITE_BKG
};

enum ClearCodes {
    CLEAR_FROM_CURSOR_TO_END,
    CLEAR_FROM_CURSOR_TO_BEGIN,
    CLEAR_ALL
};

void setupConsole(void);
void restoreConsole(void);

static inline void set_text_color(int code) {
    printf("\x1b[%dm", code);
}

static inline char* get_text_color(int code, char char_list[]) {
    static char buffer[CHAR_MAX];
    snprintf(buffer, sizeof(buffer),
      "\x1b[%dm%s\x1b[%dm", code, char_list, RESET_COLOR
    );

    return (char*) buffer;
}

static inline void setTextColorBright(int code) {
    printf("\x1b[%d;1m", code);
}

static inline void setBackgroundColor(int code) {
    printf("\x1b[%dm", code);
}

static inline void setBackgroundColorBright(int code) {
    printf("\x1b[%d;1m", code);
}

static inline void resetColor(void) {
    printf("\x1b[%dm", RESET_COLOR);
}

#define print_text_color(code, ...) set_text_color(code); \
                            printf(__VA_ARGS__); \
                            resetColor()

static inline void clearScreen(void) {
    printf("\x1b[%dJ", CLEAR_ALL);
}

static inline void clearScreenToBottom(void) {
    printf("\x1b[%dJ", CLEAR_FROM_CURSOR_TO_END);
}

static inline void clearScreenToTop(void) {
    printf("\x1b[%dJ", CLEAR_FROM_CURSOR_TO_BEGIN);
}

static inline void clearLine(void) {
    printf("\x1b[%dK", CLEAR_ALL);
}

static inline void clearLineToRight(void) {
    printf("\x1b[%dK", CLEAR_FROM_CURSOR_TO_END);
}

static inline void clearLineToLeft(void) {
    printf("\x1b[%dK", CLEAR_FROM_CURSOR_TO_BEGIN);
}
