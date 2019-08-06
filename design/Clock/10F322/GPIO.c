/*
 * File:  GPIO.c
 * Author: Jamie Starling - JamieStarling.com 
 *
 * Created on:  June 6, 2019, 10:01 PM
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

/* PURPOSE:
Use pinDirection to setup pin as input or outp
Example : pinDirection(0,1) - sets Pin A.0 as input
Example : pinDirection(0,0) - sets Pin A.0 as output

digitalWrite - writes the desired state to the PIN
Example: digitalWrite (1,1) - sets PIN A.1 High
Example: digitalWrite (2,0) - sets PIN A.2 Low

*/


#include <xc.h>
#include <stdint.h>
#include "GPIO.h"





int8_t digitalWrite (int8_t pin, int8_t value)
/*
 * Turns off or on a specific pin.  
 * Usage digitalWrite( pin to control , 1 for on / 0 for off)
 * Returns 0 if success, 1 if failure.   
 * Valid pins for 10F32x are 0 - 2 - pin 3 is always input only.
 *  
 */
{ 
    switch (pin)  
    {
        case 0 : //Port RA.0
            if (value)  //Turn on if value is 1
            {
                LATAbits.LATA0 = 1;
            }
            else       //Other wise turn off
            {
                LATAbits.LATA0 = 0;
            }
            return 0;
            
        case 1 : //Port RA.1
            if (value)  //Turn on if value is 1
            {
                LATAbits.LATA1 = 1;
            }
            else       //Other wise turn off
            {
                LATAbits.LATA1 = 0;
            }
            return 0;  
            
         case 2 : //Port RA.2
            if (value)  //Turn on if value is 1
            {
                LATAbits.LATA2 = 1;
            }
            else       //Other wise turn off
            {
                LATAbits.LATA2 = 0;
            }
            return 0;
            
            default : //Value out of range - return 1 includes pin 3 since it is input only
            return 1;            
            
    }
    
}

int8_t pinDirection(int8_t pin, int8_t direction)
/*
 * Sets a pin direction input or output
 * Usage pinDirection (Pin Value , 1 for input or 0 for output)
 * Valid pins for the 10F32X is 0 - 2 - pin 3 is always input
 * The routine also clears the Analog bit for the port
 * Returns 0 if success 1 if failure.  
 */
{
    switch (pin)
    {
        case 0 : //Port RA.0
           ANSELAbits.ANSA0 = 0; //Disable Analog
           if (direction)  //Set Pin as Input
           {
               TRISAbits.TRISA0 = 1;                       
           }
           else
           {
               TRISAbits.TRISA0 = 0;
           }
           return 0;
        
        case 1 : //Port RA.1
           ANSELAbits.ANSA1 = 0; //Disable Analog
           if (direction)  //Set Pin as Input
           {
               TRISAbits.TRISA1 = 1;                       
           }
           else
           {
               TRISAbits.TRISA1 = 0;
           }
           return 0;
           
        case 2 : //Port RA.2
           ANSELAbits.ANSA2 = 0; //Disable Analog
           if (direction)  //Set Pin as Input
           {
               TRISAbits.TRISA2 = 1;                       
           }
           else
           {
               TRISAbits.TRISA2 = 0;
           }  
           return 0;
           
        case 3 : //Port RA.3 - Input only we do nothing
            return 0;
            
        default : //Value out of range - return 1
        return 1;
           
    }
}


uint8_t digitalRead (int8_t pin)
/*
 * Reads the current input value of a pin - returns value 
 * Returns value 0Xff if out of range
 */
{
        
    switch (pin)
    {
        case 0 : //Port RA.0
             return (PORTAbits.RA0);
        
        case 1: //Port RA.1
            return (PORTAbits.RA1);
            
        case 2: //Port RA.2
            return (PORTAbits.RA2);
            
        case 3 : //Port RA.3
            return (PORTAbits.RA3);
            
        default : //Value out of range - return 255
        return 0xFF;
        
    }        
}

uint8_t enableWPUA (int8_t pin)
/*Enables Weak Pull ups on port pin - input pin number*/
{
	OPTION_REGbits.nWPUEN = 0; //Enable WeakPull up in option register
	
	switch (pin)
	{
		case 0 : //Port RA.0
             WPUAbits.WPUA0 = 1;
             return 0;
        
        case 1: //Port RA.1
            WPUAbits.WPUA1 = 1;
            return 0;
            
        case 2: //Port RA.2
            WPUAbits.WPUA2 = 1;            
            return 0;
            
        case 3 : //Port RA.3
            WPUAbits.WPUA3 = 1;
            return 0;
            
        default : //Value out of range - return 255
        return 0xFF;	
	}	
}	
	