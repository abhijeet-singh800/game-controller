// Initial Definitions and Setup
// Libary Inclusion
#include <Joystick.h>

// Define and Allocate Input Pins to memorable names
#define left_joyx A3
#define left_joyy A2
#define right_joyx A1
#define right_joyy A0
#define dpad_up 10
#define dpad_down 9
#define dpad_right 8
#define dpad_left 14
#define button_a 2
#define button_b 4
#define button_x 6
#define button_y 5
#define left_trig 15
#define left_bump 16
#define right_trig 7
#define right_bump 3

// Initializing Axis as Integers, at a 0 default value
int leftjoy_xAxis_ = 0;
int leftjoy_yAxis_ = 0;
int rightjoy_xAxis_ = 0;
int rightjoy_yAxis_ = 0;

// Setting up Buttons
// Updating a static variable gives greater stability than reading directly from the digital pin.
// Giving Default Values to the Buttons for later use
int last_dpad_up_State = 0;
int last_dpad_down_State = 0;
int last_dpad_left_State = 0;
int last_dpad_right_State = 0;
int last_button_a_State = 0;
int last_button_b_State = 0;
int last_button_x_State = 0;
int last_button_y_State = 0;
int last_left_trig_State = 0;
int last_left_bump_State = 0;
int last_right_trig_State = 0;
int last_right_bump_State = 0;

// Joystick Initilization command

Joystick_ Joystick(0x5, JOYSTICK_TYPE_GAMEPAD, 16, 0, true, true, false, true, true, false, false, false, false, false, false);
// Joystick_ Joystick;

// Set Auto Send State
// Enables Auto Sending, allowing the controller to send information to the HID system, rather than waiting to be asked.
const bool initAutoSendState = true;

void setup()
{
  // Initialize Buttons
  // Buttons set up between Digital Pin and Ground, following pin allocations from earlier on
  pinMode(left_joyx, INPUT_PULLUP);
  pinMode(left_joyy, INPUT_PULLUP);
  pinMode(right_joyx, INPUT_PULLUP);
  pinMode(right_joyy, INPUT_PULLUP);
  pinMode(dpad_up, INPUT_PULLUP);
  pinMode(dpad_down, INPUT_PULLUP);
  pinMode(dpad_right, INPUT_PULLUP);
  pinMode(dpad_left, INPUT_PULLUP);
  pinMode(button_a, INPUT_PULLUP);
  pinMode(button_b, INPUT_PULLUP);
  pinMode(button_x, INPUT_PULLUP);
  pinMode(button_y, INPUT_PULLUP);
  pinMode(left_trig, INPUT_PULLUP);
  pinMode(left_bump, INPUT_PULLUP);
  pinMode(right_trig, INPUT_PULLUP);
  pinMode(right_bump, INPUT_PULLUP);
  Joystick.setXAxisRange(0, 255);
  Joystick.setYAxisRange(0, 255);
  Joystick.setRxAxisRange(0, 255);
  Joystick.setRyAxisRange(0, 255);

  // Start Joystick - Needed to start the Joystick function libary
  Joystick.begin();
}

void loop()
{
  // Runtime Axis Reading

  // Reading for X Axis of Left Joystick
  Joystick.setXAxis(-((analogRead(left_joyx) >> 2) - 255.00));

  // //Reading for Y Axis of Left Joystick
  Joystick.setYAxis(analogRead(left_joyy) >> 2);

  // Reading for X Axis of Right Joystick
  Joystick.setRxAxis(-((analogRead(right_joyx) >> 2) - 255.00));

  // Reading for Y Axis of Right Joystick
  Joystick.setRyAxis(analogRead(right_joyy) >> 2);

  // Runtime Button Reading

  // Reading for Dpad Up
  int current_dpad_up_State = !digitalRead(dpad_up);
  if (current_dpad_up_State != last_dpad_up_State)
  {
    Joystick.setButton(12, current_dpad_up_State);
    last_dpad_up_State = current_dpad_up_State;
  }
  // Reading for Dpad Down
  int current_dpad_down_State = !digitalRead(dpad_down);
  if (current_dpad_down_State != last_dpad_down_State)
  {
    Joystick.setButton(13, current_dpad_down_State);
    last_dpad_down_State = current_dpad_down_State;
  }
  // Reading for Dpad Right
  int current_dpad_right_State = !digitalRead(dpad_right);
  if (current_dpad_right_State != last_dpad_right_State)
  {
    Joystick.setButton(15, current_dpad_right_State);
    last_dpad_right_State = current_dpad_right_State;
  }
  // Reading for Dpad Left
  int current_dpad_left_State = !digitalRead(dpad_left);
  if (current_dpad_left_State != last_dpad_left_State)
  {
    Joystick.setButton(14, current_dpad_left_State);
    last_dpad_left_State = current_dpad_left_State;
  }
  // Reading for Button A
  int current_button_a_State = !digitalRead(2);
  if (current_button_a_State != last_button_a_State)
  {
    Joystick.setButton(0, current_button_a_State);
    last_button_a_State = current_button_a_State;
  }
  // Reading for Button B
  int current_button_b_State = !digitalRead(button_b);
  if (current_button_b_State != last_button_b_State)
  {
    Joystick.setButton(1, current_button_b_State);
    last_button_b_State = current_button_b_State;
  }
  // Reading for Button X
  int current_button_x_State = !digitalRead(button_x);
  if (current_button_x_State != last_button_x_State)
  {
    Joystick.setButton(2, current_button_x_State);
    last_button_x_State = current_button_x_State;
  }
  // Reading for Button Y
  int current_button_y_State = !digitalRead(button_y);
  if (current_button_y_State != last_button_y_State)
  {
    Joystick.setButton(3, current_button_y_State);
    last_button_y_State = current_button_y_State;
  }
  // Reading for Button Left Trigger
  int current_left_trig_State = !digitalRead(left_trig);
  if (current_left_trig_State != last_left_trig_State)
  {
    Joystick.setButton(6, current_left_trig_State);
    last_left_trig_State = current_left_trig_State;
  }
  // Reading for Button Left Bumper
  int current_left_bump_State = !digitalRead(left_bump);
  if (current_left_bump_State != last_left_bump_State)
  {
    Joystick.setButton(4, current_left_bump_State);
    last_left_bump_State = current_left_bump_State;
  }
  // Reading for Button Right Trigger
  int current_right_trig_State = !digitalRead(right_trig);
  if (current_right_trig_State != last_right_trig_State)
  {
    Joystick.setButton(7, current_right_trig_State);
    last_right_trig_State = current_right_trig_State;
  }
  // Reading for Button Right Bumper
  int current_right_bump_State = !digitalRead(right_bump);
  if (current_right_bump_State != last_right_bump_State)
  {
    Joystick.setButton(5, current_right_bump_State);
    last_right_bump_State = current_right_bump_State;
  }

  // Pole Delay
  // Debounce
  delay(10);
}
