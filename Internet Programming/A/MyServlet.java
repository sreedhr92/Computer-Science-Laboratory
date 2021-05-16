import java.io.*;
import jakarta.servlet.*;
import jakarta.servlet.http.*;
public class MyServlet extends HttpServlet {
public void doGet(HttpServletRequest request, HttpServletResponse response)
throws ServletException, IOException {
String name = request.getParameter("name");
response.setContentType("text/html");
String email = request.getParameter("email");
PrintWriter pw = response.getWriter();

pw.println("<table border =\"1\"width = \"50%\">");
pw.println("<tr><th>ID</th><th>Value</th></tr>");
pw.println("<tr><td>NAME</td><td>"+name+"</td></tr>");
pw.println("<tr><td>EMAIL</td><td>"+email+"</td></tr>");
pw.println("</table>");
pw.close();
}
}