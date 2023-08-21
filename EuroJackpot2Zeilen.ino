#include <analogWrite.h>
#include <ESP32Tone.h>
#include <ESP32PWM.h>

#include <LiquidCrystal.h>
LiquidCrystal lcd(22, 23, 5, 18, 19, 21);

long int counter = 1;

  
void setup() {

  // Datenausgabe einrichten
  lcd.begin(16, 2);
  Serial.begin(9600);

  // Konstanten für die Entscheidungen einstellen

  long int ziehungen = 0;
  int finz = 0;
  int game = 0;
  int fingame = 0;
  long int Mkopf = 0;
  long int Mzahl = 0;
  long int winkel=0;


pinMode(33, OUTPUT); // Grüne Diode, welche das Ergebnis anzeigt! 
pinMode(32, OUTPUT); // Rote Diode, welche Berechnungen anzeigt!
pinMode(25, OUTPUT); // Blaue Diode, welche nächste Ziehung anzeigt!

digitalWrite(33, HIGH);
digitalWrite(32, HIGH);
digitalWrite(25, HIGH);


  // ******************* ENDE Void Setup
}

void loop() {



if(counter==1){

digitalWrite(33, HIGH);
digitalWrite(32, HIGH);
digitalWrite(25, HIGH);

lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("EuroJackpot");
    lcd.setCursor(0, 1);
    lcd.print("Simulator (2023)");
    delay (3000);
    lcd.setCursor(0, 0);
    lcd.print("Quantenfluxt so");
    lcd.setCursor(0, 1);
    lcd.print("vor sich hin...");
    delay (3000);
}

digitalWrite(33, LOW);
digitalWrite(32, LOW);
digitalWrite(25, HIGH);

lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ziehung: ");
    lcd.print(counter);
delay(1000);
lcd.clear();
counter++;

digitalWrite(33, LOW);
digitalWrite(32, HIGH);
digitalWrite(25, LOW);

    // Und nun das entsprechende Array für die Ziehung 5 aus 50 generieren

    long int Array[50] = {};
    long int Num[5] = {};
    long int Numfin[5] = {};
    long int Numfin2[5] = {};

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Berechnet");

    for (long int j = 0; j < 1000000; j++) {
      Array[random(0, 50)]++;
      if (j % (10000) < 1) {
        lcd.setCursor(0, 1);
        lcd.print(j / (10000));
        lcd.print(" Prozent...");
      }
    }

    // Die 6 am meisten gezogenen Zahlen identifizieren

    for (int drw = 0; drw < 5; drw++) {

      long int tst = 0;
      long int tst1 = 0;

      for (int k = 0; k < 50; k++) {
        if (Array[k] > tst) {
          tst = Array[k];
          tst1 = (k + 1);
        }
      }

      //Serial.println(tst1);
      Num[drw] = tst1;
      Array[tst1 - 1] = 0;
    }

    // Das Array mit den Zahlen nach Größe sortieren

    for (int drw = 0; drw < 5; drw++) {

      long int tst = 0;
      long int tst1 = 0;

      for (int k = 0; k < 5; k++) {
        if (Num[k] > tst) {
          tst = Num[k];
          tst1 = (k + 1);
        }
      }

      Serial.print(tst);
      Numfin[drw] = tst;
      if (drw < 4) {
        Serial.print("-");
      }
      Num[tst1 - 1] = 0;
    }

    // Und nun die Sortieung umkehren

    for (int k = 0; k < 5; k++) {
      Numfin2[4 - k] = Numfin[k];
    }

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(Numfin2[0]);
    lcd.print("-");
    lcd.print(Numfin2[1]);
    lcd.print("-");
    lcd.print(Numfin2[2]);
    lcd.print("-");
    lcd.print(Numfin2[3]);
    lcd.print("-");
    lcd.print(Numfin2[4]);


    // Jetzt das gleiche nochmal für die Zusatzzahlen (2 aus 10)

    long int Array2[12] = {};
    long int Num2[2] = {};
    long int Numfin3[2] = {};
    long int Numfin4[2] = {};


    lcd.setCursor(0, 1);
    lcd.print("wait...[%]:");

    for (long int j = 0; j < 1000000; j++) {
      Array2[random(0, 12)]++;
      if (j % (10000) < 1) {
        lcd.setCursor(11, 1);
        lcd.print(j / (10000));
      }
    }

    // Die 6 am meisten gezogenen Zahlen identifizieren

    for (int drw = 0; drw < 2; drw++) {

      long int tst = 0;
      long int tst1 = 0;

      for (int k = 0; k < 12; k++) {
        if (Array2[k] > tst) {
          tst = Array2[k];
          tst1 = (k + 1);
        }
      }

      //Serial.println(tst1);
      Num2[drw] = tst1;
      Array2[tst1 - 1] = 0;
    }

    // Das Array mit den Zahlen nach Größe sortieren

    for (int drw = 0; drw < 2; drw++) {

      long int tst = 0;
      long int tst1 = 0;

      for (int k = 0; k < 2; k++) {
        if (Num2[k] > tst) {
          tst = Num2[k];
          tst1 = (k + 1);
        }
      }

      
      Numfin3[drw] = tst;
      if (drw < 1) {
        
      }
      Num2[tst1 - 1] = 0;
    }

    // Und nun die Sortierung umkehren

    for (int k = 0; k < 2; k++) {
      Numfin4[1 - k] = Numfin3[k];
    }

// Finale Datenausgabe

digitalWrite(33, HIGH);
digitalWrite(32, LOW);

    lcd.setCursor(0, 1);
    lcd.print("Eurozl.: ");
    lcd.print(Numfin4[0]);
    lcd.print(" & ");
    lcd.print(Numfin4[1]);
    lcd.print("               ");

delay(2000);

  }
