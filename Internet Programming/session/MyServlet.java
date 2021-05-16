import java.io.*;
import java.util.Date;
import jakarta.servlet.*;
import jakarta.servlet.http.*;
public class MyServlet extends HttpServlet {
public void doGet(HttpServletRequest request, HttpServletResponse response)
throws ServletException, IOException {
    try{
        String name = request.getParameter("name");
        response.setContentType("text/html");
        PrintWriter pw = response.getWriter();
        HttpSession session = request.getSession();
        session.setMaxInactiveInterval(20);
        pw.println("Session ID :"+session.getId());
        Date current = new Date(session.getCreationTime());
        pw.println("<br>Creation Time   :"+current);
        if(session.isNew())
        {
            Date last = new Date(session.getLastAccessedTime());
            pw.println("<br>Hello "+name+"!");
            pw.println("<br>Last Accessed time ="+last);
        }
        else
        {
            Date last = new Date(session.getLastAccessedTime());
            pw.println("<br>Hello "+name+" Welcome Back!");
            pw.println("<br>Last Accessed time ="+last);
        }
        pw.close();
    }
    catch(Exception e)
    {
        System.out.println(e);
    }
}
}