function get_details(branch) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
      myfunction(this,branch);
      }
    };
    xhttp.open("GET", "data.xml", true);
    xhttp.send();
  }
  function myfunction(xml,branch) {
    var i;
    var xmlDoc = xml.responseXML;
    var tab="<table><tr><th>State</th><th>district</th><th>branch</th><th>address</th><th>IFSC</th><th>MICR</th><th>code</th></tr>";
    var x = xmlDoc.getElementsByTagName("Branch");
    for (i = 0; i <x.length; i++) 
    {
        if(x[i].getElementsByTagName("branch")[0].childNodes[0].nodeValue==branch)
        {
            tab += "<tr><td>" +
            x[i].getElementsByTagName("state")[0].childNodes[0].nodeValue +
            "</td><td>" +
            x[i].getElementsByTagName("district")[0].childNodes[0].nodeValue +
            "</td><td>" +
            x[i].getElementsByTagName("branch")[0].childNodes[0].nodeValue +
            "</td><td>" +
            x[i].getElementsByTagName("address")[0].childNodes[0].nodeValue +
            "</td><td>" +
            x[i].getElementsByTagName("IFSC")[0].childNodes[0].nodeValue +
            "</td><td>" +
            x[i].getElementsByTagName("MICR")[0].childNodes[0].nodeValue +
            "</td><td>" +
            x[i].getElementsByTagName("code")[0].childNodes[0].nodeValue +
            "</td><tr>";
            break;
        }
    }
    tab+="</table>";
    document.getElementById("output").innerHTML = tab;
  }

  function disp() {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
          fil(this);
      }
    };
    xhttp.open("GET", "data.xml", true);
    xhttp.send();
  }
  function fil(xml) {
    var i;
    var xmlDoc = xml.responseXML;
    var tab="<table><tr><th>Branch</th><th>Details</th></tr>";
    var x = xmlDoc.getElementsByTagName("Branch");
    for (i = 0; i <x.length; i++) {
      tab += "<tr><td>"+x[i].getElementsByTagName("branch")[0].childNodes[0].nodeValue+"</td><td><button onclick='get_details(this.innerHTML)'>"+x[i].getElementsByTagName("branch")[0].childNodes[0].nodeValue+"</button></td></tr>";
    }
    tab+="</table>";
    document.getElementById("table").innerHTML = tab;
  }
