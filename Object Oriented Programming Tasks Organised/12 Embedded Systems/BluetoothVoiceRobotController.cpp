#include <SoftwareSerial.h>

SoftwareSerial BT(0, 1); //TX, RX respetively
String readvoice;

void setup() {
    BT.begin(9600);
    Serial.begin(9600);
    pinMode(9, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);

}
-----------------------------------------------------------------------// 
void loop() {
    while (BT.available()) {  //Check if there is an available byte to read
        delay(10); //Delay added to make thing stable
        char c = BT.read(); //Conduct a serial read
        readvoice += c; //build the string- "forward", "reverse", "left" and "right"
    }
    if (readvoice.length() > 0) {
        Serial.println(readvoice);

        if (readvoice == "*forward#")
        {
            digitalWrite(8, HIGH);
            digitalWrite(9, HIGH);
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
            delay(100);
        }

        else if (readvoice == "*back#" || readvoice == "*Back#")
        {
            digitalWrite(8, LOW);
            digitalWrite(9, LOW);
            digitalWrite(10, HIGH);
            digitalWrite(11, HIGH);
            delay(100);
        }

        else if (readvoice == "*left#" || readvoice == "*Left#")
        {
            digitalWrite(8, HIGH);
            digitalWrite(9, LOW);
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
            delay(800);
            digitalWrite(8, HIGH);
            digitalWrite(9, HIGH);
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
            delay(100);

        }

        else if (readvoice == "*right#" || readvoice == "*write#" || readvoice == "*Right#" || readvoice == "*Write#")
        {
            digitalWrite(8, LOW);
            digitalWrite(9, HIGH);
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
            delay(800);
            digitalWrite(8, HIGH);
            digitalWrite(9, HIGH);
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
            delay(100);
        }

        else if (readvoice == "*stop#" || readvoice == "*Stop#")
        {
            digitalWrite(8, LOW);
            digitalWrite(9, LOW);
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
            delay(100);
        }
        else if (readvoice == "*bonus absolute#" || readvoice == "*Bonus Absolute#" || readvoice == "*Bonus absolute#" || readvoice == "*bonus Absolute#") //keep watch in all directions
        {
            digitalWrite(8, HIGH);
            digitalWrite(9, LOW);
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
            delay(100);
        }
        else if (readvoice == "*surprise them#" || readvoice == "*Surprise them#" || readvoice == "*surprise Them#" || readvoice == "*Surprise Them#") //show me Garba
        {
            digitalWrite(8, LOW);
            digitalWrite(9, HIGH);
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
            delay(400);
            digitalWrite(8, HIGH);
            digitalWrite(9, HIGH);
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
            delay(600);
            digitalWrite(8, LOW);
            digitalWrite(9, HIGH);
            digitalWrite(10, HIGH);
            digitalWrite(11, LOW);
            delay(500);
            digitalWrite(8, HIGH);
            digitalWrite(9, LOW);
            digitalWrite(10, LOW);
            digitalWrite(11, HIGH);
            delay(500);

            digitalWrite(8, LOW);
            digitalWrite(9, HIGH);
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
            delay(400);
            digitalWrite(8, HIGH);
            digitalWrite(9, HIGH);
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
            delay(600);
            digitalWrite(8, LOW);
            digitalWrite(9, HIGH);
            digitalWrite(10, HIGH);
            digitalWrite(11, LOW);
            delay(500);
            digitalWrite(8, HIGH);
            digitalWrite(9, LOW);
            digitalWrite(10, LOW);
            digitalWrite(11, HIGH);
            delay(500);digitalWrite(8, LOW);
            digitalWrite(9, HIGH);
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
            delay(400);
            digitalWrite(8, HIGH);
            digitalWrite(9, HIGH);
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
            delay(600);
            digitalWrite(8, LOW);
            digitalWrite(9, HIGH);
            digitalWrite(10, HIGH);
            digitalWrite(11, LOW);
            delay(500);
            digitalWrite(8, HIGH);
            digitalWrite(9, LOW);
            digitalWrite(10, LOW);
            digitalWrite(11, HIGH);
            delay(500);digitalWrite(8, LOW);
            digitalWrite(9, HIGH);
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
            delay(400);
            digitalWrite(8, HIGH);
            digitalWrite(9, HIGH);
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
            delay(600);
            digitalWrite(8, LOW);
            digitalWrite(9, HIGH);
            digitalWrite(10, HIGH);
            digitalWrite(11, LOW);
            delay(500);
            digitalWrite(8, HIGH);
            digitalWrite(9, LOW);
            digitalWrite(10, LOW);
            digitalWrite(11, HIGH);
            delay(500);digitalWrite(8, LOW);
            digitalWrite(9, HIGH);
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
            delay(400);
            digitalWrite(8, HIGH);
            digitalWrite(9, HIGH);
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
            delay(600);
            digitalWrite(8, LOW);
            digitalWrite(9, HIGH);
            digitalWrite(10, HIGH);
            digitalWrite(11, LOW);
            delay(500);
            digitalWrite(8, HIGH);
            digitalWrite(9, LOW);
            digitalWrite(10, LOW);
            digitalWrite(11, HIGH);
            delay(500);digitalWrite(8, LOW);
            digitalWrite(9, HIGH);
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
            delay(400);
            digitalWrite(8, HIGH);
            digitalWrite(9, HIGH);
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
            delay(600);
            digitalWrite(8, LOW);
            digitalWrite(9, HIGH);
            digitalWrite(10, HIGH);
            digitalWrite(11, LOW);
            delay(500);
            digitalWrite(8, HIGH);
            digitalWrite(9, LOW);
            digitalWrite(10, LOW);
            digitalWrite(11, HIGH);
            delay(500);digitalWrite(8, LOW);
            digitalWrite(9, HIGH);
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
            delay(400);
            digitalWrite(8, HIGH);
            digitalWrite(9, HIGH);
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
            delay(600);
            digitalWrite(8, LOW);
            digitalWrite(9, HIGH);
            digitalWrite(10, HIGH);
            digitalWrite(11, LOW);
            delay(500);
            digitalWrite(8, HIGH);
            digitalWrite(9, LOW);
            digitalWrite(10, LOW);
            digitalWrite(11, HIGH);
            delay(500);digitalWrite(8, LOW);
            digitalWrite(9, HIGH);
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
            delay(400);
            digitalWrite(8, HIGH);
            digitalWrite(9, HIGH);
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
            delay(600);
            digitalWrite(8, LOW);
            digitalWrite(9, HIGH);
            digitalWrite(10, HIGH);
            digitalWrite(11, LOW);
            delay(500);
            digitalWrite(8, HIGH);
            digitalWrite(9, LOW);
            digitalWrite(10, LOW);
            digitalWrite(11, HIGH);
            delay(500);
        }


        readvoice = "";
    }
} //Reset the variable