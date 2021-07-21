# 8080_8086_XorShift For Pascal/MT+ Family of 8 and 16 bit compilers
a pre-compiled library for Pascal/MT+ with pure 8080 or 8088/6 asembler for use on CPM-80 and CPM-86

This code will produce with very little overhead and without the use of Floating point a Psudorandom number
based off a seed of your choice. This is done useing the venerable XOR and Shift algorithm discovered by 
George Marsaglia.  You can read his paper here: http://www.jstatsoft.org/v08/i14/paper 

Both of the versions were found to work on the V20-MBC2 in both 8080 and 8086 mode. There is nothing platform
specific about any of the source and it should work well where the compiler can run and compile code (including 
but not limited to dos), while the system architecture is the same.

you can read about Fabios exellent V20-MBC Single board computer here:

https://hackaday.io/project/170924-v20-mbc-a-v20-8088-8080-cpu-homebrew-computer

you can set the seed using various methods such as the system timer by calling the randomize procedure: 

    randomize([RANDOM SEED]);
   
   note the seed must not be zero, you can asure this with a timer by simply adding 1.
   
   and then retreve a random number by calling the function: 
    
    [some integer] := random([max number]);   
    
   this will return a random number from zero to (max number - 1).  
   
Its important to note both the function and procedure use 16 bit 2's compliment integers, however the asember is 
uses a 16 bit word.  This may slightly effect the distribution of the numbering (to a small or lage degree).  
in other words - this isn't sutable for research or cryptography; but most likely perfectly fine if you just need
to seed a few random numbers for a game or whatnot.
   


UPDATE *** ADDED 8088/86 supprt for 16 bit Pascal/MT+ ***

thanks to Brad Forschingers helpfull blog post and example source: 

http://b2d-f9r.blogspot.com/2010/08/16-bit-xorshift-rng.html




NOTE: the asembler code automatically handles the entry points within the context of pascal/mt+ if you wish to use this with
another compiled language that uses microsofts relocateable file format you will need to consult that compilers manual and update 
the code for working with your specific compiler.
