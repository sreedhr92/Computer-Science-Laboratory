var MongoClient = require('mongodb').MongoClient;
var url = "mongodb://localhost:27017/Patient_Details";

MongoClient.connect(url, {useUnifiedTopology: true }, function(err, db) {
  if (err) throw err;
  console.log("Database Connected");
  var dbObject = db.db("Patient_Details");
  var myobj = { 
                Name:'Sree',
                age:20,
                ID:1,
                gender:'Male',
                address:'Erode',
                marital_status:'single',
                DateOfVisit:Date() 
            };
    dbObject.collection("patients").insertOne(myobj, function(err, res) {
        if (err) throw err;
        console.log("inserted");
        dbObject.collection('patients').find().toArray(function(err,res){
            if(err) throw err;
            console.log(res);
            dbObject.collection('patients').deleteOne({Name:'Raj Kumar'},function(err,res){
                if(err) throw err
                console.log('Deleted!');
                dbObject.collection('patients').find().toArray(function(err,res){
                    if(err) throw err;
                    console.log(res);
                    var upd_url = { Name:"Amith Kumar" };
                    var upd_values = { $set: {Name: "Vikraman", address: "Dubai" } };
                    dbObject.collection("patients").updateOne(upd_url, upd_values, function(err, res) {
                        if (err) throw err;
                        console.log("updated|");
                        dbObject.collection('patients').find().toArray(function(err,res){
                            if(err) throw err;
                            console.log(res);
                            db.close();
                        });
                    });
                });
            });
        });   
    });
});