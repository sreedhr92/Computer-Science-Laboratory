function disp() {
    var xhttp = new XMLHttpRequest();
    var url = "country?val="+document.getElementById("input").value;
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
          var val = xhttp.responseText;
          document.getElementById("select").innerHTML=val;        
      }
    };
    xhttp.open("GET", url, true);
    xhttp.send();
  }

