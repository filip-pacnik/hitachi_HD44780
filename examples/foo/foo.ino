#include <conf.h>

#include <hitachi_HD44780.h>




io io ;

driver driver ;
 



uint8_t p [ 11 ] = { 22 , 23 , 24 , 25 , 26 , 27 , 28 , 29 , 30 , 31 , 32 } ;


uint8_t * rs = & p [ 0 ] ;
uint8_t * rw = & p [ 1 ] ;
uint8_t * e = & p [ 2 ] ;

uint8_t db [ 8 ] = { 25 , 26 , 27 , 28 , 29 , 30 , 31 , 32 } ;


int dly = 500 ;




void setup ()
{
  //io.outp ( p ) ;
  pinMode( 22, OUTPUT ) ;
  pinMode( 23, OUTPUT ) ;
  pinMode( 24, OUTPUT ) ;
  pinMode( 25, OUTPUT ) ;
  pinMode( 26, OUTPUT ) ;
  pinMode( 27, OUTPUT ) ;
  pinMode( 28, OUTPUT ) ;
  pinMode( 29, OUTPUT ) ;
  pinMode( 30, OUTPUT ) ;
  pinMode( 31, OUTPUT ) ;
  pinMode( 32, OUTPUT ) ;

  driver.post( 22 , 23 , 24 , db ) ;

  delay ( dly ) ;
  driver.cmd ( IR , W , 0x30 ) ;

  delay ( dly ) ;
  driver.cmd ( IR , W , 0x0E ) ;

  delay ( dly ) ;
  driver.cmd ( IR , W , 0x06 ) ;
}


void loop ()
{
  delay ( dly ) ;
  driver.cmd ( DR , W , B01001000 ) ;

  delay ( dly ) ;
  driver.cmd ( DR , W , B01100101 ) ;

  delay ( dly ) ;
  driver.cmd ( DR , W , B01101100 ) ;

  delay ( dly ) ;
  driver.cmd ( DR , W , B01101100 ) ;

  delay ( dly ) ;
  driver.cmd ( DR , W , B01101111 ) ;

  delay ( dly ) ;
  driver.cmd ( DR , W , B00100000 ) ;

  delay ( dly ) ;
  driver.cmd ( DR , W , B01010111 ) ;

  delay ( dly ) ;
  driver.cmd ( DR , W , B01101111 ) ;

  delay ( dly ) ;
  driver.cmd ( DR , W , B01110010 ) ;

  delay ( dly ) ;
  driver.cmd ( DR , W , B01101100 ) ;

  delay ( dly ) ;
  driver.cmd ( DR , W , B01100100 ) ;

  delay ( dly * 5 ) ;
  driver.cmd ( IR , W , B00000001 ) ;
  delay ( dly * 5) ;
}