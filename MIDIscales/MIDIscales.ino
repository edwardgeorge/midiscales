#include <Adafruit_TinyUSB.h>
#include <MIDI.h>

Adafruit_USBD_MIDI usb_midi;

MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);
MIDI_CREATE_INSTANCE(Adafruit_USBD_MIDI, usb_midi, USB_MIDI);

//set MIDI channels: 144 = channel 1 note on, 128 = channel 1 note off, 145 = channel 2 note on, 129 = channel 2 note off etc..
//row 1
int MIDI_CH_ON1 = 144;
int MIDI_CH_OFF1 = 128;
//row 2
int MIDI_CH_ON2 = 144;
int MIDI_CH_OFF2 = 128;

int ROW1_CHAN = 1;
int ROW2_CHAN = 2;

//MIDI notes
int Cnote = 60;
int CSnote = 61;
int Dnote = 62;
int DSnote = 63;
int Enote = 64;
int Fnote = 65;
int FSnote = 66;
int Gnote = 67;
int GSnote = 68;
int Anote = 69;
int ASnote = 70;
int Bnote = 71;

//note swicthes
int S1;
int S2;
int S3;
int S4;
int S5;
int S6;
int S7;
int S8;
int S9;
int S10;
int S11;
int S12;
int S13;
int S14;
int S15;
int S16;

//standard octave
int octaveRow1 = 3;
int octaveRow2 = 4;

void setup() {
  if (!TinyUSBDevice.isInitialized()) {
    TinyUSBDevice.begin(0);
  }
  usb_midi.setStringDescriptor("FRUKU MIDI SCALES");
  // Set MIDI baud rate:
  //Serial1.begin(31250);
  MIDI.begin(MIDI_CHANNEL_OMNI);
  USB_MIDI.begin(MIDI_CHANNEL_OMNI);

  if (TinyUSBDevice.mounted()) {
    TinyUSBDevice.detach();
    delay(10);
    TinyUSBDevice.attach();
  }

  //set cmajor scale
  S1 = Cnote;
  S2 = Dnote;
  S3 = Enote;
  S4 = Fnote;
  S5 = Gnote;
  S6 = Anote;
  S7 = Bnote;
  S8 = Cnote+12;
  S9 = Cnote;
  S10 = Dnote;
  S11 = Enote;
  S12 = Fnote;
  S13 = Gnote;
  S14 = Anote;
  S15 = Bnote;
  S16 = Cnote+12;

  //define input pins
  for (int i = 1; i <= 27; i++) {
  pinMode(i, INPUT_PULLUP);
  }
}

void loop() {
  MIDI.read();

  //switch logic
  static bool button1valueOld = HIGH;
  static bool button2valueOld = HIGH;
  static bool button3valueOld = HIGH;
  static bool button4valueOld = HIGH;
  static bool button5valueOld = HIGH;
  static bool button6valueOld = HIGH;
  static bool button7valueOld = HIGH;
  static bool button8valueOld = HIGH;
  static bool button9valueOld = HIGH;
  static bool button10valueOld = HIGH;
  static bool button11valueOld = HIGH;
  static bool button12valueOld = HIGH;
  static bool button13valueOld = HIGH;
  static bool button14valueOld = HIGH;
  static bool button15valueOld = HIGH;
  static bool button16valueOld = HIGH;
  static bool button17valueOld = HIGH;
  static bool button18valueOld = HIGH;
  static bool button19valueOld = HIGH;
  static bool button20valueOld = HIGH;
  static bool button21valueOld = HIGH;
  static bool button22valueOld = HIGH;
  static bool button23valueOld = HIGH;
  static bool button24valueOld = HIGH;

  //switch logic
  bool button1valueNew = digitalRead(27);
  bool button2valueNew = digitalRead(21);
  bool button3valueNew = digitalRead(19);
  bool button4valueNew = digitalRead(16);
  bool button5valueNew = digitalRead(1);
  bool button6valueNew = digitalRead(3);
  bool button7valueNew = digitalRead(5);
  bool button8valueNew = digitalRead(7);
  bool button9valueNew = digitalRead(26);
  bool button10valueNew = digitalRead(22);
  bool button11valueNew = digitalRead(20);
  bool button12valueNew = digitalRead(18);
  bool button13valueNew = digitalRead(17);
  bool button14valueNew = digitalRead(2);
  bool button15valueNew = digitalRead(4);
  bool button16valueNew = digitalRead(6);
  bool button17valueNew = digitalRead(8);
  bool button18valueNew = digitalRead(9);
  bool button19valueNew = digitalRead(10);
  bool button20valueNew = digitalRead(11);
  bool button21valueNew = digitalRead(12);
  bool button22valueNew = digitalRead(15);
  bool button23valueNew = digitalRead(14);
  bool button24valueNew = digitalRead(13);

  //shift button
  if (button24valueNew != button24valueOld){
    if (button24valueNew == LOW){
      //turn off all midi notes
      for (int note = 0; note <=127; note++) {
        noteOff(note, 0, ROW1_CHAN);
        if (ROW1_CHAN != ROW2_CHAN) {
          noteOff(note, 0, ROW2_CHAN);
        }
      }
    }
     button24valueOld = button24valueNew;
  }

  //scale change
  //scale 1
  if (button21valueNew != button21valueOld){
    if (button21valueNew == LOW){
      //set cmajor scale
      S1 = Cnote;
      S2 = Dnote;
      S3 = Enote;
      S4 = Fnote;
      S5 = Gnote;
      S6 = Anote;
      S7 = Bnote;
      S8 = Cnote+12;
      S9 = Cnote;
      S10 = Dnote;
      S11 = Enote;
      S12 = Fnote;
      S13 = Gnote;
      S14 = Anote;
      S15 = Bnote;
      S16 = Cnote+12;
     }
     button21valueOld = button21valueNew;
  }

  //scale 2
  if (button22valueNew != button22valueOld){
    if (button22valueNew == LOW){
      //set cmajor scale
      S1 = Cnote;
      S2 = Dnote;
      S3 = DSnote;
      S4 = Fnote;
      S5 = Gnote;
      S6 = GSnote;
      S7 = ASnote;
      S8 = Cnote+12;
      S9 = Cnote;
      S10 = Dnote;
      S11 = DSnote;
      S12 = Fnote;
      S13 = Gnote;
      S14 = GSnote;
      S15 = ASnote;
      S16 = Cnote+12;
     }
     button22valueOld = button22valueNew;
  }

  //scale 3
  if (button23valueNew != button23valueOld){
    if (button23valueNew == LOW){
      //set cmajor scale
      S1 = Cnote;
      S2 = DSnote;
      S3 = Fnote;
      S4 = FSnote;
      S5 = Gnote;
      S6 = ASnote;
      S7 = Cnote+12;
      S8 = DSnote+12;
      S9 = Cnote;
      S10 = DSnote;
      S11 = Fnote;
      S12 = FSnote;
      S13 = Gnote;
      S14 = ASnote;
      S15 = Cnote+12;
      S16 = DSnote+12;
     }
     button23valueOld = button23valueNew;
  }


  //octave changes
  //octave down row 1
  if (button17valueNew != button17valueOld){
    if (button17valueNew == LOW){
      octaveRow1--;
      if (octaveRow1 < -1 ) octaveRow1 = -1;
     }
     button17valueOld = button17valueNew;
  }

  //octave up row 1
  if (button18valueNew != button18valueOld){
    if (button18valueNew == LOW){
      octaveRow1++;
      if (octaveRow1 > 9) octaveRow1 = 9;
     }
     button18valueOld = button18valueNew;
  }

  //octave down row 2
  if (button19valueNew != button19valueOld){
    if (button19valueNew == LOW){
      octaveRow2--;
      if (octaveRow2 < -1 ) octaveRow2 = -1;
     }
     button19valueOld = button19valueNew;
  }

  //octave up row 2
  if (button20valueNew != button20valueOld){
    if (button20valueNew == LOW){
      octaveRow2++;
      if (octaveRow2 > 9) octaveRow2 = 9;
     }
     button20valueOld = button20valueNew;
  }


  //key pressed row 2
  //switch 1
  if (button1valueNew != button1valueOld){
    if (button1valueNew == LOW){
      noteOn(S1 + (12 * (octaveRow2 - 4)), 127, ROW2_CHAN);
     }
    else {
      noteOff(S1 + (12 * (octaveRow2 - 4)), 0, ROW2_CHAN);
    }
     button1valueOld = button1valueNew;
  }

  //switch 2
  if (button2valueNew != button2valueOld){
    if (button2valueNew == LOW){
      noteOn(S2 + (12 * (octaveRow2 - 4)), 127, ROW2_CHAN);
     }
    else {
      noteOff(S2 + (12 * (octaveRow2 - 4)), 0, ROW2_CHAN);
    }
     button2valueOld = button2valueNew;
  }

  //switch 3
  if (button3valueNew != button3valueOld){
    if (button3valueNew == LOW){
      noteOn(S3 + (12 * (octaveRow2 - 4)), 127, ROW2_CHAN);
     }
    else {
      noteOff(S3 + (12 * (octaveRow2 - 4)), 0, ROW2_CHAN);
    }
     button3valueOld = button3valueNew;
  }

  //switch 4
  if (button4valueNew != button4valueOld){
    if (button4valueNew == LOW){
      noteOn(S4 + (12 * (octaveRow2 - 4)), 127, ROW2_CHAN);
     }
    else {
      noteOff(S4 + (12 * (octaveRow2 - 4)), 0, ROW2_CHAN);
    }
     button4valueOld = button4valueNew;
  }

  //switch 5
  if (button5valueNew != button5valueOld){
    if (button5valueNew == LOW){
      noteOn(S5 + (12 * (octaveRow2 - 4)), 127, ROW2_CHAN);
     }
    else {
      noteOff(S5 + (12 * (octaveRow2 - 4)), 0, ROW2_CHAN);
    }
     button5valueOld = button5valueNew;
  }

  //switch 6
  if (button6valueNew != button6valueOld){
    if (button6valueNew == LOW){
      noteOn(S6 + (12 * (octaveRow2 - 4)), 127, ROW2_CHAN);
     }
    else {
      noteOff(S6 + (12 * (octaveRow2 - 4)), 0, ROW2_CHAN);
    }
     button6valueOld = button6valueNew;
  }

  //switch 7
  if (button7valueNew != button7valueOld){
    if (button7valueNew == LOW){
      noteOn(S7 + (12 * (octaveRow2 - 4)), 127, ROW2_CHAN);
     }
    else {
      noteOff(S7 + (12 * (octaveRow2 - 4)), 0, ROW2_CHAN);
    }
     button7valueOld = button7valueNew;
  }

  //switch 8
  if (button8valueNew != button8valueOld){
    if (button8valueNew == LOW){
      noteOn(S8 + (12 * (octaveRow2 - 4)), 127, ROW2_CHAN);
     }
    else {
      noteOff(S8 + (12 * (octaveRow2 - 4)), 0, ROW2_CHAN);
    }
     button8valueOld = button8valueNew;
  }


  //key pressed row 1
  //switch 9
  if (button9valueNew != button9valueOld){
    if (button9valueNew == LOW){
      noteOn(S9 + (12 * (octaveRow1 - 4)), 127, ROW1_CHAN);
     }
    else {
      noteOff(S9 + (12 * (octaveRow1 - 4)), 0, ROW1_CHAN);
    }
     button9valueOld = button9valueNew;
  }

  //switch 10
  if (button10valueNew != button10valueOld){
    if (button10valueNew == LOW){
      noteOn(S10 + (12 * (octaveRow1 - 4)), 127, ROW1_CHAN);
     }
    else {
      noteOff(S10 + (12 * (octaveRow1 - 4)), 0, ROW1_CHAN);
    }
     button10valueOld = button10valueNew;
  }

  //switch 11
  if (button11valueNew != button11valueOld){
    if (button11valueNew == LOW){
      noteOn(S11 + (12 * (octaveRow1 - 4)), 127, ROW1_CHAN);
     }
    else {
      noteOff(S11 + (12 * (octaveRow1 - 4)), 0, ROW1_CHAN);
    }
     button11valueOld = button11valueNew;
  }

  //switch 12
  if (button12valueNew != button12valueOld){
    if (button12valueNew == LOW){
      noteOn(S12 + (12 * (octaveRow1 - 4)), 127, ROW1_CHAN);
     }
    else {
     noteOff(S12 + (12 * (octaveRow1 - 4)), 0, ROW1_CHAN);
    }
     button12valueOld = button12valueNew;
  }

  //switch 13
  if (button13valueNew != button13valueOld){
    if (button13valueNew == LOW){
      noteOn(S13 + (12 * (octaveRow1 - 4)), 127, ROW1_CHAN);
     }
    else {
      noteOff(S13 + (12 * (octaveRow1 - 4)), 0, ROW1_CHAN);
    }
     button13valueOld = button13valueNew;
  }

  //switch 14
  if (button14valueNew != button14valueOld){
    if (button14valueNew == LOW){
      noteOn(S14 + (12 * (octaveRow1 - 4)), 127, ROW1_CHAN);
     }
    else {
      noteOff(S14 + (12 * (octaveRow1 - 4)), 0, ROW1_CHAN);
    }
     button14valueOld = button14valueNew;
  }

  //switch 15
  if (button15valueNew != button15valueOld){
    if (button15valueNew == LOW){
      noteOn(S15 + (12 * (octaveRow1 - 4)), 127, ROW1_CHAN);
     }
    else {
      noteOff(S15 + (12 * (octaveRow1 - 4)), 0, ROW1_CHAN);
    }
     button15valueOld = button15valueNew;
  }

  //switch 16
  if (button16valueNew != button16valueOld){
    if (button16valueNew == LOW){
      noteOn(S16 + (12 * (octaveRow1 - 4)), 127, ROW1_CHAN);
     }
    else {
      noteOff(S16 + (12 * (octaveRow1 - 4)), 0, ROW1_CHAN);
    }
     button16valueOld = button16valueNew;
  }

delay(25);
}

void noteOn(int pitch, int velocity, int channel) {
  MIDI.sendNoteOn(pitch, velocity, channel);
  USB_MIDI.sendNoteOn(pitch, velocity, channel);
  //Serial1.write(cmd);
  //Serial1.write(pitch);
  //Serial1.write(velocity);
}

void noteOff(int pitch, int velocity, int channel) {
  MIDI.sendNoteOff(pitch, velocity, channel);
  USB_MIDI.sendNoteOff(pitch, velocity, channel);
}
