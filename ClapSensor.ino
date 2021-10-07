#define MicSamples (1024*2)
#define MicPin A1
 bool relay = false; 

// measure basic properties of the input signal
// determine if analog or digital, determine range and average.
void setup(){
  Serial.begin(9600);
 digitalWrite(13, HIGH);
  
  }
void loop(){

{
  pinMode(13, OUTPUT);
  

        long signalAvg = 0, signalMax = 0, signalMin = 1024, t0 = millis();
    for (int i = 0; i < MicSamples; i++)
    {
        int k = analogRead(MicPin);
        signalMin = min(signalMin, k);
        signalMax = max(signalMax, k);
        signalAvg += k;
    }
    signalAvg /= MicSamples;
      
 
    // print
    Serial.println(signalMax - signalAvg);
    if((signalMax - signalAvg)>12){
      if(relay == false){
      relay = true;
      Serial.println("Vklop");
      delay(1000);
      }
      else{
      relay = false;
      Serial.println("Izklop");
      delay(1000);
      }
      }
    if(relay == true){
      digitalWrite(13, HIGH);
      
      }
    else if(relay == false){ //bolje tako
      digitalWrite(13, LOW);
      
      }
 
}}
