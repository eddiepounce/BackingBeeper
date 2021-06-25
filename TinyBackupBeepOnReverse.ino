/*
An ATtiny85 implementation of a Backup Beeper when reverse is detected.
(just 1 input and 1 output pin used)

Copyright (C) 2021  Eddie Pounce

    Copyright

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

	84339861+eddiepounce@users.noreply.github.com

*/


unsigned long duration;

void setup() {
    // put your setup code here, to run once:
    pinMode(0, INPUT);  
    pinMode(1, OUTPUT);
    digitalWrite(1, LOW);
}

void loop() {
    // put your main code here, to run repeatedly:
    duration = pulseIn(0, HIGH, 100000);
    if (duration < 1400 && duration > 800) {
        digitalWrite(1, HIGH);
        delay(650);             
        digitalWrite(1, LOW);
        delay(400);  
    } else {
        digitalWrite(1, LOW);
    }
}
