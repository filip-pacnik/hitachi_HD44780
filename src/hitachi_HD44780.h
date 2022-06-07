#ifndef HITACHI_HD44780_H
#define HITACHI_HD44780_H




#include <Arduino.h>




#define IR 0x00
#define DR 0x01

#define W 0x00
#define R 0x01




#define AND 0x01




#define X8 8




class driver
{
    public :
        void post ( uint8_t , uint8_t , uint8_t , uint8_t [] ) ;

        void cmd ( uint8_t , uint8_t , uint8_t ) ;





    private :
        uint8_t _rs ; 
        uint8_t _rw ;
        uint8_t _e ; 


        uint8_t _db [ X8 ] ;




        void assign ( uint8_t , uint8_t , uint8_t , uint8_t [] ) ;

        void enable () ;

        void bitwise ( uint8_t , uint8_t , uint8_t ) ; 
} ;



#endif