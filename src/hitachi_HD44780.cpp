#include <hitachi_HD44780.h>




#include <kywrd.h>




void driver :: post ( uint8_t rs , uint8_t rw , uint8_t e , uint8_t db [] )
{
    assign ( rs , rw , e , db ) ;
}




void driver :: cmd ( uint8_t rs , uint8_t rw , uint8_t d )
{
    bitwise ( rs , rw , d ) ;
}




void driver :: assign ( uint8_t rs , uint8_t rw , uint8_t e , uint8_t db [] )
{
   _rs = rs ;
   _rw = rw ;
   _e = e ;


   for ( uint8_t i = Z ; i < X8 ; i ++ )
       _db [ i ] = db [ i ] ;
}




void driver :: enable ()
{
    DW ( _e , L ) ;
    DM ( ST ) ;
    DW ( _e , H ) ;
    DM ( ST ) ;
    DW ( _e , L ) ;
    DM ( 100 ) ;
}




void driver :: bitwise ( uint8_t rs , uint8_t rw , uint8_t d )
{
    DW ( _rs , rs );
    DW ( _rw , rw ) ;


    for ( uint8_t i = Z ; i < X8 ; i ++ )
        DW ( _db [ i ] , ( d >> i ) & AND ) ;




    enable () ;
}