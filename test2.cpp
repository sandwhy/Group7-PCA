int pp[] = {};
String pupu[] = {"a","b","c"};
int pupuLen = sizeof(pupu)/sizeof(pupu[0]);

void setup(){
    Serial.begin(9600);
    for(int i=0; i<pupuLen; i++){
        Serial.println(pupu[i]);
    }
    Serial.println(pupuLen);
    pupu[0] = "d";
        for(int i=0; i<pupuLen; i++){
        Serial.println(pupu[i]);
    }
}

void loop(){
}