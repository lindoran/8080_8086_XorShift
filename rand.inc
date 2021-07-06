module rand;
{this is a random numbmer generator that uses the xrand machine code procedure
 to produce a random number function that is closer to something a more modern
 pascal compiler would have
 
MIT License

Copyright (c) 2021 Dave Collins

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.}

type 
 intptr = ^integer;

external procedure xrand; { you will need xrnd.erl linked for this to work }
 
{ sets the seed for random number xorshift needs a non zero value }
procedure randomize(seed :integer);
var 
 seedptr : intptr;

begin
 seedptr := addr(xrand)+2;
 seedptr^ := seed;
end;

{ generates a random number of 0 thrugh (range - 1) }

function random(range : integer) : integer;
var
 valueptr : intptr;

begin
 valueptr := addr(xrand)+2;
 xrand; {this steps ahead the algoithm 1 step }
 random := abs(valueptr^) mod range;
end;

modend.   
 
