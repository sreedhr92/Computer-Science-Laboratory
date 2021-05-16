import java.sql.*;
import java.io.*;
import jakarta.servlet.*;
import jakarta.servlet.http.*;

public class loginservlet extends HttpServlet {
    public void doGet(HttpServletRequest request,HttpServletResponse response) throws ServletException, IOException {
        
        response.setContentType("text/html");
        PrintWriter pw=response.getWriter();
        Connection con;
        PreparedStatement ps;  
        Statement st;
        ResultSet rs;        
        try
        {
            Class.forName("com.mysql.cj.jdbc.Driver");
            try
            {
                con =DriverManager.getConnection("jdbc:mysql://localhost:3306/user","sree","sree");
                try
                {
                    String srch = "SELECT * FROM users WHERE uname=\""+(String)request.getParameter("name")+"\" and pass=\""+(String)request.getParameter("pass")+"\";";
                    st = con.createStatement();
                    rs=st.executeQuery(srch);
                    if(rs.next()){
                        pw.println("<script>");
                        pw.println("alert(\"Logged in Successfully\");");
                        pw.println("</script>");
                        HttpSession session = request.getSession(true);
                        session.setAttribute("uname",(String)request.getParameter("name"));
                        String user_name = rs.getString(3);
                        pw.println("<html><head><link rel=\"stylesheet\" href=\"style.css\"><link href=\"https://fonts.googleapis.com/css?family=Ubuntu\" rel=\"stylesheet\">");
                        pw.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\" /> <link rel=\"stylesheet\" href=\"path/to/font-awesome/css/font-awesome.min.css\">");
                        pw.println("<s src=\"script.js\"></s><title>Login</title></head><body><p class=\"sign\" align=\"center\">Welcome "+user_name+"</p>");
                        pw.println("<div><a class=\"submit\" align=\"center\" onclick=\"view();\" >View detail</a></div><script src=\"script.js\"></script></body></html>");
                    }
                    else
                    {
                        pw.println("<script>");
                        pw.println("alert(\"No data exists in that id \");");
                        pw.println("location='http://localhost:8080/ex5sql/index.html';");
                        pw.println("</script>");
                    }
                }
                  catch(SQLException e)
                {
                    pw.println("<script>");
                    pw.println("alert(\"Can't Retrive the data"+e+" \");");
                    pw.println("location='http://localhost:8080/ex5sql/index.html';");
                    pw.println("</script>");
                }
            }
            catch (SQLException e)
            {
                pw.println("<script>");
                pw.println("alert(\"Failed to establish connection.Try again Later. Error Code :1 \");");
                pw.println("location='http://localhost:8080/ex5sql/index.html';");
                pw.println("</script>");
            }     
        }
        catch(ClassNotFoundException e)
        {
            pw.println("<script>");
            pw.println("alert(\"Driver class not found.Error Code :0 \");");
            pw.println("location='http://localhost:8080/ex5sql/index.html';");
            pw.println("</script>");
        }
        pw.close();
    }

}