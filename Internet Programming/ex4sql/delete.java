import java.sql.*;
import java.io.*;
import jakarta.servlet.*;
import jakarta.servlet.http.*;

public class delete extends HttpServlet {
    public void doGet(HttpServletRequest request,HttpServletResponse response) throws ServletException, IOException {
        
        response.setContentType("text/html");
        PrintWriter pw=response.getWriter();
        Connection con;
        Statement st;      
        PreparedStatement ps; 
        try
        {
            Class.forName("com.mysql.cj.jdbc.Driver");
            try
            {
                con = DriverManager.getConnection("jdbc:mysql://localhost:3306/patient_details","sree","sree");
                try
                {
                    int id = Integer.parseInt(request.getParameter("id"));
                    String srch = "DELETE FROM patients where id =?";
                    ps = con.prepareStatement(srch);
                    ps.setInt(1,id);
                    ps.execute();
            
                    pw.println("<script>");
                    pw.println("alert(\"Deleted \");");
                    pw.println("location='http://localhost:8080/ex4sql/view_user.html';");
                    pw.println("</script>");

                }
                  catch(SQLException e)
                {
                    pw.println("<script>");
                    pw.println("alert(\"Retrive the data"+e+" \");");
                    pw.println("location='http://localhost:8080/ex4sql/delete.html';");
                    pw.println("</script>");
                }
            }
            catch (SQLException e)
            {
                pw.println("<script>");
                pw.println("alert(\"Failed to establish connection.Try again Later. Error Code :1 \");");
                pw.println("location='http://localhost:8080/ex4sql/index.html';");
                pw.println("</script>");
            }     
        }
        catch(ClassNotFoundException e)
        {
            pw.println("<script>");
            pw.println("alert(\"Driver class not found.Error Code :0 \");");
            pw.println("location='http://localhost:8080/ex4sql/index.html';");
            pw.println("</script>");
        }
        pw.close();
    }

}