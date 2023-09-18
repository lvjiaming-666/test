/*
 * lin.h
 *
 *  Created on: 2022Äê6ÔÂ25ÈÕ
 *      Author: Administrator
 */

#ifndef LINMASTER_H_
#define LINMASTER_H_

#define FRAME_MASTER_SEND_DATA      (1U)
#define FRAME_MASTER_RECEIVE_DATA     (2U)
#define FRAME_GO_TO_SLEEP             (3U)

void LinMaster_Init(void);
void LinMaster_Enable(void);
void LinMaster_Disable(void);
void LinMaster_Test (void);

#endif /* LINMASTER_H_ */
