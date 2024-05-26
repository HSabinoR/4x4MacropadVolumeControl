// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "analog.h"
#include "qmk_midi.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    [0] = LAYOUT_4x4(
        C(S(KC_M)),   C(S(KC_D)),   LWIN(KC_4),   LWIN(KC_7),
        KC_MEDIA_PREV_TRACK,   KC_MEDIA_PLAY_PAUSE,   KC_MEDIA_NEXT_TRACK,   KC_MEDIA_STOP,
        LWIN(KC_3),   LWIN(KC_5),   LWIN(KC_6),  KC_AUDIO_MUTE,
        LWIN(KC_L),   A(KC_F4), KC_F15, TO(1)
    ),
    [1] = LAYOUT_4x4(
        S(KC_F13), S(KC_F14), S(KC_F15), S(KC_F16),
        S(KC_F17), S(KC_F18), S(KC_F19), S(KC_F20),
        S(KC_F21), S(KC_F22), S(KC_F23), S(KC_F24),
        C(S(KC_F13)), C(S(KC_F14)), C(S(KC_F15)), TO(0)
        )
};

uint8_t last_readA = 0;
uint8_t current_readA = 0;
uint8_t last_readB = 0;
uint8_t current_readB = 0;
uint8_t last_readC = 0;
uint8_t current_readC = 0;
uint8_t last_readD = 0;
uint8_t current_readD = 0;
uint8_t last_readE = 0;
uint8_t current_readE = 0;

void slider(void) {
    uint8_t current_layer = get_highest_layer(layer_state);

    uint8_t current_readA = (analogReadPin(SLIDER_PINA) +last_readA)/8; //filter strength
 
    if (current_readA != last_readA ) { // (&midi_device, chan, message, max control value - (current pin reading) >>resolution)
        if (current_layer == 1) {
            midi_send_cc(&midi_device, 2, 0x30, 0x7F - (analogReadPin(SLIDER_PINA) >>3));
        }
        else {
            midi_send_cc(&midi_device, 1, 0x30, 0x7F - (analogReadPin(SLIDER_PINA) >>3));
            }
 
    last_readA = current_readA;
    }
 

    uint8_t current_readB = (analogReadPin(SLIDER_PINB) +last_readB)/8;
 
    if (current_readB != last_readB ) {
        if (current_layer == 1) {
            midi_send_cc(&midi_device, 2, 0x31, 0x7F - (analogReadPin(SLIDER_PINB) >>3));
        }
        else {
            midi_send_cc(&midi_device, 1, 0x31, 0x7F - (analogReadPin(SLIDER_PINB) >>3));
        }
    last_readB = current_readB;
    }


    uint8_t current_readC = (analogReadPin(SLIDER_PINC) +last_readC)/8;
 
    if (current_readC != last_readC ) {
        if (current_layer == 1) {
            midi_send_cc(&midi_device, 2, 0x32, 0x7F - (analogReadPin(SLIDER_PINC) >>3));
        }
        else {
            midi_send_cc(&midi_device, 1, 0x32, 0x7F - (analogReadPin(SLIDER_PINC) >>3));
        }

    last_readC = current_readC;
    }

    uint8_t current_readD = (analogReadPin(SLIDER_PIND) +last_readD)/8;
 
    if (current_readD != last_readD ) {
        if (current_layer == 1) {
            midi_send_cc(&midi_device, 2, 0x33, 0x7F - (analogReadPin(SLIDER_PIND) >>3));
        }
        else {
            midi_send_cc(&midi_device, 1, 0x33, 0x7F - (analogReadPin(SLIDER_PIND) >>3));
        }
 
    last_readD = current_readD;
    }

    uint8_t current_readE = (analogReadPin(SLIDER_PINE) +last_readE)/8;
 
    if (current_readE != last_readE ) {
        if (current_layer == 1) {
            midi_send_cc(&midi_device, 2, 0x34, 0x7F - (analogReadPin(SLIDER_PINE) >>3));
        } else {
            midi_send_cc(&midi_device, 1, 0x34, 0x7F - (analogReadPin(SLIDER_PINE) >>3));
        }
    last_readE = current_readE;
    }
 
}

 
void matrix_scan_user(void) {
    slider();
}