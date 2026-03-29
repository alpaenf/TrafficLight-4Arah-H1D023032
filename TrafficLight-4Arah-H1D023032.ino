// Utara
int m1=13, k1=12, h1=11;
// Timur
int m2=10, k2=9, h2=8;
// Selatan
int m3=7, k3=6, h3=5;
// Barat
int m4=4, k4=3, h4=2;

int merah[] = {m1,m2,m3,m4};
int kuning[] = {k1,k2,k3,k4};
int hijau[] = {h1,h2,h3,h4};

void setup() {
  for(int i=0;i<4;i++){
    pinMode(merah[i], OUTPUT);
    pinMode(kuning[i], OUTPUT);
    pinMode(hijau[i], OUTPUT);
  }
}

void semuaMerah(){
  for(int i=0;i<4;i++){
    digitalWrite(merah[i], HIGH);
    digitalWrite(kuning[i], LOW);
    digitalWrite(hijau[i], LOW);
  }
}

// kuning kedip 3x dalam 2 detik
void kuningKedip(int pin){
  for(int i=0;i<3;i++){
    digitalWrite(pin, HIGH);
    delay(300);
    digitalWrite(pin, LOW);
    delay(300);
  }
}

void aktifkanSimpang(int i){
  semuaMerah();

  // hijau nyala
  digitalWrite(merah[i], LOW);
  digitalWrite(hijau[i], HIGH);
  delay(5000);

  // kuning kedip
  digitalWrite(hijau[i], LOW);
  kuningKedip(kuning[i]);

  // kembali merah
  digitalWrite(merah[i], HIGH);
}

void loop(){
  for(int i=0;i<4;i++){
    aktifkanSimpang(i);
  }
}