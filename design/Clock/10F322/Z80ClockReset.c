/*
 * File:  Z80ClockReset.c
 * Author: Jamie Starling - JamieStarling.com 
 *
 * Created on:  July 29, 2019, 3:08 PM
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
#include "deviceconfig.h"
#include "GPIO.h"
#include "OSC.h"





void main(void)
{
    cpuFreqSelect(500); //Set CPU Freq to 500Khz
    clockReferenceOut(1); //Set Clock Reference Out
    
    pinDirection(0,0); //Set PORTA.0 Output
    digitalWrite(0,0); //Set PORTA.0 Low
    
    enableWPUA(3); //Enable Weakpull Ups PORTA.3
    
    __delay_ms(50);  //If you change the CPU Frequency Update _XTAL_FREQ in device.h
     
    digitalWrite(0,1); //Set PORTA.0 High - Bring Z80 out of reset.
    
    
    
  while(1)  
  {
      if (!digitalRead(3))  //Read the reset Button - if low
      {
          __delay_ms(50);  //Wait 50ms..
          
          if (!digitalRead(3)) //Check it again.. if still slow reset Z80
          {
              while (!digitalRead(3)); //Wait here until button is released
              digitalWrite(0,0); //Set PORTA.0 Low - Z80 Reset
              __delay_ms(100);  //Wait 100ms
              digitalWrite(0,1); //Set PORTA.0 High - Bring Z80 out of reset.
          }        
      }      
  }
    
}
