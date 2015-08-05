#!/usr/bin/env node

var fs = require('fs');
var outfile = "primes.txt";
var i = 2;
var primes = [];
//console.log(primes.length);
//console.log(primes[0]+","+primes[1]);
while(primes.length < 100)
{
    isPrime = true;
    for(var j = 2; j < Math.floor(Math.sqrt(i)) + 1; j++)
    {
        if(i%j == 0)
        {
            isPrime = false;
            break;
        }
    }
    if(isPrime)
        primes.push(i);
    i++;
}
//console.log(primes.length);
var out = "";
out += primes[0];
for(var j = 1; j < primes.length; j++)
{
    out += "," + primes[j];
}
out += "\n";
fs.writeFileSync(outfile, out);