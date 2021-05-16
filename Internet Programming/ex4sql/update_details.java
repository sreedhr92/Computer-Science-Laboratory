import java.sql.*;
import java.io.*;
import jakarta.servlet.*;
import jakarta.servlet.http.*;

public class update_details extends HttpServlet {
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
                con =DriverManager.getConnection("jdbc:mysql://localhost:3306/patient_details","sree","sree");
                
                try
                {
                    int id = Integer.parseInt(request.getParameter("id"));
                    String phone = request.getParameter("num");
                    String address = request.getParameter("address");
                    String srch="update patients set phone_no=? ,address=? where id=?";
                    ps = con.prepareStatement(srch);
                    ps.setInt(3,id);
                    ps.setString(1,phone);
                    ps.setString(2,address);
                    ps.execute();            
                    pw.println("<script>");
                    pw.println("alert(\"Updated! \");");
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