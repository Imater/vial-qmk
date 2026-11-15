// Copyright 2026 Ergohaven
// SPDX-License-Identifier: GPL-2.0-or-later
// Экран «дашборд»: рисует только то, что прислал хост (текст, полосы, прямоугольники).
#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "src/display/eh_display.h"

#define SM62_DASH_MAX_ELEMENTS 24

/* Безопасная область: скругления экрана режут ~12 px слева и ~8 px сверху/снизу */
#define SM62_DASH_PAD_LEFT 12
#define SM62_DASH_PAD_TOP 8
#define SM62_DASH_TEXT_BYTES 96

typedef enum {
    SM62_DASH_BEGIN = 0xC0,
    SM62_DASH_TEXT = 0xC1,
    SM62_DASH_BAR = 0xC2,
    SM62_DASH_RECT = 0xC3,
    SM62_DASH_COMMIT = 0xC4,
    SM62_DASH_SCREEN = 0xC5,
    SM62_DASH_INVERT = 0xC6,
} sm62_dash_type;

/* target: 0 — левая половина, 1 — правая, 2 — обе */
void sm62_dash_begin(uint8_t version, uint8_t target, uint8_t count);
void sm62_dash_text(uint8_t id, uint16_t x, uint16_t y, uint16_t width, uint8_t font, uint16_t color, uint8_t align, uint8_t flags, uint8_t offset, const uint8_t *data, uint8_t length);
void sm62_dash_bar(uint8_t id, uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t pos, uint32_t duration, uint16_t color, uint16_t background);
void sm62_dash_rect(uint8_t id, uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t color, uint8_t radius);
void sm62_dash_commit(void);
void sm62_dash_invert(bool on);
void sm62_dash_apply_invert(void);
void sm62_dash_reset_invert(void);

bool sm62_dash_has_frame(void);

extern const eh_screen_t eh_screen_dash;
