int photocellPin = 0;     // the cell and 10K pulldown are connected to a0
int pRead;     // the analog reading from the sensor divider
int count;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  writeHigh();
}

void loop() {
  pRead = analogRead(photocellPin);
  // put your main code here, to run repeatedly:
 
  Serial.print("Analog reading = ");
  Serial.println(pRead);     // the raw analog reading

  
  if( pRead < 100 )
  {
    writeLow();
    count = 0;
  }
  else if( pRead > 100 && count > 30 )
  {
    writeHigh();
  }
  count ++;
  delay(1000);
}

void writeLow() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
}

void writeHigh() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
}

