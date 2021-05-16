function signin(){
  document.getElementById("login").action = "./login";
  document.getElementById("login").submit();
}
function view(){
  window.location.href='./profile';
}
function logout(){
  window.location.href='./logout';
}
//window.location.href='./dbcheck';