import java.sql.*;
import java.io.*;
import jakarta.servlet.*;
import jakarta.servlet.http.*;

public class update extends HttpServlet {
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
                con =DriverManager.getConnection("jdbc:mysql://localhost:3306/patient_details","sree","sree");
                
                try
                {
                    String id = request.getParameter("id");
                    String srch = "SELECT * FROM patients where id ="+id+";";
                    st = con.createStatement();
                    rs=st.executeQuery(srch);
                    if(rs.next()){
                    pw.println("<html><head><link rel=\"stylesheet\" href=\"style.css\"><link href=\"https://fonts.googleapis.com/css?family=Ubuntu\" rel=\"stylesheet\">");
                    pw.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\" /> <link rel=\"stylesheet\" href=\"path/to/font-awesome/css/font-awesome.min.css\">");
                    pw.println("<script src=\"script.js\"></script><title>Update User</title></head><body><div class=\"main_home\"><p class=\"sign\" align=\"center\">Update User</p>");
                    pw.println("<form class=\"form2\" id=\"update\">");
                    pw.println("<input class=\"un\" id=\"name\" name =\"name\" type=\"text\" align=\"center\" placeholder=\"Name\" value=\""+rs.getString(2)+"\" readonly>");
                    pw.println("<input class=\"un\" id=\"age\" name=\"age\" type=\"text\" align=\"center\" placeholder=\"age\" value=\""+rs.getString(3)+"\"readonly>");
                    pw.println("<input class=\"un\" id=\"id\" name=\"id\" type=\"text\" align=\"center\" placeholder=\"id\" value=\""+rs.getString(1)+"\"readonly>");
                    pw.println("<input class=\"un\" id=\"gender\" name=\"gender\" type=\"text\" align=\"center\" placeholder=\"id\" value=\""+rs.getString(4)+"\"readonly>");
                    pw.println("<input class=\"un\" id=\"mstat\" name=\"mstat\" type=\"text\" align=\"center\" placeholder=\"id\" value=\""+rs.getString(6)+"\"readonly>");
                    pw.println("<input class=\"un\" id=\"date\" name=\"date\" type=\"text\" align=\"center\" placeholder=\"id\" value=\""+rs.getString(8)+"\"readonly>");
                    pw.println("<input class=\"un\" style=\"background-color: #3CBC8D;color: white;\" name=\"address\" id=\"address\" type=\"text\" align=\"center\" placeholder=\"address\" value=\""+rs.getString(5)+"\">");
                    pw.println("<input class=\"un\" style=\"background-color: #3CBC8D;color: white;\" name=\"num\" id=\"num\" type=\"text\" align=\"center\" placeholder=\"phone number\" value=\""+rs.getString(7)+"\">");
                    pw.println("<a class=\"submit\" align=\"center\" onclick=\"up();\" >Update User</a></form></div><script src=\"script.js\"></script></body></html>");
                    pw.println("<script>");
                    
                    
                    pw.println("function up(){document.getElementById(\"update\").action = \"http://localhost:8080/ex4sql/updatenew\";document.getElementById(\"update\").submit()}");
                    pw.println("</script>");
                    }
                    else
                    {
                        pw.println("<script>");
                        pw.println("alert(\"No data exist in main update\");");
                        pw.println("location='http://localhost:8080/ex4sql/view_user.html';");
                        pw.println("</script>");
                    }
                }
                 catch(SQLException e)
                {
                    pw.println("<script>");
                    pw.println("alert(\"Can't Retrive the data"+e+" \");");
                    pw.println("location='http://localhost:8080/ex4sql/view_user.html';");
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