module rand;
{this is a random numbmer generator that uses the xrand machine code procedure
 to produce a random number function that is closer to something a more modern
 pascal compiler would have it is (C) 2020 - david collins, use at your own 
 risk.  also if you use this on a altair, i want to know about it LOL }

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
 
