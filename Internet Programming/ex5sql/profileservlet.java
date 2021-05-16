import java.sql.*;
import java.io.*;
import jakarta.servlet.*;
import jakarta.servlet.http.*;

public class profileservlet extends HttpServlet {
    public void doGet(HttpServletRequest request,HttpServletResponse response) throws ServletException, IOException {
        
        response.setContentType("text/html");
        PrintWriter pw=response.getWriter();
        Connection con;
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
                    HttpSession session = request.getSession(false);
                    String srch = "SELECT * FROM users WHERE uname=\""+(String)session.getAttribute("uname")+"\";";
                    st = con.createStatement();
                    rs=st.executeQuery(srch);
                    if(rs.next()){
                        pw.println("<html><head><link rel=\"stylesheet\" href=\"style.css\"><link rel=\"stylesheet\" href=\"table_style.css\"><link href=\"https://fonts.googleapis.com/css?family=Ubuntu\" rel=\"stylesheet\">");
                        pw.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\" /> <link rel=\"stylesheet\" href=\"path/to/font-awesome/css/font-awesome.min.css\">");
                        pw.println("<title>Profile</title></head>");
                        pw.println("<br><br><br><br><br><body>");
                        pw.println("<p class=\"sign\" align=\"center\">Welcome "+(String)session.getAttribute("uname")+"</p>");
                        pw.println("<table>");
                        pw.println("<thead>");
                        pw.println("<tr><th>Name</th><th>Gender</th><th>Address</th><th>Marital status</th><th>Phone No</th></tr>");
                        pw.println("</thead>");
                        pw.println("<tbody>");
                        do{
                            pw.println("<tr><td>"+rs.getString(3)+"</td><td>"+rs.getString(4)+"</td><td>"+rs.getString(5)+"</td><td>"+rs.getString(6)+"</td><td>"+rs.getString(7)+"</td></tr>"); 
                        }while(rs.next());
                        pw.println("</tbody>");
                        pw.println("</table><br><br><br><div><a class=\"submit\" align=\"center\" onclick=\"logout();\" >Logout</a><script src=\"script.js\"></script></div></body></html>");
                    }
                    else
                    {
                        pw.println("<script>");
                        pw.println("alert(\"No data exist in main update\");");
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
                pw.println("<>");
                pw.println("alert(\"Failed to establish connection.Try again Later. Error Code :1 \");");
                pw.println("location='http://localhost:8080/ex4sql/index.html';");
                pw.println("</>");
            }     
        }
        catch(ClassNotFoundException e)
        {
            pw.println("<>");
            pw.println("alert(\"Driver class not found.Error Code :0 \");");
            pw.println("location='http://localhost:8080/ex4sql/index.html';");
            pw.println("</>");
        }
        pw.close();
    }

}