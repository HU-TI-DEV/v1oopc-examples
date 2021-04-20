#include "hwlib.hpp"

void pin_pulse( 
   hwlib::pin_out & pin, 
   uint16_t on, 
   uint16_t total 
){
   pin.write( 1 );
   pin.flush();
   hwlib::wait_us( on );
   pin.write( 0 );
   pin.flush();   
   hwlib::wait_us( total - on );
}

int main( void ){	
    
   namespace target = hwlib::target;
   target::board board; 
   auto switches = hwlib::port_in_from( board.sw6, board.sw5 );
   auto buttons = hwlib::port_in_from( board.sw1, board.sw2, board.sw3, board.sw4 );
   auto colors = hwlib::port_out_from( board.red, board.green, board.blue );
   auto last_time = hwlib::now_us();
   
   auto leds = hwlib::port_out_from(
      board.led1, board.led2, board.led3, board.led4, 
      board.led5, board.led6, board.led7, board.led8, board.led9 ); 
   
   int_fast8_t old_mode = -1;
   int_fast8_t color = 0;
   int_fast16_t led = 0;
   uint_fast8_t old_buttons = 0;

   hwlib::cout << "MFD demo/test application\n";
          
   for(;;){    
    
      switches.refresh();
      int mode = switches.read();
      
      buttons.refresh();
      auto b = buttons.read();      
   
      auto time = hwlib::now_us();
            
      if( mode != old_mode ){
         hwlib::cout << "mode= " << mode << "\n";
         color = 0;
         old_mode = mode;
         led = 0b1'1111'1111;
      }
      
      switch( mode ){
          
         // automatically cycle through the 3 colors
         case 0: {
            if( time > last_time + 500'000 ){
               color = ( color == 0 ) 
                  ? 0b0100 
                  : color >> 1;
               last_time = time;
            }
            break;
         }
          
         // select a color using the buttons
         case 1: {
            if( b == 0b01 ) {
                color = 0;
            } else {
               color |= ( b >> 1 );
            }
            break;
         }
          
         // beep depending on the button
         case 2: {
            if( b != old_buttons ){
               switch( b ) {
                  case 0b0001 : {
                     hwlib::blink( board.buzzer, 4, 200 );                      
                     break;
                  }
                  case 0b0010 : {
                     hwlib::blink( board.buzzer, 3, 200 );                      
                     break;
                  }
                  case 0b0100 : {
                     hwlib::blink( board.buzzer, 2, 200 );                      
                     break;
                  }
                  case 0b1000 : {
                     hwlib::blink( board.buzzer, 1, 200 );                      
                     break;
                  }
               }   
            }
            break;
         }
          
         case 3: {
            if( b > old_buttons ){ 
               led = ( led == 0 )
                  ? 0b1'1111'1111
                  : led >> 1;   
            }         
            pin_pulse( 
               board.green,
               board.adc.read(),
               board.adc.adc_max_value
             );             
             break;
         }
      }   
      
      leds.write( led );
      leds.flush();
      
      colors.write( color );
      colors.flush();
          
      old_buttons = b;
   }
}
