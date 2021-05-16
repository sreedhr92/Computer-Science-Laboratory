import java.io.*;
import java.util.Date;
import jakarta.servlet.*;
import jakarta.servlet.http.*;
public class logoutservlet extends HttpServlet {
public void doGet(HttpServletRequest request, HttpServletResponse response)
throws ServletException, IOException {
    try{
        PrintWriter pw=response.getWriter();
        HttpSession session = request.getSession(false);
        session.invalidate();
        pw.println("<script>");
        pw.println("alert(\"Logged out Successfully\");");
        pw.println("location='http://localhost:8080/ex5sql/index.html';");
        pw.println("</script>");
    }
    catch(Exception e)
    {
        pw.println("<script>");
        pw.println("alert(\"Logged out Successfully\");");
        pw.println("location='http://localhost:8080/ex5sql/index.html';");
        pw.println("</script>");
        System.out.println(e);
    }
}
}