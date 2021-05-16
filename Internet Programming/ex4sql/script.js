function signin(){
    var pass="1234";
    var user="admin";
    var user_entered = document.getElementById("name").value;
    var pass_entered = document.getElementById("pass").value;
    if(pass==pass_entered && user==user_entered)
    {
        document.getElementById("form1").reset();
        window.alert("Welcome back Admin !\nRedirecting to homepage...");
        window.location.href="./dbcheck";
    }
    else
    {
      document.getElementById("form1").reset();
      window.alert("Invalid User Name or Password!");
      document.getElementById("name").focus();
    }
}
function add(){
  document.getElementById("add_form").action = "http://localhost:8080/ex4sql/adduser";
  document.getElementById("add_form").submit();
}
function view(){
  document.getElementById("view_form").action = "http://localhost:8080/ex4sql/viewuser";
  document.getElementById("view_form").submit();
}
function sh(){
  document.getElementById("search_form").action = "http://localhost:8080/ex4sql/searchuser";
  document.getElementById("search_form").submit();
}
function del(){
  document.getElementById("delete_form").action = "http://localhost:8080/ex4sql/deleteuser";
  document.getElementById("delete_form").submit();
}
function update(){
  document.getElementById("update_form").action = "http://localhost:8080/ex4sql/updateuser";
  document.getElementById("update_form").submit();
}