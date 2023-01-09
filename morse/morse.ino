#include <string.h>

int ledPin = 4;
void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  morse("SOS");
  delay(1000);
  morse("Hallo Welt");
  delay(1000);
}

// character map
const char *mymap[] = {
    ".-",	/* a */
    "-...",	/* b */
    "-.-.",	/* c */
    "-..",	/* d */
    ".",	/* e */
    "..-.",	/* f */
    "--.",	/* g */
    "....",	/* h */
    "..",	/* i */
    ".---",	/* j */
    "-.-",	/* k */
    ".-..",	/* l */
    "--",	/* m */
    "-.",	/* n */
    "---",	/* o */
    ".--.",	/* p */
    "--.-",	/* q */
    ".-.",	/* r */
    "...",	/* s */
    "-",	/* t */
    "..-",	/* u */
    "...-",	/* v */
    ".--",	/* w */
    "-..-",	/* x */
    "-.--",	/* y */
    "--..",     /* z */
    "-----",	/* 0 */
    ".----",	/* 1 */
    "..---",	/* 2 */
    "...--",	/* 3 */
    "....-",	/* 4 */
    ".....",	/* 5 */
    "-....",	/* 6 */
    "--...",	/* 7 */
    "---..",	/* 8 */
    "----.",	/* 9 */
};

const unsigned int dit = 200;
const unsigned int dah = 3 * dit;
const unsigned int pause_symbol = 1 * dit;
const unsigned int pause_letter = 3 * dit;
const unsigned int pause_word   = 7 * dit;


// convert text to morse
void morse(const char s[]) {
  // loop over all characters
  for (unsigned int i=0; i<strlen(s); i++) {
    blink(getcode(s[i]));
  }
}

// convert morse to blink
void blink(const char s[]) {
  for (unsigned int i=0; i<strlen(s); i++) {
    if (s[i] == '.')
      blink(dit);
    if (s[i] == '-')
      blink(dah);
    if (s[i] == ' ')
      delay(pause_word);
    delay(pause_symbol);
  }
  delay(pause_letter);  
}

void blink(unsigned int length) {
  digitalWrite(ledPin, HIGH);   
  delay(length);                     
  digitalWrite(ledPin, LOW);    
}

const char* getcode(char c) {
  if (c > 96 && c < 123)  // lower case letter
    return mymap[c-97];
  if (c > 64 && c < 91)   // upper case letter
    return mymap[c-65];
  if (c > 47 && c < 58)   // number
    return mymap[c-22];
  return " ";             // other → pause
}