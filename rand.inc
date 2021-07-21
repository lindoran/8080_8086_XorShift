module rand;
{this is a random numbmer generator that uses the xrand machine code procedure
 to produce a random number function that is closer to something a more modern
 pascal compiler would have it is (C) 2021 - david collins, use at your own 
 risk.  also if you use this on a altair, i want to know about it LOL
 the code here is the same for 8088/6 as well as 8080 the companion mechine
 code module is required for your specific platform. to use include rand.def 
 after your declaration block }

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
 
