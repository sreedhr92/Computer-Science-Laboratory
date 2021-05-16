import java.io.*;
import jakarta.servlet.*;
import jakarta.servlet.http.*;
public class MyServlet extends HttpServlet {
public void doGet(HttpServletRequest request, HttpServletResponse response)
throws ServletException, IOException {
String id = request.getParameter("id");
String name = request.getParameter("name");
String desig = request.getParameter("desig");
String dept = request.getParameter("dept");
int salary = Integer.parseInt(request.getParameter("salary"));
String address = request.getParameter("address");
String dob = request.getParameter("birthday");
String gender = request.getParameter("gender");
String mstat = request.getParameter("mstat");
String num = request.getParameter("num");
PrintWriter pw = response.getWriter();
response.setContentType("text/html");
if(desig.equals("HR"))salary *=2;
else if(desig.equals("MGR"))salary *=1.7;
else salary*=1.2;
pw.println("<html><head><link href=\"style.css\" rel=\"stylesheet\" type=\"text/css\"/><head>");
pw.println("<br><br><br><br><br><body>");
pw.println("<h1 style=\"text-align:center;\"><i>Form Details</i></h1>");
pw.println("<table border =\"1\"width = \"50%\">");
pw.println("<tr><th>ID</th><th>Value</th></tr>");
pw.println("<tr><td>NAME</td><td>"+name+"</td></tr>");
pw.println("<tr><td>ADDRESS</td><td>"+address+"</td></tr>");
pw.println("<tr><td>EMP ID</td><td>"+id+"</td></tr>");
pw.println("<tr><td>D.O.B</td><td>"+dob+"</td></tr>");
pw.println("<tr><td>MARITAL STATUS</td><td>"+mstat+"</td></tr>");
pw.println("<tr><td>GENDER</td><td>"+gender+"</td></tr>");
pw.println("<tr><td>CONTACT</td><td>"+num+"</td></tr>");
pw.println("<tr><td>DESIGNATION </td><td>"+desig+"</td></tr>");
pw.println("<tr><td>DEPARTMENT </td><td>"+dept+"</td></tr>");
pw.println("<tr><td>GROSS PAY </td><td>"+salary+"</td></tr>");
pw.println("</table></body></head>");
pw.close();
}
}