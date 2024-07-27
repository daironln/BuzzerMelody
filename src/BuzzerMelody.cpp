#include "BuzzerMelody.h"

#pragma region CONSTRUCT_DESTRUCT
//Constructor
BuzzerMelody :: BuzzerMelody(int _buzzer, int _tempo, int _melodySize, int _melody[]){
    pinMode(_buzzer, OUTPUT);

    buzzer = _buzzer;
    tempo = _tempo;
    tam = _melodySize;

    melody = _melody;
}

//Destructor
BuzzerMelody :: ~BuzzerMelody(){}

#pragma endregion



#pragma region METHODS

auto BuzzerMelody :: playMelody() -> void {

    if(melody == NULL) return;
    
    Serial.println("Playing Melody");

    int t_notes {(tam) >> 1}, full_note {240000 / tempo}, div {}, note_time {};
    
    for (int i {}; i < (t_notes << 1); i += 2) {

        div = *(melody + (i + 1));

        note_time = div != 0 ? (full_note) / abs(div) : 0;
   
        note_time *= div < 0 ? 1.5 : 1;

        tone(buzzer, *(melody + i), note_time * (0x1 - 0.10));

        delay(note_time);

        noTone(buzzer);
    }
    
}

#pragma endregion