

#ifndef __QUAD_H__
#define __QUAD_H__

#include "servo.h"
extern const uint16_t pwm_values[180];

/****************************
 *     \             /
 *    3 \ A      C  / 9
 *     2 \         / 8
 *      1 |-------| 7
 *        |       |
 *        |       |
 *      4 |-------| 10
 *     5 /         \ 11
 *    6 / B      D  \ 12
 *     /             \
 ****************************/

// quad legs
#define setLegA(pivot, lift, knee)					\
		servo_pwm[1-1] = pwm_values[179-(pivot)];	\
		servo_pwm[2-1] = pwm_values[(lift)];		\
		servo_pwm[3-1] = pwm_values[179-(knee)]

#define setLegB(pivot, lift, knee)					\
		servo_pwm[4-1] = pwm_values[179-(pivot)];	\
		servo_pwm[5-1] = pwm_values[179-(lift)];	\
		servo_pwm[6-1] = pwm_values[(knee)]

#define setLegC(pivot, lift, knee)					\
		servo_pwm[7-1] = pwm_values[179-(pivot)];	\
		servo_pwm[8-1] = pwm_values[179-(lift)];	\
		servo_pwm[9-1] = pwm_values[(knee)]

#define setLegD(pivot, lift, knee)					\
		servo_pwm[10-1] = pwm_values[179-(pivot)];	\
		servo_pwm[11-1] = pwm_values[(lift)];		\
		servo_pwm[12-1] = pwm_values[179-(knee)]


/* leg assembly compensation */
// pivot normals to CoG
#define AN	95
#define BN	95
#define CN	90
#define DN	105

// lift horizontal
#define AH	85
#define BH	90
#define CH	90
#define DH	90

// knee straight
#define AS	120
#define BS	110
#define CS	120
#define DS	130

/* steps table */
#define POSITION_TOTAL	64
extern const int8_t pivots[POSITION_TOTAL];
extern const int8_t lifts[POSITION_TOTAL];
extern const int8_t knees[POSITION_TOTAL];

void quad_init(void);

#endif /* __QUAD_H__ */
