var fs=require('fs');
const readline = require("readline");
const r1 = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});
r1.question("What is your Name ? ", function(name) {
    fs.readFile('./greet.txt', function(err,data){
        if(err) return console.log("File not Found");
        data+='';
        var x=data.split(/\r?\n/)
        var greet = x[Math.floor(Math.random()*x.length)]
        console.log(greet,name);
        r1.close();
    });
});