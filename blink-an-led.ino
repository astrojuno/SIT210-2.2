// ----------------------------------------
// Blink an LED for your name in Morse Code
// ----------------------------------------

// Taken from the example code available at particle.io

// Altered here for my SIT210 Task 2.2

// First, we're going to make some variables.
// This is our "shorthand" that we'll use throughout the program:

int led1 = D0; // Instead of writing D0 over and over again, we'll write led1
// You'll need to wire an LED to this one to see it blink.

int led2 = D7; // Instead of writing D7 over and over again, we'll write led2
// This one is the little blue LED on your board. On the Photon it is next to D7, and on the Core it is next to the USB jack.

// Here are my timings. Remember, they're in milliseconds.
int dot = 300;
int dash = 900;
int pauseMidLetter = 300;
int pauseAfterLetter = 900;
int pauseAfterWord = 1200;

// Having declared these variables, let's move on to the setup function.
// The setup function is a standard part of any microcontroller program.
// It runs only once when the device boots up or is reset.

void setup() {

  // We are going to tell our device that D0 and D7 (which we named led1 and led2 respectively) are going to be output
  // (That means that we will be sending voltage to them, rather than monitoring voltage that comes from them)

  // It's important you do this here, inside the setup() function rather than outside it or in the loop function.

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

}

// Next we have the loop function, the other essential part of a microcontroller program.
// This routine gets repeated over and over, as quickly as possible and as many times as possible, after the setup function is called.
// Note: Code that blocks for too long (like more than 5 seconds), can make weird things happen (like dropping the network connection).  The built-in delay function shown below safely interleaves required background activity, so arbitrarily long delays can safely be done if you need them.

void loop() {
  // blink out my name in morse code
  blinkJ();
  delay(pauseAfterLetter);
  blinkO();
  delay(pauseAfterLetter);
  blinkH();
  delay(pauseAfterLetter);
  blinkN();
  
  delay(pauseAfterWord);

  // And repeat!
}

// blink the letter j
void blinkJ() {
    blinkDot();
    delay(pauseMidLetter);
    blinkDash();
    delay(pauseMidLetter);
    blinkDash();
    delay(pauseMidLetter);
    blinkDash();
}

// blink the letter o
void blinkO() {
	blinkDash();
    delay(pauseMidLetter);
    blinkDash();
    delay(pauseMidLetter);
    blinkDash();
}

// blink the letter h
void blinkH() {
	blinkDot();
    delay(pauseMidLetter);
    blinkDot();
    delay(pauseMidLetter);
    blinkDot();
    delay(pauseMidLetter);
    blinkDot();
}

// blink the letter n
void blinkN() {
	blinkDash();
    delay(pauseMidLetter);
    blinkDot();
}

// make the argon blink a dot (on for 300 milliseconds, then off)
void blinkDot() {
    digitalWrite(led2, HIGH);
    delay(dot);
    digitalWrite(led2, LOW);
}

// make the argon blink a dash (on for 900 milliseconds, then off)
void blinkDash() {
    digitalWrite(led2, HIGH);
    delay(dash);
    digitalWrite(led2, LOW);
}

