// To run this:
//  cd workspace
//  node main.js

// To restart:
//  Ctrl-c
//  node main.js
//
// To start MongoDB:
//   parts start mongodb
//

var express = require('express');
var app = express();

var databaseUrl = "mydb"; // "username:password@example.com/mydb"
var collections = ["buildings"]
var db = require("mongojs").connect(databaseUrl, collections);

var Mustache = require('mustache')

/*
db.buildings.save({
  "number" : 10,
  "name" : "Cornett",
  "description" : "Those silly mechanical jerks",
  "contacts" : [
    {
      "name" : "Bob the Builder",
      "phone" : "123-456-7890",
      "email" : "ihateurguts@evilcat.net"
    },
    {
      "name" : "Mad Cat",
      "phone" : "456-789-1234",
      "email" : "ilovedogs@ymail.com"
    }
  ]
}, function(err, saved) {
  if( err || !saved ) console.log("User not saved");
  else console.log("User saved");
});
*/
  
app.use('/', express.static(__dirname + '/static'));

// You could generalize this URL.
// Example: /?building=Cornett

app.get('/purvine', function(req, res) {
  db.buildings.find({name: "Purvine Hall"}, function(err, buildings) {
    if(err || !buildings) console.log("No building found");
    else {
      var building = buildings[0];
      console.log(building);
      building.thumb = 'http://oitweb1.oit.edu/Libraries/Campus_Map/Purvine.sflb.ashx';
      //res.write(JSON.stringify(building));
      var html = Mustache.render("<html><body><h2><div class='building'>{{name}}</h2><p>{{description}}</div></body></html>" + "{{#contacts}}<p>contact: {{name}} Phone:{{phone}}, Email: {{email}} </p> {{/contacts}}<img src='{{thumb}}'>", building);
      res.write(html);
      res.end();
    }
  });
});

app.get('/cornett', function(req, res) {
  db.buildings.find({name: "Cornett Hall"}, function(err, buildings) {
    if(err || !buildings) console.log("No building found");
    else {
      var building = buildings[0];
      console.log(building);
      building.thumb = 'http://oit.edu/images/default-source/campus-map/cornett/cornett.jpg';
      //res.write(JSON.stringify(building));
      var html = Mustache.render("<html><body><div class='building'> {{name}}<p>{{description}}</div></body></html>" + "{{#contacts}}<p>contacts: </p><p>{{name}} Phone:{{phone}}, Email: {{email}} </p> {{/contacts}}<img src='{{thumb}}'>", building);
      res.write(html);
      res.end();
    }
  });
});
app.get('/snell', function(req, res) {
  db.buildings.find({name: "Snell Hall"}, function(err, buildings) {
    if(err || !buildings) console.log("No building found");
    else {
      var building = buildings[0];
      console.log(building);
      building.thumb = 'http://oitweb1.oit.edu/Libraries/Campus_Map/Boivin.sflb.ashx';
      //res.write(JSON.stringify(building));
      var html = Mustache.render("<html><body><div class='building'> {{name}}<p>{{description}}</div></body></html>" + "{{#contacts}}<p>contacts: </p><p>{{name}} Phone:{{phone}}, Email: {{email}} </p> {{/contacts}}<img src='{{thumb}}'>", building);
      res.write(html);
      res.end();
    }
  });
});
app.get('/collegeunion', function(req, res) {
  db.buildings.find({name: "College Union"}, function(err, buildings) {
    if(err || !buildings) console.log("No building found");
    else {
      var building = buildings[0];
      console.log(building);
      building.thumb = 'http://oit.edu/images/default-source/campus-map/cu/cu.jpg?sfvrsn=2';
      //res.write(JSON.stringify(building));
      var html = Mustache.render("<html><body><div class='building'> {{name}}<p>{{description}}</div></body></html>" + "{{#contacts}}<p>contacts: </p><p>{{name}} Phone:{{phone}}, Email: {{email}} </p> {{/contacts}}<img src='{{thumb}}'>", building);
      res.write(html);
      res.end();
    }
  });
});
app.get('/residence', function(req, res) {
  db.buildings.find({name: "Residence Hall"}, function(err, buildings) {
    if(err || !buildings) console.log("No building found");
    else {
      var building = buildings[0];
      console.log(building);
      building.thumb = 'http://oitweb1.oit.edu/Libraries/Campus_Map/ResHall.sflb.ashx';
      //res.write(JSON.stringify(building));
      var html = Mustache.render("<html><body><div class='building'> {{name}}<p>{{description}}</div></body></html>" + "{{#contacts}}<p>contacts: </p><p>{{name}} Phone:{{phone}}, Email: {{email}} </p> {{/contacts}}<img src='{{thumb}}'>", building);
      res.write(html);
      res.end();
    }
  });
});
app.get('/athletics', function(req, res) {
  db.buildings.find({name: "Athletics"}, function(err, buildings) {
    if(err || !buildings) console.log("No building found");
    else {
      var building = buildings[0];
      console.log(building);
      building.thumb = 'http://oit.edu/images/default-source/campus-map/athletics/athletics.jpg?sfvrsn=2';
      //res.write(JSON.stringify(building));
      var html = Mustache.render("<html><body><div class='building'> {{name}}<p>{{description}}</div></body></html>" + "{{#contacts}}<p>contacts: </p><p>{{name}} Phone:{{phone}}, Email: {{email}} </p> {{/contacts}}<img src='{{thumb}}'>", building);
      res.write(html);
      res.end();
    }
  });
});
app.get('/lrc', function(req, res) {
  db.buildings.find({name: "Learning Resource Center"}, function(err, buildings) {
    if(err || !buildings) console.log("No building found");
    else {
      var building = buildings[0];
      console.log(building);
      building.thumb = 'http://oitweb1.oit.edu/Libraries/Campus_Map/LRC.sflb.ashx';
      //res.write(JSON.stringify(building));
      var html = Mustache.render("<html><body><div class='building'> {{name}}<p>{{description}}</div></body></html>" + "{{#contacts}}<p>contacts: </p><p>{{name}} Phone:{{phone}}, Email: {{email}} </p> {{/contacts}}<img src='{{thumb}}'>", building);
      res.write(html);
      res.end();
    }
  });
});
app.get('/semon', function(req, res) {
  db.buildings.find({name: "Semon Hall"}, function(err, buildings) {
    if(err || !buildings) console.log("No building found");
    else {
      var building = buildings[0];
      console.log(building);
      building.thumb = 'http://oitweb1.oit.edu/Libraries/Campus_Map/Semon.sflb.ashx';
      //res.write(JSON.stringify(building));
      var html = Mustache.render("<html><body><div class='building'> {{name}}<p>{{description}}</div></body></html>" + "{{#contacts}}<p>contacts: </p><p>{{name}} Phone:{{phone}}, Email: {{email}} </p> {{/contacts}}<img src='{{thumb}}'>", building);
      res.write(html);
      res.end();
    }
  });
});
app.get('/owens', function(req, res) {
  db.buildings.find({name: "Owens Hall"}, function(err, buildings) {
    if(err || !buildings) console.log("No building found");
    else {
      var building = buildings[0];
      console.log(building);
      building.thumb = 'http://oitweb1.oit.edu/Libraries/Campus_Map/Owens.sflb.ashx';
      //res.write(JSON.stringify(building));
      var html = Mustache.render("<html><body><div class='building'> {{name}}<p>{{description}}</div></body></html>" + "{{#contacts}}<p>contacts: </p><p>{{name}} Phone:{{phone}}, Email: {{email}} </p> {{/contacts}}<img src='{{thumb}}'>", building);
      res.write(html);
      res.end();
    }
  });
});
app.get('/bovin', function(req, res) {
  db.buildings.find({name: "Bovin Hall"}, function(err, buildings) {
    if(err || !buildings) console.log("No building found");
    else {
      var building = buildings[0];
      console.log(building);
      building.thumb = 'http://oit.edu/images/default-source/campus-map/boivin/boivin.jpg?sfvrsn=2';
      //res.write(JSON.stringify(building));
      var html = Mustache.render("<html><body><div class='building'> {{name}}<p>{{description}}</div></body></html>" + "{{#contacts}}<p>contacts: </p><p>{{name}} Phone:{{phone}}, Email: {{email}} </p> {{/contacts}}<img src='{{thumb}}'>", building);
      res.write(html);
      res.end();
    }
  });
});
app.get('/moehl', function(req, res) {
  db.buildings.find({name: "Moehl Stadium"}, function(err, buildings) {
    if(err || !buildings) console.log("No building found");
    else {
      var building = buildings[0];
      console.log(building);
      building.thumb = 'http://oitweb1.oit.edu/Libraries/Campus_Map/Moehl_Stadium.sflb.ashx';
      //res.write(JSON.stringify(building));
      var html = Mustache.render("<html><body><div class='building'> {{name}}<p>{{description}}</div></body></html>" + "{{#contacts}}<p>contacts: </p><p>{{name}} Phone:{{phone}}, Email: {{email}} </p> {{/contacts}}<img src='{{thumb}}'>", building);
      res.write(html);
      res.end();
    }
  });
});
app.get('/Facilities', function(req, res) {
  db.buildings.find({name: "Facilities Services"}, function(err, buildings) {
    if(err || !buildings) console.log("No building found");
    else {
      var building = buildings[0];
      console.log(building);
      building.thumb = 'http://oitweb1.oit.edu/Libraries/Campus_Map/Facilities_Services.sflb.ashx';
      //res.write(JSON.stringify(building));
      var html = Mustache.render("<html><body><div class='building'> {{name}}<p>{{description}}</div></body></html>" + "{{#contacts}}<p>contacts: </p><p>{{name}} Phone:{{phone}}, Email: {{email}} </p> {{/contacts}}<img src='{{thumb}}'>", building);
      res.write(html);
      res.end();
    }
  });
});
app.get('/health', function(req, res) {
  db.buildings.find({name: "Integrated Student Health Center"}, function(err, buildings) {
    if(err || !buildings) console.log("No building found");
    else {
      var building = buildings[0];
      console.log(building);
      building.thumb = 'http://oitweb1.oit.edu/Libraries/Campus_Map/ISHC.sflb.ashx';
      //res.write(JSON.stringify(building));
      var html = Mustache.render("<html><body><div class='building'> {{name}}<p>{{description}}</div></body></html>" + "{{#contacts}}<p>contacts: </p><p>{{name}} Phone:{{phone}}, Email: {{email}} </p> {{/contacts}}<img src='{{thumb}}'>", building);
      res.write(html);
      res.end();
    }
  });
});
app.get('/dow', function(req, res) {
  db.buildings.find({name: "Dow Center for Health Professions"}, function(err, buildings) {
    if(err || !buildings) console.log("No building found");
    else {
      var building = buildings[0];
      console.log(building);
      building.thumb = 'http://oit.edu/images/default-source/campus-map/dow/chp.jpg?sfvrsn=2';
      //res.write(JSON.stringify(building));
      var html = Mustache.render("<html><body><div class='building'> {{name}}<p>{{description}}</div></body></html>" + "{{#contacts}}<p>contacts: </p><p>{{name}} Phone:{{phone}}, Email: {{email}} </p> {{/contacts}}<img src='{{thumb}}'>", building);
      res.write(html);
      res.end();
    }
  });
});
app.get('/miller', function(req, res) {
  db.buildings.find({name: "Miller Hall"}, function(err, buildings) {
    if(err || !buildings) console.log("No building found");
    else {
      var building = buildings[0];
      console.log(building);
      //res.write(JSON.stringify(building));
      var html = Mustache.render("<html><body><div class='building'> {{name}}<p>{{description}}</div></body></html>" + "{{#contacts}}<p>contacts: </p><p>{{name}} Phone:{{phone}}, Email: {{email}} </p> {{/contacts}}", building);
      res.write(html);
      res.end();
    }
  });
});
app.get('/villageone', function(req, res) {
  db.buildings.find({name: "Sustainable Village 1"}, function(err, buildings) {
    if(err || !buildings) console.log("No building found");
    else {
      var building = buildings[0];
      console.log(building);
      building.thumb = 'http://oitweb1.oit.edu/Libraries/Campus_Map/Village1.sflb.ashx';
      //res.write(JSON.stringify(building));
      var html = Mustache.render("<html><body><div class='building'> {{name}}<p>{{description}}</div></body></html>" + "{{#contacts}}<p>contacts: </p><p>{{name}} Phone:{{phone}}, Email: {{email}} </p> {{/contacts}}<img src='{{thumb}}'>", building);
      res.write(html);
      res.end();
    }
  });
});
app.get('/villagetwo', function(req, res) {
  db.buildings.find({name: "Sustainable Village 2"}, function(err, buildings) {
    if(err || !buildings) console.log("No building found");
    else {
      var building = buildings[0];
      console.log(building);
      building.thumb = 'http://oitweb1.oit.edu/Libraries/Campus_Map/Village2.sflb.ashx';
      //res.write(JSON.stringify(building));
      var html = Mustache.render("<html><body><div class='building'> {{name}}<p>{{description}}</div></body></html>" + "{{#contacts}}<p>contacts: </p><p>{{name}} Phone:{{phone}}, Email: {{email}} </p> {{/contacts}}<img src='{{thumb}}'>", building);
      res.write(html);
      res.end();
    }
  });
});
app.get('/villagethree', function(req, res) {
  db.buildings.find({name: "Sustainable Village 3"}, function(err, buildings) {
    if(err || !buildings) console.log("No building found");
    else {
      var building = buildings[0];
      console.log(building);
      building.thumb = 'http://oitweb1.oit.edu/Libraries/Campus_Map/Village3.sflb.ashx';
      //res.write(JSON.stringify(building));
      var html = Mustache.render("<html><body><div class='building'> {{name}}<p>{{description}}</div></body></html>" + "{{#contacts}}<p>contacts: </p><p>{{name}} Phone:{{phone}}, Email: {{email}} </p> {{/contacts}}<img src='{{thumb}}'>", building);
      res.write(html);
      res.end();
    }
  });
});
app.listen(3000, '0.0.0.0');

console.log('Server running on port 3000');
