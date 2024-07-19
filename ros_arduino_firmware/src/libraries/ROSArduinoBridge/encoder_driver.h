/* *************************************************************
   Encoder driver function definitions - by James Nugen
   ************************************************************ */


#ifdef ARDUINO_ENC_COUNTER
  //below can be changed, but should be PORTD pins; 
  //otherwise additional changes in the code are required
  #define LEFT_ENC_PIN_A PD2  //pin 2
  #define LEFT_ENC_PIN_B PD3  //pin 3

  //below can be changed, but should be PORTC pins
  #define RIGHT_ENC_PIN_A PC4  //pin A4
  #define RIGHT_ENC_PIN_B PC5   //pin A5
#elif defined ARDUINO_MY_COUNTER
  #include<PID_v1.h> //调用PID包
  #define LEFT_A 21
  #define LEFT_B 20
  #define RIGHT_A 18
  #define RIGHT_B 19
  void initEncoders();
  void leftEncoderEventA();
  void leftEncoderEventB();
  void rightEncoderEventA();
  void rightEncoderEventB();
  void update_vel();
  double get_current_vel(volatile long count);
  double kp=1.5, ki=3.0, kd=0.1;
  double vela,velb,vel,target_a,target_b;
  double pwma,pwmb;
  PID pid_a(&vela,&pwma,&target_a,kp,ki,kd,DIRECT),pid_b(&velb,&pwmb,&target_b,kp,ki,kd,DIRECT);
#endif

long readEncoder(int i);
void resetEncoder(int i);
void resetEncoders();