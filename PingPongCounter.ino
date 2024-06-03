#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int buttonPinOne = 7;
const int buttonPinTwo = 8;  // the number of the pushbutton pin
int buttonStateOne = 0;
int buttonStateTwo = 0;
int lastButtonStateOne = 0;
int lastButtonStateTwo = 0;
int playerOne = 0;
int playerTwo = 0;


void setup() {
  pinMode(buttonPinOne, INPUT);
  pinMode(buttonPinTwo, INPUT);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
}

void loop() {
  buttonStateOne = digitalRead(buttonPinOne);
  buttonStateTwo = digitalRead(buttonPinTwo);


  // check if the pushbutton is pressed. If it is, the buttonStateOne is HIGH:
  if (buttonStateOne != lastButtonStateOne) {
    playerOne++;
    delay(150);
  } else if (buttonStateTwo != lastButtonStateTwo) {
    playerTwo++;
    delay(150);
  }
  

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  lcd.print("Player 1: " + String(playerOne));
  lcd.setCursor(0, 1);
  lcd.print("Player 2: " + String(playerTwo));
  
  if (playerOne >= 11) {
    while(true) {
      lcd.setCursor(0, 0);
      lcd.print("Player 1 one!");
      lcd.setCursor(0, 1);
      lcd.print("Player 2 lose");
    }
  }
    if (playerTwo >= 11) {
      while(true) {
        lcd.setCursor(0, 0);
        lcd.print("Player 2 won!");
        lcd.setCursor(0, 1);
        lcd.print("Player 1 lose");
      }
  }
  // print the number of seconds since reset:
}

