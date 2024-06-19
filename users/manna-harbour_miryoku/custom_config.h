#pragma once

// Define the keycodes for the combos
enum combo_events {
    COMBO_AE,
    COMBO_OE,
    COMBO_UE,
    COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

// Define the combo key arrays
const uint16_t PROGMEM ae_combo[] = {KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM oe_combo[] = {KC_O, KC_E, COMBO_END};
const uint16_t PROGMEM ue_combo[] = {KC_U, KC_E, COMBO_END};

// Define the combo actions
combo_t key_combos[COMBO_LENGTH] = {
    [COMBO_AE] = COMBO(ae_combo, KC_QUOT),  // For ä
    [COMBO_OE] = COMBO(oe_combo, KC_QUOT),  // For ö
    [COMBO_UE] = COMBO(ue_combo, KC_QUOT)   // For ü
};

// Function to handle special characters
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case COMBO_AE:
                tap_code16(KC_QUOT);
                tap_code(KC_A);
                return false;
            case COMBO_OE:
                tap_code16(KC_QUOT);
                tap_code(KC_O);
                return false;
            case COMBO_UE:
                tap_code16(KC_QUOT);
                tap_code(KC_U);
                return false;
        }
    }
    return true;
}

// Override the COMBO_TERM if needed (optional)
uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch(index) {
        case COMBO_AE:
        case COMBO_OE:
        case COMBO_UE:
            return 50; // Adjust this value as needed
        default:
            return COMBO_TERM;
    }
}
