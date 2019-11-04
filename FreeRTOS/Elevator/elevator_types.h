/*
 * elevator_types.h
 *
 *  Created on: 4 nov. 2019
 *      Author: A551226
 */

#ifndef ELEVATOR_TYPES_H_
#define ELEVATOR_TYPES_H_

typedef enum {
  downward = 0,
  upward
} CabinMotorDirection;

typedef enum {
  notRunning = 0,
  running
} MotorState;

typedef struct CABINMOTORCONTROL {
  CabinMotorDirection motorDirection;
  MotorState motorState;
  BaseType_t speed; // rotations/seconds
} CabinMotorControl_t;

typedef enum {
  off = 0,
  on
} ButtonState;

typedef enum {
  atGroundFloor = 0,
  atFirstFloor,
  atSecondFloor
} CabinLocation;

typedef struct BUTTON {
  ButtonState buttonState;
};

typedef struct CABINBUTTONCONTROL {
  BUTTON groundFloor;
  BUTTON firstFloor;
  BUTTON secondFloor;
} CabinButtonControl_t;

typedef struct LOBBYBUTTONCONTROL {
  BUTTON upward;
  BUTTON downward;
} LobbyButtonControl_t;

typedef enum {
  close = 0,
  open
} DoorState;

typedef struct LOBBYDOORMOTORCONTROL {
  DoorState doorState;
  MotorState motorState;
} LobbyDoorMotorControl_t;

#endif /* ELEVATOR_TYPES_H_ */
