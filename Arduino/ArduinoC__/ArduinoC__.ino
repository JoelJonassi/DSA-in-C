
class Blink{
  private:
    int led;
  public:
    Blink(int led);
    int getLed();
    void blinkLed(int l, int timeHigh, int timeLow);
 };

 Blink:: Blink(int led){
    this->led = led;

 }
 int Blink::getLed(){
  return this->led;
 }
 void Blink::blinkLed(int l, int timeHigh, int timeLow){
   digitalWrite(l, HIGH);
   delay(timeHigh);
   digitalWrite(l,LOW);
   delay(timeLow);
 }
  
Blink* l1, *l2, *l3;
void setup(){
 l1 = new Blink(1);
 l2 = new Blink(13);
 pinMode(l1->getLed(), OUTPUT);
 pinMode(l2->getLed(), OUTPUT);
 pinMode(l3->getLed(), OUTPUT);
 Serial.begin(9600);
}

void loop(){
   l1->blinkLed(l1->getLed(), 500, 100);
   l2->blinkLed(l2->getLed(), 500, 100);
   Serial.print("teste");
}
