/*
 * File:  GPIO.h
 * Author: Jamie Starling - JamieStarling.com 
 *
 * Created on:  July 28, 2019, 3:25 PM
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

#ifndef GPIO_H
#define	GPIO_H


int8_t pinDirection(int8_t pin, int8_t direction);
int8_t digitalWrite (int8_t pin, int8_t value);
uint8_t digitalRead (int8_t pin);
uint8_t enableWPUA (int8_t pin);

#endif	/* GPIO_H */

