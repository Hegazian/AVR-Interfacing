/*
 * SPI.h
 *
 * Created: 2/28/2022 12:43:27 PM
 *  Author: aaa
 */ 


#ifndef SPI_H_
#define SPI_H_

#define SLAVE	0
#define MASTER	1

#define MISO	25
#define MOSI	26
#define SS		24
#define SCK		27

void SPI_INIT(void);

u8 SPI_TRANSIVE(u8);



#endif /* SPI_H_ */