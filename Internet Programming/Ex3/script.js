function startTime() {
    var today = new Date();
    var h = today.getHours();
    var m = today.getMinutes();
    var s = today.getSeconds();
    h = addzero(h);
    m = addzero(m);
    s = addzero(s);
    document.getElementById('txt').innerHTML =
    h + ":" + m + ":" + s;
    var t = setTimeout(startTime, 500);
  }
  function addzero(a)
  {
    if(a<10)
      return "0"+a;
    return a;
  }
  function myFunction() {
    document.getElementById("addr_rule").innerHTML = "Please enter a valid address!";
  }
  function remv() {
    document.getElementById("addr_rule").innerHTML = "";
  }
  function allowDrop(ev) {
    ev.preventDefault();
  }
  
  function drag(ev) {
    ev.dataTransfer.setData("text", ev.target.id);
  }
  
  function drop(ev) {
    ev.preventDefault();
    var data = ev.dataTransfer.getData("text");
    ev.target.appendChild(document.getElementById(data));
  }
  
  function drag_reset()
  {
    document.getElementById('div1').innerHTML+=document.getElementById('div2').innerHTML;
    document.getElementById('div2').innerHTML='';    
  }

  function display_table() {
  var name=document.getElementById("name").value;
  var addr=document.getElementById("address").value;
  var age=document.getElementById("age").value;
  var dob=document.getElementById("birthday").value;
  var ms=document.getElementById("mstat").value;
  var radios = document.getElementsByName('gender');
  var gender;
  for (var radio of radios) {
    if (radio.checked) {
      gender = radio.value;
    }
  }
  var contact=document.getElementById("num").value;
  var addiction=document.getElementById("div2").innerHTML; 
  document.writeln("<link rel=\"stylesheet\" href=\"style.css\">")

  for(var i=0;i<6;i++)
    document.writeln("<br>");
  document.writeln("<body>");
  document.writeln("<h1 style=\"text-align:center;\"><i>Form Details</i></h1>");
  document.writeln("<table border =\"1\"width = \"50%\">");
  document.writeln( "<tr><th>ID</th><th>Value</th></tr>");
  document.writeln("<tr><td>NAME</td><td>"+name+"</td></tr>");
  document.writeln("<tr><td>ADDRESS</td><td>"+addr+"</td></tr>");
  document.writeln("<tr><td>AGE</td><td>"+age+"</td></tr>");
  document.writeln("<tr><td>D.O.B</td><td>"+dob+"</td></tr>");
  document.writeln("<tr><td>Marital Status</td><td>"+ms+"</td></tr>");
  document.writeln("<tr><td>GENDER</td><td>"+gender+"</td></tr>");
  document.writeln("<tr><td>CONTACT</td><td>"+contact+"</td></tr>");
  document.writeln("<tr><td>ADDICTION </td><td>"+addiction+"</td></tr>");
  document.writeln( "</table></body>" );
  }
  function test()
  {
    document.writeln("<p>Hello world</p>");
  }
