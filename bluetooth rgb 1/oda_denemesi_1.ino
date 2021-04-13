const int kirmiziPin = 3;
const int yesilPin = 4;
const int maviPin = 2;
int veri;


int x = 0;
int y = 0;
int z = 0;

void setup()
{
  int x = 0;
  Serial.begin(9600);
  pinMode(kirmiziPin, OUTPUT);
  pinMode(yesilPin, OUTPUT);
  pinMode(maviPin, OUTPUT);
  digitalWrite(kirmiziPin, LOW);
  digitalWrite(yesilPin, LOW);
  digitalWrite(maviPin, LOW);
}
void loop()
{
  if (Serial.available() > 0)
  {
    veri = Serial.read();
  }
  if (veri == 'r')
  {
    for (int efe = 0; efe < 10; efe++)
    {
      digitalWrite(kirmiziPin, HIGH);
      delay(310);
      digitalWrite(kirmiziPin, LOW);

      digitalWrite(kirmiziPin, HIGH);
      digitalWrite(yesilPin, HIGH);
      delay(310);
      digitalWrite(kirmiziPin, LOW);
      digitalWrite(yesilPin, LOW);

      digitalWrite(yesilPin, HIGH);
      delay(310);
      digitalWrite(yesilPin, LOW);

      digitalWrite(yesilPin, HIGH);
      digitalWrite(maviPin, HIGH);
      delay(310);
      digitalWrite(yesilPin, LOW);
      digitalWrite(maviPin, LOW);

      digitalWrite(maviPin, HIGH);
      delay(310);
      digitalWrite(maviPin, LOW);

      digitalWrite(kirmiziPin, HIGH);
      digitalWrite(maviPin, HIGH);
      delay(310);
      digitalWrite(kirmiziPin, LOW);
      digitalWrite(maviPin, LOW);
    }
  }

  if (veri == 'R')
  {
    for (int i = 0; i < 255; i = i + 1)
    {
      x -= 1;
      y += 1;
      analogWrite(kirmiziPin, x);
      analogWrite(yesilPin, y);
      delay(10);
    }

    x = 0;
    y = 255;
    z = 0;

    for (int i = 0; i < 255; i = i + 1)
    {
      y -= 1;
      z += 1;
      analogWrite(yesilPin, y);
      analogWrite(maviPin, z);
      delay(10);
    }
    x = 0;
    y = 0;
    z = 255;

    for (int i = 0; i < 255; i = i + 1)
    {
      z -= 1;
      x += 1;
      analogWrite(maviPin, z);
      analogWrite(kirmiziPin, x);
      delay(10);
    }
    x = 255;
    y = 0;
    z = 0;
  }
  if (veri == 'k')
  {
    digitalWrite(kirmiziPin, HIGH);
    digitalWrite(yesilPin, LOW);
    digitalWrite(maviPin, LOW);
  }
  if (veri == 'y')
  {
    digitalWrite(kirmiziPin, LOW);
    digitalWrite(yesilPin, HIGH);
    digitalWrite(maviPin, LOW);
  }
  if (veri == 'm')
  {
    digitalWrite(kirmiziPin, LOW);
    digitalWrite(yesilPin, LOW);
    digitalWrite(maviPin, HIGH);
  }
  if (veri == 'x')
  {
    digitalWrite(kirmiziPin, LOW);
    digitalWrite(yesilPin, LOW);
    digitalWrite(maviPin, LOW);
    x = 0;
    y = 0;
    z = 0;
  }
}
