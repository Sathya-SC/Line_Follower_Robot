#define left_1 6
#define left_2 7
#define right_1 4
#define right_2  5
#define ena 8
#define enb 9

#define ir_l 2
#define ir_r 3

const int pins_in[2]={ir_l,ir_r};
const int pins_out[6]={left_1,left_2,right_1,right_2,ena,enb};

void setLogic(int a,int b,int c,int d)
{
  digitalWrite(left_1,a);
  digitalWrite(left_2,b);
  digitalWrite(right_1,c);
  digitalWrite(right_2,d);
}


void setup() {
  // put your setup code here, to run once:
for(int a=0;a<4;a++)
{
  pinMode(pins_out[a],OUTPUT);
}

for(int b=0;b<2;b++)
{
  pinMode(pins_in[b],INPUT);
}

Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
int a=digitalRead(ir_l);
int b=digitalRead(ir_r);

Serial.print("Left IR : ");
Serial.println(a);

Serial.print("Right IR : ");
Serial.println(b);


if(a==0 && b==0)
{
  //move forward
  setLogic(1,0,1,0);
}

else if(a==0 && b==1)
{
  //move left
  setLogic(1,0,0,0);
}
else if(a==1 && b==0)

delay(1000);

analogWrite(ena,250);
analogWrite(enb,250);

}
