/*
 * File:  OSC.c
 * Author: Jamie Starling - JamieStarling.com 
 *
 * Created on:  June 5, 2019, 10:52 AM
 * 
 * Copyright 2018 - 2019 Jamie Starling

Free for Personal Use.  
Restricted Commercial Use  : Please Contact Jamie at jamie@jamiestarling.com for Terms.

THE SOFTWARE IS PROVIDED ?AS IS?, WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED,INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.

 */

#include <xc.h>
#include <stdint.h>




uint8_t cpuFreqSelect(uint16_t speed) {
/* Sets the processor Frequence 
 * Speed is the clock speed input value
 *
 *16  111 = 16 MHz
 *8   110 = 8 MHz (default power on value)
 *4   101 = 4 MHz
 *2   100 = 2 MHz
 *1   011 = 1 MHz
 *500 010 = 500 kHz
 *250 001 = 250 kHz
 *32  000 = 31 kHz (LFINTOSC) 
 * 
 * Returns 0 if success - 1 if value is out of range.
 */   
   
switch (speed)
{
    
    case 31 :  //31Khz
        OSCCONbits.IRCF = 0b000;
        return 0;
        
     case 250 :  //250Khz
        OSCCONbits.IRCF = 0b001;
        return 0;    
         
        
     case 500 :  //500Khz
        OSCCONbits.IRCF = 0b010;       
        return 0;    
        
    case 1 :  //1Mhz
        OSCCONbits.IRCF = 0b011;
        return 0;    
        
    case 2 :  //2Mhz
        OSCCONbits.IRCF = 0b100;
        return 0;        
        
    case 4 :  //4Mhz
        OSCCONbits.IRCF = 0b101;
        return 0;   
        
    case 8 :  //8Mhz - Default
        OSCCONbits.IRCF = 0b110;
        return 0;   
        
    case 16 :  //16Mhz
        OSCCONbits.IRCF = 0b111;
        return 0;

    default : //Return error
        return 1;
        
}

}

void clockReferenceOut ( int8_t ClockOut)
/* Enables or Disables the Reference Clock out on PIN CLKR (PIN A.2)
 * 1 enable 
 * 0 (anything else) disable 
 */
{  
    if (ClockOut == 1)
    {
        CLKRCONbits.CLKROE = 1; 
    }
    else
    {
        CLKRCONbits.CLKROE = 0; 
    }
    
}
