module rand;
{this is a random numbmer generator that uses the xrand machine code procedure
 to produce a random number function that is closer to something a more modern
 pascal compiler would have it is (C) 2021 - david collins, use at your own 
 risk.  also if you use this on a altair, i want to know about it LOL
 the code here is the same for 8088/6 as well as 8080 the companion mechine
 code module is required for your specific platform. to use include rand.def 
 after your declaration block 
 
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

var
  masterseed : integer;

external function xrand(seed:integer) : integer; 
   { you will need xrnd.r86 linked for this to work }
 
{ sets the seed for random number xorshift needs a non zero value }
procedure randomize(seed :integer);

begin
 masterseed := seed;
end;

{ generates a random number of 0 thrugh (range - 1) }

function random(range : integer) : integer;
begin
 if masterseed = 0 then masterseed := 1;
 masterseed := xrand(masterseed); {this steps ahead the algoithm 1 step }
 random := abs(masterseed) mod range;
end;

modend.   
 
