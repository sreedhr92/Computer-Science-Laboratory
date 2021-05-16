var fs = require("fs");
fs.open('input.txt', 'r+', function(err, fd) {
    if(err) console.log(err);
    console.log("\nOriginal File Content\n\n");
    fs.readFile(fd, function(err,data){
        if(err) console.log(err);
        console.log(data.toString());
        fs.ftruncate(fd,50,function(err){
            if(err) console.log(err);
            fs.readFile('input.txt',function(err,new_data){
                if(err) console.log(err);
                console.log("\n\n\nTruncating the file:\n\n\n"+new_data.toString());
                console.log("\n\n\n");
            })
            fs.close(fd,function(err)
            {
                if(err) console.log(err);
            });
        });
    });
});